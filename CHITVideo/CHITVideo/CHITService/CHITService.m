//
//  CHITService.m
//  CHitVideo
//
//  Created by user on 2018/9/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CHITService.h"
#import "CHITVideoService.h"
#import "CHITBasicService.h"
#import "CHITConfService.h"
#import "CHITPrivateService.h"
#import "CTWSReq.h"


static CHITService *_shareVideo = nil;
@implementation CHITService
+ (id)instance{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _shareVideo = [[CHITService alloc] init];
    });
    return _shareVideo;
}
+ (void)serviceAddress:(NSString *)address{
    [CHITBasicService serviceAddress:address];
}
+ (BOOL)initialize:(BOOL)log view:(NSView *)view{
    
    [VCConnectorPkg vcInitialize];

    if (view) {
      return [CHITVideoService initialize:log view:view];
    }else{
        [CHITPrivateService initializeManger];
    }
    return YES;
}

+ (void)uninitialize{
    [CHITVideoService uninitialize];
}

+ (BOOL)logLevel:(NSString *)log{
    return [CHITVideoService logLevel:log];
}
+ (BOOL)joinConferenceWithWeblink:(NSString *)weblink
                      displayName:(NSString *)displayName
                            login:(BOOL )login{
   return [CHITPrivateService joinConferenceWithWeblink:weblink displayName:displayName login:login];
}
+ (BOOL)joinConferenceWithQR:(NSString *)QR
                 displayName:(NSString *)displayName
                       login:(BOOL )login{
    return [CHITPrivateService joinConferenceWithQR:QR displayName:displayName login:login];
}
+ (int)joinConference:(NSString *)portalURL
              roomKey:(NSString *)roomKey
             userName:(NSString *)displayName
           andRoomPIN:(NSString *)pin
            muteVideo:(BOOL)muteVideo
       muteMicrophone:(BOOL)muteMicrophone
          muteSpeaker:(BOOL)muteSpeaker{
  return [CHITVideoService joinConference:portalURL roomKey:roomKey userName:displayName andRoomPIN:pin muteVideo:muteVideo muteMicrophone:muteMicrophone muteSpeaker:muteSpeaker];
}
+ (void)leaveConference:(NSString *)globalConferenceID userId:(NSString *)uid success:(GNSuccessBlock)success fail:(GNFailBlock)fail{
    if (globalConferenceID) {
        [CHITConfService leaveConference:globalConferenceID userId:uid success:success fail:fail];
    }else{
        [CHITVideoService leaveConference];
    }
}
+ (BOOL)leaveConference{
   return [CHITVideoService leaveConference];
}
+ (BOOL)switchCamera:(int)camera{
   return [CHITVideoService switchCamera:camera];
}

