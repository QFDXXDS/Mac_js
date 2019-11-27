//
//  CTWSService.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/2/5.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CTWSService.h"
#import "GNWSManager.h"
#import "CTWSReq.h"
#import "GNDeviceInfo.h"

@implementation CTWSService

+ (void)WSConfDetailSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail {

    CTWSConfDetailReq * req = [[CTWSConfDetailReq alloc] init];
    req.opt = CT_CONF_DETAIL;
    req.globalConferenceID = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID];

    [GNWSManager sendReq:req success:nil fail:nil];
}

+ (void)WSAppInfoSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail {

    CTWSAppInfoReq *req = [[CTWSAppInfoReq alloc]init];
    req.opt = CT_APP_INFO ;
    req.userTerminalType = [GNDeviceInfo userTerminalType];
    [GNWSManager sendReq:req success:nil fail:nil];
}

+ (void)WSParticipantUE:(NSString *)UE status:(NSString *)status success:(GNSuccessBlock)success fail:(GNFailBlock)fail {

//    CTWSHardwareStatusReq *req = [[CTWSHardwareStatusReq alloc]init];
//    req.opt = CT_CONF_HARDWARE_STATUS ;
//    req.globalConferenceID = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID];
//    req.participantUE = UE ;
//    req.participantUEStatus = status;
//
//    [GNWSManager sendReq:req success:nil fail:nil];
}

+ (void)WSConfInitialSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail {

    CTWSConfInitialReq *req = [[CTWSConfInitialReq alloc]init];
    req.opt = CT_CONF_INITIAL_STATUS;
    req.globalConferenceID = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID];
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
}

+ (void)WSLock:(NSString *)action success:(GNSuccessBlock)success fail:(GNFailBlock)fail {
    
    CTWSConfLockReq *req = [[CTWSConfLockReq alloc]init];
    req.globalConferenceID = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID];
    req.action = action ;
    req.opt = CT_CONF_LOCK ;
    
    [GNWSManager sendReq:req success:^(id results) {
        
        CT_ConfStatus.isLock = !CT_ConfStatus.isLock ;
        success(nil) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
}

+ (void)subscribeConferencSuccess:(GNSuccessBlock)success
                             fail:(GNFailBlock)fail {

    CHITSubscribeConferenceRequest *req = [[CHITSubscribeConferenceRequest alloc]init];
    req.conferenceId = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID] ;
    req.participantId = [GNDefault objectForKey:CT_PARTICIPANTID] ;

    [GNWSManager sendReq:req success:^(id results) {
        
        GNLog(@"SubscribeConferenceRequest 处理成功") ;
    } fail:^(NSError *error) {
        
        GNLog(@"SubscribeConferenceRequest 处理失败") ;
    }];

    
}
+ (void)interConfCallFlag:(NSString *)callFlag
             devicePartId:(NSString *)devicePartId
           participantURI:(NSString *)participantURI
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail {
    
    
    CHITParticipantJoinedNotifyRequest *req1 = [[CHITParticipantJoinedNotifyRequest alloc]init];
    req1.conferenceId = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID] ;
    req1.participantId = [GNDefault objectForKey:CT_PARTICIPANTID] ;
    req1.participantURI = participantURI ;
    req1.devicePartId = devicePartId ;
    [GNWSManager sendReq:req1 success:^(id results) {
        success(results);
    } fail:^(NSError *error) {
        
        fail(error);

    }];
}

+ (void)handupWithAction:(NSString *)action
                 success:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail {
    
    CHITRaiseHandRequest *req = [[CHITRaiseHandRequest alloc]init] ;
    req.conferenceId = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID] ;
    req.participantId = [GNDefault objectForKey:CT_PARTICIPANTID] ;
    
    CHITLowerHandRequest *lowerReq = [[CHITLowerHandRequest alloc]init] ;
    lowerReq.conferenceId = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID] ;
    lowerReq.participantId = [GNDefault objectForKey:CT_PARTICIPANTID] ;

    if ([action isEqualToString:@"up"]) {

        [GNWSManager sendReq:req success:success fail:fail];

    } else {

        [GNWSManager sendReq:lowerReq success:success fail:fail];
    }
}

+ (void)leaveConfSuccess:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail {
    
    CHITParticipantLeftNotifyRequest *req = [[CHITParticipantLeftNotifyRequest alloc]init];
    req.conferenceId = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID] ;
    req.participantId = [GNDefault objectForKey:CT_PARTICIPANTID] ;
    
    [GNWSManager sendReq:req success:success fail:fail];
}


+ (void)getParticipantsWithId:(NSString *)Id
                      success:(GNSuccessBlock)success
                         fail:(GNFailBlock)fail
{
    CHITGetParticipantsRequest *req = [[CHITGetParticipantsRequest alloc]init];
    req.conferenceId = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID] ;
    
    [GNWSManager sendReq:req success:^(id results)
    {
        NSDictionary *value = results ;
        NSArray *participants = value[@"participants"];

        NSDictionary *participant = [self getParticipantWithId:Id participants:participants];
        
        if (![CTHelper isValid:participants]) return ;

        GNLog(@"participants is %@",participant) ;

        success (participant) ;

    } fail:^(NSError *error) {
        
        fail(error) ;
    }];
}

