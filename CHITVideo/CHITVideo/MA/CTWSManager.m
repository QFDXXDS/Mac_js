//
//  CTWSManager.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/5/11.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CTWSManager.h"
#import "CTWSService.h"
#import "CTConfCtrlService.h"
#import "CTService.h"
#import "GNWSManager.h"
#import "CHITService.h"


@interface CTWSManager ()

@property (nonatomic,copy)GNSuccessBlock  wsLinkSuccess;
@end

@implementation CTWSManager

+ (instancetype)shareInstance {
    
    static CTWSManager *ma= nil ;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
        ma = [[CTWSManager alloc]init];
    });
    return ma ;
}
- (instancetype)init {
    
    if (self = [super init]) {
        
        [GNWSManager shareInstance];
        [self addNotification];

    }
    return self ;
}
+ (void)sendLink:(GNSuccessBlock) success {
    
    [CTWSManager shareInstance].wsLinkSuccess = success;
    NSString * WSURLString = [GNDefault objectForKey:CT_WS_BASEURL];
    [GNWSManager sendLink:WSURLString];
}

- (void)addNotification {

    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(confInitial:) name:CTWSConfInitialNotification object:nil];
    
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(getConfDetail:) name:CTWSConfDetailNotification object:nil];
    

    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(WSLostLink) name:GNWSLostLinkNotification object:nil];
    

    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(WSLinkSuccess) name:GNWSLinkSuccessNotification object:nil];
    
}

- (void)confInitial:(NSNotification *)nty {
    
    BOOL videoMute = NO ;
    BOOL micMute = NO ;
    
    NSDictionary *dic = nty.object;
    if ([CTHelper isValid:dic]) {
        
        NSString *microphoneStatus = dic[@"microphoneStatus"] ;
        NSString *cameraStatus = dic[@"cameraStatus"] ;
        
        if (![microphoneStatus isEqualToString:@"on"]) {
            
            micMute = YES ;
        }
        if (![cameraStatus isEqualToString:@"on"]) {
            
            videoMute = YES ;
        }
    }
}
- (void)WSLinkSuccess {
    
    [CHITService AdmissionRequestSuccess:nil fail:nil ];
    
//    [CTWSService WSConfInitialSuccess:^(id results) {
//
//        NSDictionary *dic = results ;
//        [GNDefault setObject:dic[@"id"] key:CT_USER_ID];
//
//    } fail:^(NSError *error) {
//
//    }];
//    [CTWSService WSAppInfoSuccess:nil fail:nil];
//
//    if (CT_ConfStatus.didInterConfBool) {
//
        [CTConfCtrlService uploadURI];
//    }
    
    if ([CTWSManager shareInstance].wsLinkSuccess) {
        
        [CTWSManager shareInstance].wsLinkSuccess(CT_SOCKET_LINK_SUCCESS) ;
        [CTWSManager shareInstance].wsLinkSuccess = nil;
    }

}
- (void)getConfDetail:(NSNotification *)nty {

    
//    NSLog(@"[CHITVideoService  getCallState] is %d", [CHITVideoService  getCallState]) ;
    
    if ([CTHelper isValid:nty.object]) {
        
        NSDictionary *results = nty.object ;
        
        [CTConfCtrlService ConfDetail:results] ;
    }
}
- (void)WSLostLink {
    
//    if (CT_ConfStatus.isLogin) {
//
//        [CTService getTenantSuccess:^(id results) {
//
//            [CTWSManager sendLink];
//        } fail:nil];
//    }
    
    if ([CTWSManager shareInstance].wsLinkSuccess) {
        
        [CTWSManager shareInstance].wsLinkSuccess(CT_SOCKET_LINK_LOST) ;
        [CTWSManager shareInstance].wsLinkSuccess = nil;
    }
}

@end