+ (void)conferenceMuteCamera:(BOOL)camera muteMicrophone:(BOOL)microphone muteSpeaker:(BOOL)speaker{
//    [CHITVideoService conferenceMuteCamera:camera muteMicrophone:microphone muteSpeaker:speaker];
    [CHITPrivateService muteCamera:camera muteMicrophone:microphone muteSpeaker:speaker];
}
+ (BOOL)muteCamera:(BOOL)mute{
   return [CHITVideoService muteCamera:mute];
}
+ (BOOL)muteMicrophone:(BOOL)mute{
   return [CHITVideoService muteMicrophone:mute];
}
+ (BOOL)muteSpeaker:(BOOL)mute{
   return [CHITVideoService muteSpeaker:mute];
}
+ (NSDictionary *)getCameraStatus{
   return [CHITVideoService getCameraStatus];
}
+ (NSDictionary *)getMicrophoneStatus{
   return [CHITVideoService getMicrophoneStatus];
}
+ (NSDictionary *)getSpeakerStatus{
   return [CHITVideoService getSpeakerStatus];
}
+ (BOOL)showParticipantName:(int)isShow{
   return [CHITVideoService showParticipantName:isShow];
}
+ (void)didBecomeActive{
    [CHITVideoService didBecomeActive];
}
+ (void)willResignActive{
    [CHITVideoService willResignActive];
}
+ (BOOL)enableBackground:(BOOL)enable{
   return [CHITVideoService enableBackground:enable];
}
+ (BOOL)enableMenuBar:(BOOL)enable{
   return [CHITVideoService enableMenuBar:enable];
}
+ (BOOL)enableRedBorder:(BOOL)enable{
    return [CHITVideoService enableRedBorder:enable];
}
+ (BOOL)showPreview:(BOOL)ishow{
    return [CHITVideoService showPreview:ishow];
}
+ (BOOL)showSelfViewLoopback:(BOOL)ishow{
    return [CHITVideoService showSelfViewLoopback:ishow];
}
+ (BOOL)resizeWithxPos:(int)xPos
                  yPos:(int)yPos
                 width:(int)width
                height:(int)height{
    return [CHITVideoService resizeWithxPos:xPos yPos:yPos width:width andHeight:height];
}
//+ (BOOL)setDeviceOrientation:(UIDeviceOrientation)duration{
//    return [CHITVideoService setDeviceOrientation:duration];
//}
//+ (BOOL)setInterfaceOrientation:(UIInterfaceOrientation)duration{
//    return [CHITVideoService setInterfaceOrientation:duration];
//}
+ (BOOL)setParticipantsLimit:(int)limit{
    return [CHITVideoService setParticipantsLimit:limit];
}
+ (void)pinParticipant:(NSString*)participantURI pin:(BOOL)pin{
    [CHITVideoService pinParticipant:participantURI pin:pin];
}
+ (int)getCallState{
   return [CHITVideoService getCallState];
}
+ (void)toggleVideoDock{
    [CHITVideoService toggleVideoDock];
}
+ (void)toggleApplicationDock{
    [CHITVideoService toggleApplicationDock];
}
+ (void)showApplicationDock:(BOOL)willShow{
    [CHITVideoService showApplicationDock:willShow];
}
+ (void)showParticipantDock:(BOOL)willShow{
    [CHITVideoService showParticipantDock:willShow];
}
+ (BOOL)isApplicationDockVisible{
   return [CHITVideoService isApplicationDockVisible];
}
+ (BOOL)isParticipantDockVisible{
    return [CHITVideoService isParticipantDockVisible];
}
+ (NSDictionary *)getVideoDockCount{
    return [CHITVideoService getVideoDockCount];
}
+ (NSArray *)getParticipants{
    return [CHITVideoService getParticipants];
}
+ (NSDictionary *)getMyConferenceInfo{
    return [CHITVideoService getMyConferenceInfo];
}
+ (id)getShareApplicationInfo{
    return [CHITVideoService getShareApplicationInfo];
}
+ (BOOL)setSelfDisplayName:(NSString *)displayname{
    return [CHITVideoService setSelfDisplayName:displayname];
}
+ (BOOL)setDisplayName:(NSString *)displayname uri:(NSString *)uri{
    return [CHITVideoService setDisplayName:displayname uri:uri];
}
//+ (void)startShareImage:(UIImage *)image{
//    [CHITVideoService startShareImage:image];
//}
+ (void)stopShareImage{
    [CHITVideoService stopShareImage];
}
+ (void)readFromAssets:(NSString *)fontPath{
    [CHITVideoService readFromAssets:fontPath];
}
+ (BOOL)bestVideoQuality:(BOOL)enable{
    return [CHITVideoService bestVideoQuality:enable];
}
+ (void)enableForceProxy:(BOOL)enable{
    [CHITVideoService enableForceProxy:enable];
}
+ (void)enableProxy:(NSString *)address port:(NSString *)port{
    [CHITVideoService enableProxy:address port:port];
}
+ (void)disableProxy{
    [CHITVideoService disableProxy];
}
- (BOOL)videoStart{
    return [[CHITVideoService instance] videoStart];
}
- (BOOL)isShareImage{
    return [[CHITVideoService instance] isShareImage];
}
+ (void)searchConatctWithStr:(NSString *)searchStr
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail {
    [CHITBasicService searchConatctWithStr:searchStr success:success fail:fail];
}

+ (void)reviseConatctWithAvatar:(NSString *)avatar
                           mail:(NSString *)mail
                         mobile:(NSString *)mobile
                           name:(NSString *)name
                      officeTel:(NSString *)officeTel
                         userid:(NSString *)userid
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail {
    [CHITBasicService reviseConatctWithAvatar:avatar mail:mail mobile:mobile name:name officeTel:officeTel userid:userid success:success fail:fail];
}
+ (void)searchConatctWithUserid:(NSString *)userid
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail {
    
    [CHITBasicService searchConatctWithUserid:userid success:success fail:fail];
}



