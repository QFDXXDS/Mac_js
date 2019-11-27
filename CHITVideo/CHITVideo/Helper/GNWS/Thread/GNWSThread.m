//
//  GNWSThread.m
//  CHITVideo  
//
//  Created by Xianxiangdaishu on 2018/11/22.
//  Copyright © 2018 changhongit. All rights reserved.
//

#import "GNWSThread.h"
#import "GNWSReq.h"
#import "GNWSManager.h"

@implementation GNWSThread

//- (NSTimer *)heartTimer {
//
//    if (!_heartTimer) {
//        _heartTimer = [NSTimer scheduledTimerWithTimeInterval:HEART_INTERVAL target:self selector:@selector(heartCheck) userInfo:nil repeats:YES];
//        [_heartTimer setFireDate:[NSDate distantFuture]];
//
//    }
//    return _heartTimer;
//}
//- (NSTimer *)connectTimer {
//
//    if (!_connectTimer) {
//        _connectTimer = [NSTimer scheduledTimerWithTimeInterval:RECONNECT_INTERVAL target:self selector:@selector(connectCheck) userInfo:nil repeats:YES];
//        [_connectTimer setFireDate:[NSDate distantFuture]];
//
//    }
//    return _connectTimer;
//}
//- (NSTimer *)responseTimer {
//
//    if (!_responseTimer) {
//        _responseTimer = [NSTimer scheduledTimerWithTimeInterval:RSP_CHECK_INTERVAL target:self selector:@selector(responseCheck) userInfo:nil repeats:YES];
//        [_responseTimer setFireDate:[NSDate distantFuture]];
//
//    }
//    return _responseTimer;
//}

//- (void)start {
//    
//    NSRunLoop *currentLoop = [NSRunLoop currentRunLoop];
//    [currentLoop addTimer:self.heartTimer forMode:NSRunLoopCommonModes];
//    [currentLoop addTimer:self.connectTimer forMode:NSRunLoopCommonModes];
//    [currentLoop addTimer:self.responseTimer forMode:NSRunLoopCommonModes];
//    [currentLoop run];
//}
//
//#pragma mark 定时检测(心跳、重连、响应)
//- (void)heartCheck {
//
//    CHITKeepAliveRequest *req = [[CHITKeepAliveRequest alloc]init];
//    
//    [GNWSManager sendReq:req success:nil fail:nil];
//}
//- (void)connectCheck {
//    
//    [GNWSManager sendLink:nil] ;
//    [GNWSReqManager clear] ;
//    GNLog(@"5秒重连++");
//    [self reconnectCount];
//}
////- (void)responseCheck {
////
////    if (!ma.WSObject.isConnect) return ;
////    [GNWSReqManager detectReqObject];
////}
////- (void)reconnectCount {
////
////    if (_reConnectCount == 0 || _reConnectCount%5 == 0) {
////
////        [[NSNotificationQueue defaultQueue] enqueueNotification:[NSNotification notificationWithName:GNWSLostLinkNotification object:nil] postingStyle:NSPostASAP];
////    }
////    _reConnectCount ++ ;
////}
////
//- (void)pause {
//    
//    [_heartTimer setFireDate:[NSDate distantFuture]];
//    [_connectTimer setFireDate:[NSDate distantFuture]];
//    [_responseTimer setFireDate:[NSDate distantFuture]];
//
//}
@end
