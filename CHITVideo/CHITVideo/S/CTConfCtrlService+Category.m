//
//  CTConfCtrlService+Category.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/7/9.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CTConfCtrlService+Category.h"

@implementation CTConfCtrlService (Category)

+ (void)confMode:(NSString *)mode {
    
    if ([CTHelper isValid:mode]) {
        
        if (![CT_ConfStatus.confMode isEqualToString:mode]) {
            
            if ([mode isEqualToString:CT_CONFMODE_LECTURE]) {
                
//                [SVProgressHUD showInfoWithStatus:@"演讲者模式"];
                if ([[CHITVideoService instance] isShareImage]) {
                    
                    [CHITVideoService stopShareImage];
                }
            }
            if ([mode isEqualToString:CT_CONFMODE_GROUP]) {
                
//                [SVProgressHUD showInfoWithStatus:@"普通模式"];
            }
            CT_ConfStatus.confMode = mode ;
            
            [[NSNotificationCenter defaultCenter] postNotificationName:CTConfCtrlDidHappenNotification object:nil];
            
        }
    }
}
+ (void)pinWithURI:(NSString *)participantURI limit:(int)limit mode:(BOOL)mode preview:(BOOL)show {
    
    if ([CTHelper isValid:participantURI] ) {

        [CHITVideoService showPreview:show];
        [CHITVideoService setParticipantsLimit:limit] ;
        [CHITVideoService pinParticipant:participantURI pin:mode] ;
    }
}

@end
