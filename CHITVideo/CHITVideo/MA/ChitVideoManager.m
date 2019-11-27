//
//  ChitVideoManager.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/10.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "ChitVideoManager.h"
#import "CTHelper.h"
#import "CTConfCtrlService.h"
#import "CTConfManager.h"
#import "CTService.h"
#import "CTLogService.h"
#import "CTWSManager.h"
#import "UIAlertController+Category.h"

#define CT_CONF_LINK  @"byshang.cn/#/roomDirect"
//#define URLINFO_LINK_TEST  @"http://imtest.byshang.cn/#/roomDirect"

@implementation ChitVideoManager

#pragma mark - 二期修改、增加

+ (void)initializeManger {
    
    [CTConfManager manager];
    [CTWSManager shareInstance];
    [self muteCamera:NO muteMicrophone:NO muteSpeaker:NO];
    
    [CHITVideoService leaveConference];
    
    [GNDefault setObject:@"http://120.133.9.13/jc-portal/" key:CT_HTTP_BASEURL];

    
}
+ (void)muteCamera:(BOOL )muteCamera
    muteMicrophone:(BOOL )muteMicrophone
       muteSpeaker:(BOOL ) muteSpeaker {
    
    NSArray *temp = @[@(muteCamera),@(muteMicrophone),@(muteSpeaker)];
    [GNDefault setObject:temp key:CT_CONF_MUTE];
    
}
+ (BOOL)joinConferenceWithWeblink:(NSString *)weblink
                      displayName:(NSString *)displayName
                            login:(BOOL )login {
    
    return [self joinConferenceWithUrlInfo:weblink displayName:displayName login:login] ;
}
+ (BOOL )joinConferenceWithQR:(NSString *)QR
                 displayName:(NSString *)displayName
                       login:(BOOL )login {
    
   return [self joinConferenceWithUrlInfo:QR displayName:displayName login:login];

}
+ (void)joinConferenceWithRoomNumber:(NSString *)roomNumber
                             cossUrl:(NSString *)cossUrl
                            cossPort:(NSString *)cossPort
                         displayName:(NSString *)displayName
                               login:(BOOL )login {
    
    CT_ConfStatus.isLogin = login ;
    if (login) {
        
        [self joinConferenceWithRoomNumber:roomNumber ];
    } else {
        
        [self cossUrl:cossUrl cossPort:cossPort displayName:displayName];
        
        [CTService createAnonymousUserWithDisplayname:displayName success:^(id results) {
            
            [self joinConferenceWithRoomNumber:roomNumber ];
            
        } fail:^(NSError *error) {
            
//            [SVProgressHUD showErrorWithStatus:error.localizedDescription];
        }];
    }
    
}
+ (void)joinConferenceWithRoomId:(NSString *)roomId {
    
    CT_ConfStatus.isLogin = YES ;

    [CTService joinConferenceWithRoomId:roomId success:^(id results) {

        [self handleWithConfDetail:results ];
        
    } fail:^(NSError *error) {
    
//        [SVProgressHUD showErrorWithStatus:error.localizedDescription];
    }];

}

+ (BOOL)joinConferenceWithUrlInfo:(NSString *)urlInfo
                      displayName:(NSString *)displayName
                            login:(BOOL )login  {
//    http://imdev.byshang.cn/#/roomDirect/65316
    
    if(![urlInfo isKindOfClass:[NSString class]] || ![urlInfo containsString:CT_CONF_LINK])   return NO;
    
    CT_ConfStatus.isLogin = login ;
    NSString *confIdOrRoomId = [CTHelper anonymousInfoWithUrlInfo:urlInfo];
    if (login) {
        
        [self joinConferenceWithRoomId:confIdOrRoomId ];
    } else {
        
        NSString *domain = [CTHelper domainWithUrlInfo:urlInfo];
        [self cossUrl:domain cossPort:CT_ANONYMOUS_PORT  displayName:displayName];

        [CTService createAnonymousUserWithDisplayname:displayName success:^(id results) {
            
            [self joinConferenceWithRoomId:confIdOrRoomId ];
            
        } fail:^(NSError *error) {
            
//            [SVProgressHUD showErrorWithStatus:error.localizedDescription];
        }];
    }
    return YES;
}

+ (void)joinConferenceWithRoomNumber:(NSString *)roomNumber {

//    会议室号输入有误，请重新核查您的会议号
    NSString *errDesc = @"会议室号输入有误，请重新核查您的会议号" ;
    if(![GNRegex isNumber:roomNumber]) {
        
//        [SVProgressHUD showErrorWithStatus:errDesc];
        return ;
    }
    [CTService joinConferenceWithRoomNumber:roomNumber success:^(id results) {

        [self handleWithConfDetail:results ];
    } fail:^(NSError *error) {

//        [SVProgressHUD showErrorWithStatus:error.localizedDescription];
    }];

}
+ (void)handleWithConfDetail:(NSDictionary *)results {
    
    

    if (results.count == 0) {
        
//        [SVProgressHUD showInfoWithStatus:@"会议已结束!"];
        return ;
    }

    GNLog(@"results is %@",results);
    CT_ConfStatus.detailModel = [CTConfDetailModel mj_objectWithKeyValues:results];
    RoomModel *room = CT_ConfStatus.detailModel.room ;
    RoomStatusModel *roomStatus = CT_ConfStatus.detailModel.roomStatus ;
    
    if ([roomStatus.locking boolValue]) {
//        [SVProgressHUD showInfoWithStatus:@"入会失败，会议室已锁定!"];
        return ;
    }
//    GNLog(@"room.ownerId  is %@",room.ownerId );
//    GNLog(@"room.userId is %@",room.userId );

    CT_ConfStatus.isCreateConf = [room.ownerId isEqual:room.userId];

    if([room.hasPIN boolValue]  && ![room.ownerId isEqual:room.userId]){
        
//        [UIAlertController GNAlertTitle:@"请输入密码" mes:nil textfild:^(UITextField *textField) {
//
//        } cancel:^{
//
//        } ensure:^(NSString *text) {
//
//            if ([text isEqualToString:room.roomPIN]) {
//
//                [self joinConferenceWithRoom:room ];
//            } else {
//
//                [self handleWithConfDetail:results ];
//                [SVProgressHUD showErrorWithStatus:@"密码验证失败"];
//            }
//        }];
        
    } else {
        
        [self joinConferenceWithRoom:room ];
    }
}

