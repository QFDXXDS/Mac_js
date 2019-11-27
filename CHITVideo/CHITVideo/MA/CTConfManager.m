//
//  CTConfManager.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/26.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CTConfManager.h"
#import "CTNtyService.h"
#import "GNDeviceInfo.h"
#import "CTConfCtrlService.h"
#import "GNAdaptive.h"
#import "UIWindow+Category.h"
//#import "VidyoControlTools.h"
//#import "CHITWhiteBoardVC.h"

#import "VidyoViewController.h"

static  CTConfManager *ma = nil;

@interface CTConfManager()

//@property (nonatomic,strong)CTConfVC *confVC ;

@property (nonatomic,strong)NSWindowController *wc;

@end

@implementation CTConfManager

//- (CTConfVC * )confVC  {
//
//    if (!_confVC) {
//
//        _confVC = [CTConfVC confVC];
//    }
//    return _confVC;
//}
+ (instancetype)shareInstance {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
        ma = [[CTConfManager alloc]init];
        [CTConfManager config];
    });
    return ma ;
}
+ (void)manager {
    
    [self shareInstance];
}
+ (void)config {
    
    [CTNtyService addNotification];
    [CTConfCtrlService addNotification];

//    [self vidyoInit];
    [self HUD];
}
+ (void)startVideo {
    
//    CTConfVC *vc = ma.confVC;
//
//    [CHITVideoService initialize:YES view:vc.contentView];
//
//    [CHITVideoService readFromAssets:[NSString stringWithFormat:@"%@/zh-Hans.vyf",[CTHelper bundle].bundlePath]];
//    [CHITVideoService enableMenuBar:NO];
//    [CHITVideoService enableRedBorder:NO];
//    [CHITVideoService showSelfViewLoopback:NO];
    
    
    
        [CHITVideoService initialize:YES view:ma.wc.contentViewController ];
    
//        [CHITVideoService readFromAssets:[NSString stringWithFormat:@"%@/zh-Hans.vyf",[CTHelper bundle].bundlePath]];
//        [CHITVideoService enableMenuBar:NO];
//        [CHITVideoService enableRedBorder:NO];
//        [CHITVideoService showSelfViewLoopback:NO];

    
//    [self vidyoInit];
}
+ (void)vidyoInit {
    
    if ([[GNDeviceInfo appBuddleId] isEqualToString:CT_JISHI_BUNDLE_ID]){
        
        [CHITVideoService enableBackground: [[GNDefault objectForKey:CT_BACKGROUNDMODE] boolValue] ] ;
        [CHITVideoService bestVideoQuality:[[GNDefault objectForKey:CT_QUANLITYMODE] boolValue]] ;
        [CHITVideoService enableForceProxy:[[GNDefault objectForKey:CT_PROXYMODE] boolValue]] ;
    }
}

+ (void)HUD {
    
#if ChitVideoDynamic

    [SVProgressHUD setDefaultStyle:SVProgressHUDStyleCustom];
    [SVProgressHUD setForegroundColor:[UIColor whiteColor]];
    [SVProgressHUD setBackgroundColor:[UIColor blackColor]];
    [SVProgressHUD setDefaultMaskType:SVProgressHUDMaskTypeClear];
    [SVProgressHUD setMaximumDismissTimeInterval:1.5];
#endif
}


//+ (CTConfVC *)confVC {
//
//    CTConfVC *VC = ma.confVC;
//
//    return VC;
//}

- (NSWindowController *)wc {
    
    if (!_wc) {
        
        _wc = [[NSStoryboard storyboardWithName:@"Main" bundle:[CTHelper bundle] ]instantiateControllerWithIdentifier:@"WindowController"] ;
        
    }
    return _wc ;
}

+ (void)presentVC {
    
//    UIViewController *VC = [self confVC];
//    UIViewController *rootVC = [UIWindow rootVC] ;
//
//    dispatch_async(dispatch_get_main_queue(), ^{
//
//        [rootVC presentViewController:VC animated:YES completion:^{
//
//            [SVProgressHUD showWithStatus:@"正在准备加入会议请稍后。。。"];
//        }];
//    });
    
    
    
    [ma.wc.window orderFront:nil];
    
}
+ (void)dismissVC {
    
    [ma removeVC];
}
- (void)removeVC {
    
//    if(_confVC){
//        
//        GNLog(@"移除会议controller") ;
//        CT_ConfStatus.didInterSDKBool = NO ;
//        [VidyoControlTools removeTools];
//        
//        if (_confVC.presentedViewController) {
//        
//             [_confVC dismissViewControllerAnimated:NO completion:nil];
//        }
//        [_confVC dismissViewControllerAnimated:YES completion:nil];
//        _confVC = nil;
//    }
}


@end
