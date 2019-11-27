//
//  GNAudio.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/24.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNAudio.h"
#import <AVFoundation/AVFoundation.h>

@implementation GNAudio


+ (BOOL)otherAudioPlaying {
    
    return YES ;
    
}
+ (void)audioAndVideoAuthor:(void (^)(void))complete {
    
//    AVAuthorizationStatus audioStatus = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeAudio] ;
//    AVAuthorizationStatus videoStatus = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo] ;

//    if (audioStatus == AVAuthorizationStatusNotDetermined || videoStatus == AVAuthorizationStatusNotDetermined) {
//
//        [AVCaptureDevice requestAccessForMediaType:AVMediaTypeAudio completionHandler:^(BOOL granted) {
//
//            complete();
//        }];
//        [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted) {

//            complete();
//        }];
//    } else {
//        complete();
//    }
}

@end