+ (void)getConferenceSuccess:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail {
    
    
    CHITGetConferenceRequest *req = [[CHITGetConferenceRequest alloc]init];
    
    req.conferenceId = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID];
    
    [GNWSManager sendReq:req success:success fail:fail];
    
//    [GNHTTPManager req:req success:^(id results) {
//
//        GNLog(@"获取会议详情成功");
//        success(results);
//
//    } fail:^(NSError *error) {
//        GNLog(@"获取会议详情失败");
//        fail(error);
//
//    }];
    
}
+ (NSArray<NSNumber *> *)getSelfHardWareStateParticipants:(NSArray *)participants {
    
    BOOL muteVideo = NO ;
    BOOL muteMic = NO ;
    BOOL muteSpeaker = NO ;
    for (NSDictionary *participant in participants) {
        
        //      找到自己
        if([participant[@"participantId"] isEqualToString:[GNDefault objectForKey:  CT_PARTICIPANTID ]]) {
            
            if ([participant[@"videoIn"] isEqualToString:@"muted"]) {
                muteVideo = YES;
            }
            if ([participant[@"audioIn"] isEqualToString:@"muted"]) {
                muteMic = YES;
                
            }
            if ([participant[@"audioOut"] isEqualToString:@"muted"]) {
                muteSpeaker = YES;
                
            }
            
            break ;
        }
    }
    
    return @[@(muteVideo),@(muteMic),@(muteSpeaker)] ;
}

+ (NSDictionary *)getParticipantWithId:(NSString *)Id participants:(NSArray *)participants {
    
//    找到级联URI
    NSString *URI = nil ;
    for (NSDictionary *participant in participants) {

        if([participant[@"casadingType"] isEqualToString:@"vidyoGW"] && [participant[@"cascadingParticipant"] boolValue]) {
            CT_ConfStatus.isPVConf = YES ;
            URI = participant[@"participantURI"];
            break ;
        }
    }
//  找到设置对应演讲者，点名者的成员
    NSDictionary *lectureDic = nil;
    for (NSDictionary *participant in participants) {
        
        if ([participant[@"participantId"] isEqualToString:Id]) {
            
            lectureDic = participant ;
            break ;
        }
    }
    
    NSMutableDictionary *participantDic = [[NSMutableDictionary alloc]initWithDictionary:lectureDic] ;
//    如果URI为空，就将级联的URI赋值给他
    NSString *participantURI = participantDic[@"participantURI"] ;
    if (![CTHelper isValid:participantURI]) {
        
        participantDic[@"participantURI"] = URI ;
    }
    
    return participantDic ;
}

+ (NSArray<NSNumber *> * )getParticipantEffectivityCount:(NSArray *)participants {
    
    NSInteger total = 0 ;
    NSInteger online = 0 ;
    
    for (NSDictionary *participant in participants) {
        
//      [participant[@"casadingType"] isEqualToString:@"vidyoGW"] &&
//      1,满足下两个条件是级联端口（有URI），2、其他是宝利通终端
        if( [participant[@"cascadingParticipant"] boolValue]) {
            
        } else {
            
            total++ ;
            if ([participant[@"status"] isEqualToString:@"Connected"]) {

                online++ ;
            }
        }
    }
    
    return @[@(total),@(online)] ;
}


+ (void)participantMediaChangedNotify:(NSString *)mediaType
                                muted:(NSString *)muted
                            direction:(NSString *)direction
                              success:(GNSuccessBlock)success
                                 fail:(GNFailBlock)fail
{
    
    CHITParticipantMediaChangedNotifyRequest *req = [[CHITParticipantMediaChangedNotifyRequest alloc]init];
    req.conferenceId = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID] ;
    req.participantId = [GNDefault objectForKey:CT_PARTICIPANTID] ;
    req.mediaType = mediaType ;
    req.direction = direction ;
    req.muted = muted ;
    
    [GNWSManager sendReq:req success:^(id results)
     {
         
//         success (participant) ;
         
     } fail:^(NSError *error) {
         
//         fail(error) ;
     }];
}


+ (void)WhiteBoardStartedNotify:(NSString *)sessionURL
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail {
    
    
    CHITWhiteBoardStartedNotifyRequest *req = [[CHITWhiteBoardStartedNotifyRequest alloc]init];
    req.sessionURL = sessionURL ;
    req.conferenceId = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID] ;
    req.participantId = [GNDefault objectForKey:CT_PARTICIPANTID] ;

    [GNWSManager sendReq:req success:nil fail:nil];
}


+ (void)WhiteBoardStopdNotifySuccess:(GNSuccessBlock)success
                                fail:(GNFailBlock)fail {
    
    CHITWhiteBoardStoppedNotifyRequest *req = [[CHITWhiteBoardStoppedNotifyRequest alloc]init];
    
    [GNWSManager sendReq:req success:nil fail:nil];

}




@end