+ (void)cossUrl:(NSString *)cossUrl
       cossPort:(NSString *)cossPort
    displayName:(NSString *)displayName {
    
    if (![cossUrl hasPrefix:@"http"]) {
        
        cossUrl = [NSString stringWithFormat:@"http://%@",cossUrl];
    }
    [GNDefault setObject:cossUrl key:CT_BASE_DOMAIN];
    [GNDefault setObject:[NSString stringWithFormat:@"%@:%@",cossUrl,cossPort] key:CT_HTTP_BASEURL];
    [GNDefault setObject:displayName key:CT_DISPLAYNAME];
}
+ (void)wakeUp:(NSString *)weblink {
    
    if(![weblink isKindOfClass:[NSString class]] || ![weblink containsString:CT_CONF_LINK])   return ;

    [CTService addWakeOpenId:[CTHelper getOpenID:weblink] success:nil fail:nil];
}

#pragma mark - 一期接口
+ (void)setUserInfoWithCossUrl:(NSString *)cossUrl
                      cossPort:(NSString *)cossPort
                     userToken:(NSString *)userToken
                   displayName:(NSString *)displayName {

    CT_ConfStatus.isLogin = YES ;
    [GNDefault setObject:userToken key:CT_TOKEN];
    [self cossUrl:cossUrl cossPort:cossPort  displayName:displayName];
    
    if(![CTHelper isInnerSDK]) [CTService getTenantSuccess:nil fail:nil];
}
+ (void)joinConferenceWithJSON:(id )JSON {

    
    NSDictionary *dic = [CTHelper toDic:JSON] ;
    
    if ([CTHelper isValid:dic]) {
        
        [GNDefault setObject:JSON key:CT_CONF_JSON];
        
        NSString *globalConferenceID = dic[@"globalConferenceID"];
        [GNDefault setObject:globalConferenceID key:CT_GLOBAL_CONFERENCEID];

        [CTService joinConferenceWithGlobalConferenceIDSuccess:^(id results) {
            
            [self handleWithConfDetail:results ];

        } fail:^(NSError *error) {
//            [SVProgressHUD showErrorWithStatus:error.localizedDescription];

        }] ;
    }
}
+ (void)joinConferenceWithRoomId:(NSString *)roomId
                         roomURL:(NSString *)roomURL
                         roomPIN:(NSString *)roomPIN
                    conferenceId:(NSString *)conferenceId
                     displayName:(NSString *)displayName {
    
    NSArray *resArray = [CTHelper confResWithRoomURL:roomURL];
    NSString *confURL = resArray[0];
    NSString *confKey = resArray[1];
    
    NSArray *temp = [GNDefault objectForKey:CT_CONF_MUTE];
    BOOL muteVideo = [temp[0] boolValue] ;
    BOOL muteMicrophone = [temp[1] boolValue] ;
    BOOL muteSpeaker = [temp[2] boolValue] ;
    
    [CHITVideoService joinConference:confURL roomKey:confKey userName:displayName andRoomPIN:roomPIN muteVideo:muteVideo muteMicrophone:muteMicrophone muteSpeaker:muteSpeaker];
 
}
+ (int)getConferenceState {
    
    return [CHITVideoService getCallState] || CT_ConfStatus.didInterSDKBool;
}
+ (BOOL)didAccessChitSDK {
    
    return CT_ConfStatus.didInterConfBool;
}
+ (void )setConfig {
    
    CT_ConfStatus.confMode = nil;  // 入会默认没有模式
//    [CTWSManager sendLink];
    [CTConfManager presentVC];
//    [CTConfManager vidyoInit];
    [CTLogService LOG];
}

+ (void)joinConferenceWithRoom:(RoomModel * )room {
    
    if (CT_ConfStatus.didInterSDKBool) return;
    
    CT_ConfStatus.didInterSDKBool = YES;

    if ([CTHelper isValid:room]) {
        
        NSString *displayName = [GNDefault objectForKey:CT_DISPLAYNAME] ;
    
        [GNDefault setObject:room.conferenceId key:CT_GLOBAL_CONFERENCEID];
        [GNDefault setObject:room.participantId key:CT_PARTICIPANTID] ;

        
        [self setConfig] ;
//        [self joinConferenceWithRoomId:room.conferenceId roomURL:room.roomURL roomPIN:room.roomPIN conferenceId:room.globalConferenceID displayName:displayName ];
    }
}

+ (void)getShareInfoWithRoomId:(NSString *)roomId {
    
    [CTService getShareRoomInfoWithRoomId:roomId Success:^(id results) {
    
//        [SVProgressHUD showSuccessWithStatus:@"会议信息已复制，请分享"];
    } fail:^(NSError *error) {
        
//        [SVProgressHUD showInfoWithStatus:error.localizedDescription];
    }];
}

@end
