//
//  CHITConfService.m
//  CHitVideo
//
//  Created by user on 2018/9/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CHITConfService.h"
#import "CHITReq.h"
#import "GNWSManager.h"
#import "GNRegex.h"
#import "GNDeviceInfo.h"
#import "GNHTTPManager.h"
@implementation CHITConfService
+ (void)invateUserToConference:(NSString *)conferenceid
                     userIdArr:(NSArray *)userIdArr
                       success:(GNSuccessBlock)success
                          fail:(GNFailBlock)fail{
    
    ConferenceInvateReq * req = [[ConferenceInvateReq alloc] init];
//    req.opt          = CHIT_CON_INVATE;
    req.usersid      = userIdArr;
    req.conferenceId = conferenceid;
    
    //    [ChityoWebSocketManager sendReq:req complete:^(id results, NSError *error) {
    //
    //        error?fail(error):success(results);
    //    }];
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
}

+ (void)refuseToJoinConference:(NSString *)globalConferenceID
                        userId:(NSString *)uid
                       success:(GNSuccessBlock)success
                          fail:(GNFailBlock)fail{
    
//    ConferenceJoinReq * req = [[ConferenceJoinReq alloc] init];
//    req.opt          = CHIT_CON_REFUSE;
//    req.userid       = uid;
//    req.globalConferenceID = globalConferenceID;
//    req.userTerminalType = [GNDeviceInfo userTerminalType];
//
//    [GNWSManager sendReq:req success:^(id results) {
//
//        success(results) ;
//    } fail:^(NSError *error) {
//        fail(error) ;
//    }];
    
    
    
    
}
+ (void)leaveConference:(NSString *)globalConferenceID
                 userId:(NSString *)uid
                success:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail{
    
    ConferenceJoinReq * req = [[ConferenceJoinReq alloc] init];
//    req.opt          = CHIT_CON_LEAVE;
    req.userid       = uid;
    req.globalConferenceID = globalConferenceID;
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
    
}
+(void)joinConference:(NSString *)globalConferenceID
               userId:(NSString *)uid
        participantId:(NSString *)participantID
       participantURI:(NSString *)participantURI
             callFlag:(NSString *)callFlag
              success:(GNSuccessBlock)success
                 fail:(GNFailBlock)fail {
    
    ConferenceJoinReq * req = [[ConferenceJoinReq alloc] init];
//    req.opt           = CHIT_CON_ENTER;
    
    req.userid        = uid;
    req.globalConferenceID  = globalConferenceID;
    req.participantID = participantID;
    req.participantURI = participantURI;
    req.callFlag      = @"Caller";
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
    
}
+ (void)getConferenceStatus:(NSString *)globalConferenceID
                    success:(GNSuccessBlock)success
                       fail:(GNFailBlock)fail {
    
    
    ConferenceStatusReq * req = [[ConferenceStatusReq alloc] init];
//    req.opt = CHIT_CON_STATUS ;
    req.globalConferenceID = globalConferenceID;
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
}
@end
