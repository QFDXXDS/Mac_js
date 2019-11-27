//
//  GNAdaptive.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/4/10.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNAdaptive.h"
#import "GNDeviceInfo.h"

#define  X_STATUS_H 44
#define  X_BOTTOM_H 34


@implementation GNAdaptive

+ (CGFloat)minHeight {
    
//    CGRect statusRect = [[UIApplication sharedApplication] statusBarFrame];
    
    
    CGFloat H = 20.f ;
//    if ([self isX]) {
//        GNLog(@"GNDeviceInfo isX") ;
//
//
////        H = X_STATUS_H;
//
//    } else {
//        GNLog(@"GNDeviceInfo isNomal") ;
//        H = 0;
//    }
    
    if (H == 0) {
        
        H = 20.f ;
    }
    return   H;
;
}
+ (CGFloat)height  {
    
    CGFloat H = 0 ;
    if ([self isX]) {
        
//        H = CT_SCREEN_H - X_STATUS_H;
    } else {
        
//        H = CT_SCREEN_H;
    }
    return H;
}

+ (CGFloat)toolViewHeight {
    
    CGFloat H = 40 ;
    
//    UIInterfaceOrientation orient = [[UIApplication sharedApplication] statusBarOrientation] ;
//
//    if (orient == UIInterfaceOrientationPortrait && [self isX]) {
//
//        H += X_BOTTOM_H;
//    }
    return H ;
}
+ (CGFloat)toolViewMinWidth {
    
    CGFloat W = 0 ;
    
//    UIInterfaceOrientation orient = [[UIApplication sharedApplication] statusBarOrientation] ;
    
    if ([self isX] ) {
        
//        if ( orient == UIInterfaceOrientationLandscapeLeft) {
//
//            W += X_STATUS_H;
//        }
//        if ( orient == UIInterfaceOrientationLandscapeRight) {
//
//             W += X_BOTTOM_H;
//        }
    }
    return W;
}
+ (BOOL)isX {
    
//    CGRect statusRect = [[UIApplication sharedApplication] statusBarFrame];
    
//    CGFloat H = CT_SCREEN_H;
//    if(H > 736) {
//
//        return YES;
//    }else {
//
//        return NO ;
//    }
    
//    if (statusRect.size.height == 20) {
//
//        return NO ;
//    } else {
//
        return YES ;
//    }
    
    
}


@end
