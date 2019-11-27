//
//  ICHITPrivateService.m
//  ChitVieoManager
//
//  Created by user on 2018/9/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CHITPrivateService.h"
#import "CHITVideoService.h"
#import "CTHelper.h"
#import "CTConfCtrlService.h"
#import "CTConfManager.h"
#import "CTService.h"
#import "CTLogService.h"
#import "CTWSManager.h"
#import "UIAlertController+Category.h"
#import "CHITService.h"
#import "CHITBasicService.h"
#import "CTWSService.h"
//#import "VidyoControlTools.h"

#define CT_CONF_LINK  @"byshang.cn/#/roomDirect"


@implementation CHITPrivateService


#pragma mark - 二期修改、增加
+ (void)initializeManger {
    
    [CTConfManager manager];
    [CTWSManager shareInstance];
    [self muteCamera:NO muteMicrophone:NO muteSpeaker:NO];
    
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
    
    if (!login) {
        
        NSString *domain = [NSString stringWithFormat:@"%@:%@",cossUrl,cossPort];
        [CHITBasicService domain:domain];
    }
    
    [self roomNumber:roomNumber conferenceId:nil subject:nil userName:displayName invitedUsers:nil invitedTerminals:nil login:login];
    
}
+ (void)joinConferenceWithRoomId:(NSString *)roomId {
    
    [CTService joinConferenceWithRoomId:roomId success:^(id results) {
        GNLog(@"results is %@",results) ;
        [self handleWithConfDetail:results ];
        
    } fail:^(NSError *error) {
        
        if(error.code == 400 ) {
            
//            [SVProgressHUD showErrorWithStatus:@"会议号无效"];
        } else {
            
//            [SVProgressHUD showErrorWithStatus:error.localizedDescription];
        }
    }];
    
}

+ (BOOL)joinConferenceWithUrlInfo:(NSString *)urlInfo
                      displayName:(NSString *)displayName
                            login:(BOOL )login  {
    
    if(![urlInfo isKindOfClass:[NSString class]] || ![urlInfo containsString:CT_CONF_LINK])   return NO;
    
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
    
    [CTService joinConferenceWithGlobalConferenceIDSuccess:^(id results) {
        
         [self handleWithConfDetail:results ];
    } fail:^(NSError *error) {
//        [SVProgressHUD showErrorWithStatus:error.localizedDescription];

    }];
}

+ (void)saveConfData:(NSDictionary *)results {
    
    NSDictionary *room = results[@"room"] ;

    NSString *roomString = [CTHelper toJSONString:room] ;
    [GNDefault setObject:roomString key:CT_CONF_JSON];
    
}

+ (void)handleWithConfDetail:(NSDictionary *)results {
    
    GNLog(@"room is %@",results[@"room"]) ;
    GNLog(@"roomStatus is %@",results[@"roomStatus"]) ;
    
    
    CT_ConfStatus.detailModel = [CTConfDetailModel mj_objectWithKeyValues:results];
    RoomModel *room = CT_ConfStatus.detailModel.room ;
    RoomStatusModel *roomStatus = CT_ConfStatus.detailModel.roomStatus;
    
    BOOL nameJudgeBool = NO ;
    CT_ConfStatus.isCreateConf = NO ;
    if (CT_ConfStatus.isLogin) {
        NSString *displayName = [GNDefault objectForKey:CT_DISPLAYNAME];
        if (![displayName isEqualToString:room.ownerName]) {
            
            nameJudgeBool = YES ;
        } else {
            
            CT_ConfStatus.isCreateConf =  YES;
        }
    } else {
        nameJudgeBool = YES ;
    }
    
    if([CTHelper isValid:room.roomPIN] && room.roomPIN.length > 0 && nameJudgeBool ){

//        [SVProgressHUD dismiss];
//        [UIAlertController GNAlertTitle:@"请输入密码" mes:nil textfild:^(UITextField *textField) {
//
//        } cancel:^{
//
//            CT_ConfStatus.didInterSDKBool = NO ;
//            [CTWSService leaveConfSuccess:nil fail:nil];
//
//
//        } ensure:^(NSString *text) {
//            if ([text isEqualToString:room.roomPIN]) {
//
//                [SVProgressHUD show];
//                [self joinConferenceWithRoom:room ];
//            } else {
//
//                [self handleWithConfDetail:results ];
//                [SVProgressHUD showErrorWithStatus:@"密码验证失败"];
//            }
//        }];
        
    } else {
        
//        [SVProgressHUD show];
        [self joinConferenceWithRoom:room ];
    }
}

+ (void)cossUrl:(NSString *)cossUrl
       cossPort:(NSString *)cossPort
    displayName:(NSString *)displayName {
    
    
    NSString *domain = [NSString stringWithFormat:@"%@:%@",cossUrl,cossPort];
    [CHITBasicService domain:domain];
    [GNDefault setObject:displayName key:CT_DISPLAYNAME];
}
+ (void)wakeUp:(NSString *)weblink {
    
    if(![weblink isKindOfClass:[NSString class]] || ![weblink containsString:CT_CONF_LINK])   return ;
    
    [CTService addWakeOpenId:[CTHelper getOpenID:weblink] success:nil fail:nil];
}