+ (void)searchOrgWithOrg:(NSString *)org
//                tenantid:(NSString *)tenantid
                 success:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail {
    
    [CHITBasicService searchOrgWithOrg:org success:success fail:fail];
    
}

+ (void)addContactArray:(NSArray *)usersid
                success:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail {
    [CHITBasicService addContactArray:usersid success:success fail:fail];
}

+ (void)delContactArray:(NSArray *)usersid
                success:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail {
    [CHITBasicService delContactArray:usersid success:success fail:fail];
}

+ (void)searchContactSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail {
    [CHITBasicService searchContactSuccess:success fail:fail];
}
+ (void)confListWithUserId:(NSString *)userId
                   success:(GNSuccessBlock)success
                      fail:(GNFailBlock)fail {

    [CHITBasicService confListWithUserId:(NSString *)userId
                             success:(GNSuccessBlock)success
                                fail:(GNFailBlock)fail];
    
}
+ (void)conferenceHistoryListPage:(NSInteger)page
                         pageSize:(NSInteger)size
                           userId:(NSString *)userId
                          success:(GNSuccessBlock)success
                             fail:(GNFailBlock)fail{
    
    [CHITBasicService conferenceHistoryListPage:page pageSize:size userId:userId success:success fail:fail];
}
+ (void)templateListWithPage:(NSInteger)page
                    pageSize:(NSInteger)size
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail{
    
    [CHITBasicService templateListWithPage:page pageSize:size success:success fail:fail];
}

+ (void)delTemplateWithId:(NSString *)Id
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail{
    
    [CHITBasicService delTemplateWithId:Id success:success fail:fail];
}

+ (void)createTemplateWithId:(NSString *)globalConferenceID
                       title:(NSString *)title
                   userIdArr:(NSArray *)userIdArr
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail{
    
    [CHITBasicService createTemplateWithId:globalConferenceID title:title userIdArr:userIdArr success:success fail:fail];
}

+ (void)conferenceDetailWithId:(NSString *)globalConferenceID
                       success:(GNSuccessBlock)success
                          fail:(GNFailBlock)fail{
    
    
    [CHITBasicService conferenceDetailWithId:globalConferenceID success:success fail:fail];
    
}

+ (void)conferenceHistoryWithId:(NSString *)globalConferenceID
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail{
    [CHITBasicService conferenceHistoryWithId:globalConferenceID success:success fail:fail];
    
}
+ (void)removeTemplateWithId:(NSString *)globalConferenceID
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail{
    
    [CHITBasicService removeTemplateWithId:globalConferenceID success:success fail:fail];
}

+ (void)createConferenceWithTitle:(NSString *)title
                        userIdArr:(NSArray *)userIdArr
                          success:(GNSuccessBlock)success
                             fail:(GNFailBlock)fail{
    
    [CHITBasicService createConferenceWithTitle:title userIdArr:userIdArr success:success fail:fail];
}

+ (void)revisePWDWithOldPWD:(NSString *)oldPWD
                     newPWD:(NSString *)newPWD
                     userid:(NSString *)userid
                    success:(GNSuccessBlock)success
                       fail:(GNFailBlock)fail {
    
    [CHITBasicService revisePWDWithOldPWD:oldPWD newPWD:newPWD userid:userid success:success fail:fail];
}

+ (void)loginOutSuccess:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail {
    
    [CHITBasicService loginOutSuccess:success fail:fail];
}


+ (void)domain:(NSString *)domain {
    
    [CHITBasicService domain:domain];
}

