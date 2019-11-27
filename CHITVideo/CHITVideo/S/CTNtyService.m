//
//  CTNtyService.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/20.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CTNtyService.h"
//#import "VidyoControlTools.h"
#import "CTService.h"
//#import "CTConfVC.h"
#import "GNWSManager.h"
#import "CTLogService.h"
#import "CTWSService.h"
#import "CHITPrivateService.h"
#import "UIWindow+Category.h"

@implementation CTNtyService

+ (instancetype)sharedInstance {
    
    static CTNtyService *s = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        s = [[CTNtyService alloc]init];
    });
    return s;
}
- (instancetype)init {
    
    if (self = [super init]) {
        
        [self addNotification];
    }
    return self;
}
- (void)addNotification {
    
    //   进入、离开会议
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(confActive) name:ChitVideoNotificationConferenceActive object:nil];
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(confClear) name:ChitVideoNotificationConferenceCleared object:nil];
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(guestJoinFail:) name:ChitVideoNotificationGuestJoinFail object:nil];
//  日志收集
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(receiveLog:) name:ChitVideoNotificationReceiveLog object:nil];
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(receiveLocalLog:) name:GNLocalLogNotification object:nil];

    //  点击事件
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(touch:) name:ChitVideoNotificationTouch object:nil];
    //  app行为事件
//    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(didBecomeActive) name:UIApplicationDidBecomeActiveNotification object:nil];
//    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(willResignActive) name:UIApplicationWillResignActiveNotification object:nil];
//    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(willTerminate) name:UIApplicationWillTerminateNotification object:nil];
    
}
+ (void)addNotification {
    
     [self sharedInstance];
}
- (void)confActive {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        if (!CT_ConfStatus.confMode) {  // 没有收到 会议详情 关掉弹框
            
//            [SVProgressHUD dismiss];
        }

//        [[UIApplication sharedApplication]setIdleTimerDisabled:YES];
        [self shouldSpeaker];
        
        if (![CT_ConfStatus.confMode isEqualToString:CT_CONFMODE_LECTURE]) {

            [CHITVideoService showPreview:YES];
            [CHITVideoService setParticipantsLimit:4];
        }
    });
}
// 关闭其他应用音乐
- (void)shouldSpeaker{

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{

//        [[ChitVideo instance] muteSpeaker:NO];
    });
}

- (void)confClear {
    
    
    GNLog(@"confClear-当前会议已结束") ;

    dispatch_async(dispatch_get_main_queue(), ^{
        
        NSString *desc = @"你已离开会议" ;
        
//        [SVProgressHUD showInfoWithStatus:desc];
        [self endConference];
    });
}
- (void)guestJoinFail:(NSNotification *)nty {

    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        if (!CT_ConfStatus.didInterSDKBool) return ;
        
        NSDictionary *dic = nty.object;
        
        if ([CTHelper isValid:dic]) {
            
            NSInteger errorCode = [dic[@"error"] integerValue] ;
            [self handleWithErrorCode:errorCode];
        } else {
            
//            [SVProgressHUD showInfoWithStatus:@"入会失败，稍后再试"];
        }
        [self endConference];
    });
}
- (void)handleWithErrorCode:(NSInteger )errorCode {

    NSString *errorDesc ;
    switch (errorCode) {
        case 1017:
            
            errorDesc = @"会议已结束，加入会议室失败";
            break;
        case 1020:
            
            errorDesc = @"会议室已锁定，不能加入会议室";
            break;
        default:
            errorDesc = @"入会失败，稍后再试";
            break;
    }
//    [SVProgressHUD showInfoWithStatus:errorDesc];
}

- (void)endConference {
    
    @try {
        
//        [[UIApplication sharedApplication]setIdleTimerDisabled:NO];
        
        [CTWSService leaveConfSuccess:nil fail:nil];
//        [CTService uploadLogSuccess:nil fail:nil] ;

        [CTNtyService endConference];
    }
    @catch (NSException *exception) {
    
    }
}
+ (void)endConference {
    
    if (![CTHelper isInnerSDK]) [GNWSManager close];
    
    [CTConfManager dismissVC];
    CT_ConfStatus.isPVConf = NO ;
    CT_ConfStatus.isConfOwner = NO ;
    CT_ConfStatus.isUploadURIBool = NO ;
    CT_ConfStatus.whiteBoardSessionURL = nil ;
    [CHITPrivateService muteCamera:NO muteMicrophone:NO muteSpeaker:NO];

    [CHITVideoService stopVideo] ;
}

- (void)touch:(NSNotification *)nty {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        if ([[nty.userInfo objectForKey:@"state"] intValue] == 0) {
            
            if ([[nty.userInfo objectForKey:@"count"] intValue] == 1) {
                
//                [VidyoControlTools display];
            }
        }
    });
}
- (void)receiveLog:(NSNotification *)nty {
    
    [CTLogService receiveLog:nty.object];
}
- (void)receiveLocalLog:(NSNotification *)nty {
    
    [CTLogService receiveLocalLog:nty.object];
}

- (void)didBecomeActive {
    
    [CHITVideoService didBecomeActive];
}
- (void)willResignActive {
    
    [CHITVideoService willResignActive];
}
- (void)willTerminate {
    
    [CHITVideoService uninitialize];
}

@end