#pragma mark  --  适配新平台join入口
+ (void)roomNumber:(NSString *)roomNumber
      conferenceId:(NSString *)conferenceId
           subject:(NSString *)subject
          userName:(NSString *)displayName
      invitedUsers:(NSArray *)invitedUsers
  invitedTerminals:(NSArray *)invitedTerminals
             login:(BOOL)login {
    
    
    if ([CTHelper isValid:roomNumber]) {
        
        if (![GNRegex isNumber:roomNumber]){
            
//            [SVProgressHUD showInfoWithStatus:@"会议号只能是数字"];
            return;
        }
    }
    
    if (CT_ConfStatus.didInterSDKBool) return;
    
    CT_ConfStatus.didInterSDKBool = YES;

    CT_ConfStatus.isLogin = login ;
    NSString *userId = [GNDefault objectForKey:CT_USERID] ;
    
    if (!login) {
        
        [GNDefault setObject:@"" key:CT_TOKEN];
        [GNDefault setObject:displayName key:CT_DISPLAYNAME];
        userId = @"" ;
    }
    
    [CTService createConf:roomNumber conferenceId:conferenceId subject:subject userName:displayName userId:userId invitedUsers:invitedUsers invitedTerminals:invitedTerminals success:^(id results) {
        
        GNLog(@"results is %@",results) ;
        
        if (![results[@"returnValue"] isEqualToString:@"OK"] ) {
            
            if ([results[@"returnValue"] isEqualToString:@"Locked"]){
                
//                [SVProgressHUD showInfoWithStatus:@"会议已被锁定"];
            }else if ([results[@"returnValue"] isEqualToString:@"RoomLocked"]){
                
//                [SVProgressHUD showInfoWithStatus:@"会议室已被锁定"];
            } else if ([results[@"returnValue"] isEqualToString:@"ConfNotFound"]){
                
//                [SVProgressHUD showInfoWithStatus:@"会议已结束"];
            }else if ([results[@"returnValue"] isEqualToString:@"ConfStartFailed"]){
                
//                [SVProgressHUD showInfoWithStatus:@"新建会议失败，请检查"];
            } else {
                
//                [SVProgressHUD showInfoWithStatus:@"获取会议信息失败，请稍后重试"];
            }
            CT_ConfStatus.didInterSDKBool = NO ;
            return  ;
        }
        
        if (!login) {
            [GNDefault setObject:results[CT_PARTICIPANTTOKEN] key:CT_TOKEN];
        }
        if (![CTHelper  isInnerSDK]) {
            
//            [GNDefault setObject:results[CT_UCCSURL] key:CT_WS_BASEURL];
        }
        
        [GNDefault setObject:results[@"conferenceId"] key:CT_GLOBAL_CONFERENCEID];
        [GNDefault setObject:results[@"participantId"] key:CT_PARTICIPANTID];
        
        [self getConferenceDetail];
        
    } fail:^(NSError *error) {
        
        CT_ConfStatus.didInterSDKBool = NO ;
//        [SVProgressHUD showErrorWithStatus:error.localizedDescription];
    }];
}

+ (void)getConferenceDetail {
    
    
    [CTService joinConferenceWithGlobalConferenceIDSuccess:^(id results) {

        [self handleWithConfDetail:results ];

        [self saveConfData:results];
    } fail:^(NSError *error) {
        
        CT_ConfStatus.didInterSDKBool = NO ;
//        [SVProgressHUD showErrorWithStatus:error.localizedDescription];
    }] ;
    
}



#pragma mark - 一期接口
+ (void)setUserInfoWithCossUrl:(NSString *)cossUrl
                      cossPort:(NSString *)cossPort
                        userId:(NSString *)userId
                     userToken:(NSString *)userToken
                   displayName:(NSString *)displayName {
    
    [GNDefault setObject:userToken key:CT_TOKEN];
    [GNDefault setObject:userId key:CT_USERID];
    [self cossUrl:cossUrl cossPort:cossPort  displayName:displayName];
    
}
+ (void)joinConferenceWithJSON:(id )JSON {
    
    NSDictionary *dic = [CTHelper toDic:JSON] ;
    
    if ([CTHelper isValid:dic]) {
        
        NSString *conferenceId = dic[@"conferenceId"];
        NSString *globalConferenceID = dic[@"globalConferenceID"];

        if (![CTHelper isValid:conferenceId ]) {
            
            conferenceId = globalConferenceID ;
        }
       
        if (![globalConferenceID isKindOfClass:[NSNull class]]) {
            
            if (globalConferenceID.length > conferenceId.length ){
                
                conferenceId = globalConferenceID ;
            }
        }
    [self roomNumber:nil conferenceId:conferenceId subject:nil userName:nil invitedUsers:nil invitedTerminals:nil login:YES] ;

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
    
    GNLog(@"confURL is %@",confURL) ;
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
    [CTConfManager presentVC];
    [CTConfManager startVideo];
//    [CTLogService LOG];
}

+ (void)joinConferenceWithRoom:(RoomModel * )room {
    
    if ([CTHelper isValid:room]) {
        
        NSString *displayName = [GNDefault objectForKey:CT_DISPLAYNAME] ;
        [self setConfig] ;
//        [VidyoControlTools displayAtFirst];

        if (![CTHelper isInnerSDK]) {
            
            [CTWSManager sendLink:^(id results) {
                
                if ([results isEqual:CT_SOCKET_LINK_SUCCESS]) {
                   
                    [CTWSService subscribeConferencSuccess:nil fail:nil];
                    [self joinConferenceWithRoomId:room.conferenceId roomURL:room.roomURL roomPIN:room.roomPIN conferenceId:room.globalConferenceID displayName:displayName ];
                } else {
                    
                    [[NSNotificationCenter defaultCenter] postNotificationName:ChitVideoNotificationGuestJoinFail object:nil];
                }
            }];
        } else {
            
            [CTWSService subscribeConferencSuccess:nil fail:nil];
            [self joinConferenceWithRoomId:room.conferenceId roomURL:room.roomURL roomPIN:room.roomPIN conferenceId:room.globalConferenceID displayName:displayName ];
            

        }
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