+ (void)backgrandMode:(BOOL)backgrandMode quanlityMode:(BOOL)quanlityMode proxyMode:(BOOL)proxyMode {
    
    
    GNLog(@"setting is %d__%d__%d",backgrandMode,quanlityMode, proxyMode) ;
    [GNDefault setObject:@(backgrandMode) key:CT_BACKGROUNDMODE];
    [GNDefault setObject:@(quanlityMode) key:CT_QUANLITYMODE];
    [GNDefault setObject:@(proxyMode) key:CT_PROXYMODE];

}
+ (void)loginWithLoginName:(NSString *)loginName
                  password:(NSString *)password
                    tenant:(NSString *)tenant
                   success:(GNSuccessBlock)success
                      fail:(GNFailBlock)fail {
    
    [CHITBasicService loginWithLoginName:loginName password:password tenant:tenant success:success fail:fail];
    
}
+ (void)invateUserToConference:(NSString *)conferenceid userIdArr:(NSArray *)userIdArr success:(GNSuccessBlock)success fail:(GNFailBlock)fail{
    [CHITConfService invateUserToConference:conferenceid userIdArr:userIdArr success:success fail:fail];
}
+ (void)refuseToJoinConference:(NSString *)conferenceid userId:(NSString *)uid success:(GNSuccessBlock)success fail:(GNFailBlock)fail{
    [CHITConfService refuseToJoinConference:conferenceid userId:uid success:success fail:fail];
}
+ (void)joinConference:(NSString *)globalConferenceID userId:(NSString *)uid participantId:(NSString *)participantID participantURI:(NSString *)participantURI callFlag:(NSString *)callFlag success:(GNSuccessBlock)success fail:(GNFailBlock)fail{
    [CHITConfService joinConference:globalConferenceID userId:uid participantId:participantID participantURI:participantURI callFlag:callFlag success:success fail:fail];
}
+ (void)getConferenceStatus:(NSString *)conferenceId success:(GNSuccessBlock)success fail:(GNFailBlock)fail{
    [CHITConfService getConferenceStatus:conferenceId success:success fail:fail];
}
+ (void)joinConferenceWithRoomId:(NSString *)roomId{
    [CHITPrivateService joinConferenceWithRoomId:roomId];
}
+ (void)joinConferenceWithRoomNumber:(NSString *)roomNumber cossUrl:(NSString *)cossUrl cossPort:(NSString *)cossPort displayName:(NSString *)displayName login:(BOOL)login{
    [CHITPrivateService joinConferenceWithRoomNumber:roomNumber cossUrl:cossUrl cossPort:cossPort displayName:displayName login:login];
}
+ (void)wakeUp:(NSString *)weblink{
    [CHITPrivateService wakeUp:weblink];
}
+ (void)setUserInfoWithCossUrl:(NSString *)cossUrl
                      cossPort:(NSString *)cossPort
                        userId:(NSString *)userId
                     userToken:(NSString *)userToken
                   displayName:(NSString *)displayName{
    
    [CHITPrivateService setUserInfoWithCossUrl:cossUrl cossPort:cossPort userId:userId userToken:userToken displayName:displayName];
//    [CHITPrivateService setUserInfoWithCossUrl:cossUrl cossPort:cossPort userToken:userToken displayName:displayName];
    
    
}
+ (void)joinConferenceWithJSON:(id )JSON{
    [CHITPrivateService joinConferenceWithJSON:JSON];
}
+ (int )getConferenceState{
   return [CHITPrivateService getConferenceState];
}
+ (BOOL)didAccessChitSDK{
   return [CHITPrivateService didAccessChitSDK];
}
+ (void)getShareInfoWithRoomId:(NSString *)roomId {
    
    [CHITPrivateService getShareInfoWithRoomId:roomId] ;
}


