//
//  GNWSManager.m
//  GN-OC
//
//  Created by Xianxiangdaishu on 2018/1/15.
//  Copyright © 2018年 XXDS. All rights reserved.
//

#import "GNWSManager.h"
#import "GNWSObject.h"
#import "GNWSReqManager.h"
#import "GNWSReq.h"
#import "GNError.h"
#import "GNWSThread.h"

#define HEART_INTERVAL  20
#define RECONNECT_INTERVAL  3
#define RSP_CHECK_INTERVAL  1

static GNWSManager *ma = nil;

@interface GNWSManager()

@property (nonatomic,strong)GNWSObject *WSObject;

@property (nonatomic,copy)NSString *WSURLString;

@property (nonatomic,strong)NSTimer *heartTimer;   //心跳timer

@property (nonatomic,strong)NSTimer *connectTimer;   //检测连接timer

@property (nonatomic,strong)NSTimer *responseTimer;   //响应超时检查

@property (nonatomic,assign)BOOL isConnect;    //      连接成功

@property (nonatomic,assign)BOOL isLostConnect;    //   失去连接

@property (nonatomic,assign)NSInteger reConnectCount;  // 重连次数、暂定5次重新获取域名、端口

//@property (nonatomic,strong)GNWSThread *thread ;

@end

@implementation GNWSManager

//- (GNWSThread *)thread {
//
//    if (!_thread ) {
//
//        _thread = [[GNWSThread alloc]init];
//        [_thread start];
//    }
//    return  _thread ;
//}

- (NSTimer *)heartTimer {
    
    if (!_heartTimer) {
        _heartTimer = [NSTimer scheduledTimerWithTimeInterval:HEART_INTERVAL target:self selector:@selector(heartCheck) userInfo:nil repeats:YES];
        [_heartTimer setFireDate:[NSDate distantFuture]];
        
    }
    return _heartTimer;
}
- (NSTimer *)connectTimer {
    
    if (!_connectTimer) {
        _connectTimer = [NSTimer scheduledTimerWithTimeInterval:RECONNECT_INTERVAL target:self selector:@selector(connectCheck) userInfo:nil repeats:YES];
        [_connectTimer setFireDate:[NSDate distantFuture]];
        
    }
    return _connectTimer;
}
- (NSTimer *)responseTimer {

    if (!_responseTimer) {
        _responseTimer = [NSTimer scheduledTimerWithTimeInterval:RSP_CHECK_INTERVAL target:self selector:@selector(responseCheck) userInfo:nil repeats:YES];
        [_responseTimer setFireDate:[NSDate distantFuture]];

    }
    return _responseTimer;
}

+ (instancetype)shareInstance {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
        ma = [[GNWSManager alloc]init];
        [ma setConfig];
    });
    return ma ;
}
- (void)setConfig {
    
    [self performSelectorInBackground:@selector(setOtherThread) withObject:nil];
    [self setWSObject];
}
- (void)setOtherThread {
    
    NSRunLoop *currentLoop = [NSRunLoop currentRunLoop];
    [currentLoop addTimer:self.heartTimer forMode:NSRunLoopCommonModes];
    [currentLoop addTimer:self.connectTimer forMode:NSRunLoopCommonModes];
    [currentLoop addTimer:self.responseTimer forMode:NSRunLoopCommonModes];
    [currentLoop run];
}
- (void)setWSObject {
    
    _WSObject = [[GNWSObject alloc]init];
    
    CT_WEAKSELF;
    _WSObject.socketEventBlock = ^(SocketEvent event,BOOL excut){
        
        CT_STRONGSELF;
        switch (event) {
            case HeartCheckEvent:
            {
                if (excut == sSelf.isConnect) return ;
                sSelf.isConnect = excut ;
                
                if (excut) {
                    _reConnectCount = 0 ;
                    [sSelf.heartTimer setFireDate:[NSDate dateWithTimeIntervalSinceNow:HEART_INTERVAL]];
                    [sSelf.responseTimer setFireDate:[NSDate distantPast]];
                } else {
                
                    [sSelf.heartTimer setFireDate:[NSDate distantFuture]];
                    [sSelf.responseTimer setFireDate:[NSDate distantFuture]];
                }
            }
                break;
            case ReconnectEvent:
            {
                
                if (excut == sSelf.isLostConnect) return ;
                sSelf.isLostConnect = excut;
                
                if (excut) {
                    
                    [sSelf.connectTimer setFireDate:[NSDate distantPast]];
                } else {
                    [sSelf.connectTimer setFireDate:[NSDate distantFuture]];
                }
            }
                break;
                
            default:
                break;
        }
    };
}

#pragma mark 发送请求事件
+ (void)sendReq:(id <GNWSProtocol>)req success:(GNSuccessBlock )success fail:(GNFailBlock )fail{

    if (ma.WSObject.isConnect) {
        
        NSString *string = [CTHelper WSWrapperReq:req];
        [ma.WSObject WSSendString:string];
        GNLog(@"send is %@",string) ;
        [GNWSReqManager req:string success:(GNSuccessBlock )success fail:(GNFailBlock )fail];
    } else {

        fail ? fail([GNError WSLinkError]) : nil ;
    }
}
+ (void)sendLink:(NSString *)WSURLString {
    
    if (ma.WSObject.isConnect)  return ;
    ma.WSURLString = WSURLString ? WSURLString : ma.WSURLString ;
    if(WSURLString.length > 0)  [ma.WSObject WSConnectWithURLString:WSURLString];
}
+ (void)close {

    [ma.WSObject close];
    ma.isConnect = NO ;
    ma.isLostConnect = NO ;
    
    [ma.heartTimer setFireDate:[NSDate distantFuture]];
    [ma.connectTimer setFireDate:[NSDate distantFuture]];
    [ma.responseTimer setFireDate:[NSDate distantFuture]];
    
    [GNWSReqManager clear] ;
    ma.reConnectCount = 0 ;
}
#pragma mark 定时检测(心跳、重连、响应)
- (void)heartCheck {
//
//    GNWSHeartReq *req = [[GNWSHeartReq alloc]init];
//    req.opt = CT_HEART_CHECK;
//    if (CT_ConfStatus.didInterConfBool) {
//        req.status = @"busy";
//    }
//    req.id = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID];
    
    CHITKeepAliveRequest *req = [[CHITKeepAliveRequest alloc]init];
    
    [GNWSManager sendReq:req success:nil fail:nil];
}
- (void)connectCheck {
    
    [_WSObject WSConnectWithURLString:_WSURLString] ;
    [GNWSReqManager clear] ;
    GNLog(@"5秒重连++");
    [self reconnectCount];
}
- (void)responseCheck {
    
    if (!ma.WSObject.isConnect) return ;
    [GNWSReqManager detectReqObject];
}
- (void)reconnectCount {
    
    if (_reConnectCount == 0 || _reConnectCount%5 == 0) {
        
        [[NSNotificationQueue defaultQueue] enqueueNotification:[NSNotification notificationWithName:GNWSLostLinkNotification object:nil] postingStyle:NSPostASAP];
    }
    _reConnectCount ++ ;
}



@end