+ (void)getRoomInfoWithUserId:(NSString *)userId
                      success:(GNSuccessBlock)success
                         fail:(GNFailBlock)fail {
    
    CHITRoomInfoReq *req = [[CHITRoomInfoReq alloc]init];
    req.userId = userId;
    
    [GNHTTPManager req:req success:^(id results) {
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];

}

+ (void)createConf:(NSString *)conference
             owner:(NSDictionary *)owner
             users:(NSArray *)users
           success:(GNSuccessBlock)success
              fail:(GNFailBlock)fail {


    CHITCreateConfReq *req = [[CHITCreateConfReq alloc]init] ;
    req.conference = conference ;
    req.groupId = @"创建会议" ;
    req.users = users;
    req.owner = owner ;
    [GNHTTPManager req:req success:^(id results) {
        
        success(results);
    } fail:^(NSError *error) {
        
        fail(error);
    }];

    
}
+ (void)roomNumber:(NSString *)roomNumber
      conferenceId:(NSString *)conferenceId
           subject:(NSString *)subject
          userName:(NSString *)displayName
      invitedUsers:(NSArray *)invitedUsers
  invitedTerminals:(NSArray *)invitedTerminals
             login:(BOOL)login  {
    
    [CHITPrivateService roomNumber:roomNumber conferenceId:conferenceId subject:subject userName:displayName invitedUsers:invitedUsers invitedTerminals:invitedTerminals login:login];
    
}


//+ (void)createConf:(NSString *)conference
//             onwer:(NSDictionary *)owner
//             users:(NSArray *)users
//           success:(GNSuccessBlock)success
//              fail:(GNFailBlock)fail {
//
//
//
//}
+ (void)getTerminalListWithDeviceType:(NSString *)deviceType
                              success:(GNSuccessBlock)success
                                 fail:(GNFailBlock)fail {
    
    CHITTerminalListReq *req = [[CHITTerminalListReq alloc]init] ;
    [GNHTTPManager req:req success:success fail:fail];

}
+ (void)getTerminalTypeSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail {

//    CHITTerminalTypeReq *req = [[CHITTerminalTypeReq alloc]init];
//
//    [GNHTTPManager req:req success:^(id results) {
//
//        NSArray *a = results[@"content"];
//        success(a);
//    } fail:^(NSError *error) {
//        fail(error);
//    }];
    
    CHITTerminalListReq *req = [[CHITTerminalListReq alloc]init] ;
    [GNHTTPManager req:req success:success fail:fail];

}
+ (void)confInvite:(NSString *)globalConferenceID
             users:(NSArray *)users
           success:(GNSuccessBlock)success
              fail:(GNFailBlock)fail {
    
//    CHITConfInviteReq *req = [[CHITConfInviteReq alloc]init] ;
//    req.globalConferenceID = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID] ;
//    req.users = users;
//    [GNHTTPManager req:req success:^(id results) {
//
//        success(results);
//    } fail:^(NSError *error) {
//
//        fail(error);
//    }];
    
    
    for (NSDictionary *dic in users) {
        
        CHITInviteParticipantRequest *req = [[CHITInviteParticipantRequest alloc]init];
        req.userId = dic[@"userId"];
        req.ipAddress = dic[@"ipAddress"];
        req.terminalId = dic[@"terminalId"];
        req.conferenceId = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID] ;
        
        [GNWSManager sendReq:req success:success fail:fail];
    }
}

+ (void)setRoomWithRoomId:(NSString *)roomId
                     lock:(BOOL)isLocked
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail {
    
    CTRoomSetReq *req = [[CTRoomSetReq alloc]init];
    req.roomId = roomId;
    req.locked = @(isLocked) ;
    
    [GNHTTPManager req:req success:^(id results) {
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
    
}
+ (void)setRoomWithRoomId:(NSString *)roomId
                  roomPIN:(NSString *)roomPIN
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail {
    
    BOOL hasPIN = NO ;
    CTRoomSetReq *req = [[CTRoomSetReq alloc]init];
    req.roomId = roomId;
    if (roomPIN.length > 0) {
        
        req.roomPIN = roomPIN ;
        hasPIN = YES;
    }
    req.hasPIN = @(hasPIN);
    [GNHTTPManager req:req success:^(id results) {
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
}

+ (void)WSLink:(NSString *)url {
    
    if (![CTHelper isValid:url]) {
        
        url = [GNDefault objectForKey:CT_WS_BASEURL];
    }
    [GNWSManager sendLink:url];
}

+ (void)WSClose {
    
    [GNWSManager close];
}


+ (void)AdmissionRequestSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail {
    

    [CHITBasicService AdmissionRequestSuccess:success fail:fail];
}


+ (void)getUserListPageNum:(NSInteger)pageNum pageSize:(NSInteger)pageSize success:(GNSuccessBlock)success fail:(GNFailBlock)fail {
    
    
    [CHITBasicService getUserListPageNum:(NSInteger)pageNum pageSize:(NSInteger)pageSize success:success fail:fail];
}

@end
