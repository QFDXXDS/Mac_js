//
//  CTService.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/13.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CTService.h"
#import "CTReq.h"
#import "GNHTTPManager.h"
#import "GNDeviceInfo.h"
#import "ZipArchive.h"
#import "GNPath.h"
#import "CTLogService.h"
#import "CTWSReq.h"

#define PORTAL_PREFIX @"ws://"
#define PORTAL_SUFFIX @"/ue"

static  int tenentTryCount = 0 ;

@implementation CTService

+ (void)interConfCallFlag:(NSString *)callFlag
            participantID:(NSString *)participantID
           participantURI:(NSString *)participantURI
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail {

    
    CTInterConfReq *req = [[CTInterConfReq alloc]init];
    req.participantID = participantID ;
    req.callFlag = callFlag;
    req.participantURI = participantURI ;
    req.userTerminalType = [GNDeviceInfo userTerminalType];
    req.displayName = [GNDefault objectForKey:CT_DISPLAYNAME];
    
    [GNHTTPManager req:req success:^(id results) {
        
        success(nil);
        GNLog(@"++ 发送入会通知成功");
    } fail:^(NSError *error) {
        fail(nil);
        GNLog(@"++ 发送入会通知失败");
    }];
}

+ (void)leaveConfSuccess:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail {

    CTLeaveConfReq *req = [[CTLeaveConfReq alloc]init];
    req.userTerminalType = [GNDeviceInfo userTerminalType];

    [GNHTTPManager req:req success:^(id results) {
        
        GNLog(@"++ 发送离会通知成功");

    } fail:^(NSError *error) {
        
        GNLog(@"++ 发送离会通知失败");

    }];
}

+ (void)handupWithAction:(NSString *)action
                 success:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail {

//    CTHandupReq *req = [[CTHandupReq alloc]init];
//    req.action = action;
//    req.userTerminalType = [GNDeviceInfo userTerminalType];
//
//    [GNHTTPManager req:req success:^(id results) {
//
//        success(results);
//    } fail:^(NSError *error) {
//        fail(error);
//    }];
    
    CHITRaiseHandRequest *req = [[CHITRaiseHandRequest alloc]init] ;
    req.conferenceId = nil ;
    req.participantId = nil ;
    CHITLowerHandRequest *lowerReq = nil ;
    if ([action isEqualToString:@"up"]) {

    } else {
        
        lowerReq = (CHITLowerHandRequest *)req ;
    }
    [GNWSManager sendReq:req success:success fail:fail];

}

+ (void)getTenantSuccess:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail {
    
    CTGetTenantReq *req = [[CTGetTenantReq alloc]init];
    
    [GNHTTPManager req:req success:^(id results) {
        
        [self generateSocketURL:results];
        success? success(nil) : nil ;
        GNLog(@"++ 获取租户成功-%@",results);
        tenentTryCount = 0;
    } fail:^(NSError *error) {
        
        tenentTryCount ++ ;
        if (tenentTryCount < 3) {
            
            [self getTenantSuccess:nil fail:nil];
        } else {
            tenentTryCount = 0;
        }
        GNLog(@"++ 获取租户失败");
    }];
}

+ (void)uploadLogSuccess:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail {
    
    NSString *logFolder = [GNPath logFolder];
    NSArray *fileArray = [CTLogService fileArray];
    if (fileArray.count > 0) {

        NSString *zipPath = [GNPath zipPath];
        [SSZipArchive createZipFileAtPath:zipPath withContentsOfDirectory:logFolder];

        CTUploadLogReq *req = [[CTUploadLogReq alloc]init];
        [GNHTTPManager upload:req zapPath:zipPath success:^(id results) {

            [CTLogService removeFile];
        } fail:^(NSError *error) {

        }];
    }
}
+ (void)createAnonymousUserWithDisplayname:displayname
                                   success:(GNSuccessBlock)success
                                      fail:(GNFailBlock)fail {

    CTAnonymousUserReq *req = [[CTAnonymousUserReq alloc]init];
    req.displayname = displayname;
    [GNHTTPManager req:req success:^(id results) {
        
        [self generateSocketURL:results];
        
        NSString *userToken = results[@"token"] ;
        [GNDefault setObject:userToken key:CT_TOKEN];

        success(results);
        GNLog(@"创建匿名用户成功");
    } fail:^(NSError *error) {
        fail(error);
        GNLog(@"创建匿名用户失败");
    }];
}
+ (void)generateSocketURL:(NSDictionary *)results {
    
    NSDictionary *dic = results;
    NSString *IP = dic[@"userClientGatewayIp"];
    NSString *PORT = dic[@"userClientGatewayPort"];
    NSString *WSBaseURL = [NSString stringWithFormat:@"%@%@:%@%@",PORTAL_PREFIX,IP,PORT,PORTAL_SUFFIX];
    [GNDefault setObject:WSBaseURL key:CT_WS_BASEURL];
}
+ (void)joinConferenceWithRoomId:(NSString *)confIdOrRoomId
                         success:(GNSuccessBlock)success
                            fail:(GNFailBlock)fail {
    
    CTConfDetailReq1 *req = [[CTConfDetailReq1 alloc]init];
    req.confIdOrRoomId = confIdOrRoomId ;
    
    [GNHTTPManager req:req success:^(id results) {
        
        GNLog(@"获取会议详情成功");
        success(results);

    } fail:^(NSError *error) {
        GNLog(@"获取会议详情失败");
        fail(error);

    }];
}
+ (void)joinConferenceWithRoomNumber:(NSString *)roomNumber
                             success:(GNSuccessBlock)success
                                fail:(GNFailBlock)fail {
    
    CTConfDetailReq2 *req = [[CTConfDetailReq2 alloc]init];
    req.roomNumber = roomNumber ;
    
    [GNHTTPManager req:req success:^(id results) {
        
        GNLog(@"获取会议详情成功");
        success(results);
        
    } fail:^(NSError *error) {
        GNLog(@"获取会议详情失败");
        fail(error);
        
    }];
}

+ (void)addWakeOpenId:(NSString *)openId
              success:(GNSuccessBlock)success
                 fail:(GNFailBlock)fail {
    
    CTWakeReq *req = [[CTWakeReq alloc]init];
    req.openId = openId ;
    [GNHTTPManager req:req success:^(id results) {
        
        GNLog(@"上传openid成功");
    } fail:^(NSError *error) {
        GNLog(@"上传openid失败");

    }];
    
}

+ (void)getShareRoomInfoSuccess:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail {
    
    CTShareConferenceReq *req = [[CTShareConferenceReq alloc]init];
    req.globalConferenceID = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID] ;
    
    [GNHTTPManager req:req success:^(id results) {
        
        NSDictionary *dic = results ;
        NSString *shareURL = dic[@"shareURL"] ;
        NSArray *temp = [shareURL componentsSeparatedByString:@"/"] ;
        NSString *roomId = temp[temp.count - 2] ;

        [self getShareRoomInfoWithRoomId:roomId Success:success fail:fail];
        
    } fail:^(NSError *error) {
          fail(error);
    }];
}

+ (void)getShareRoomInfoWithRoomId:(NSString *)roomId
                           Success:(GNSuccessBlock)success
                              fail:(GNFailBlock)fail {

    CTShareRoomReq *req = [[CTShareRoomReq alloc]init];
    req.roomId = roomId ;
    
    [GNHTTPManager req:req success:^(id results) {
        
        [CTHelper shareInfo:results];
        success(results) ;
    } fail:^(NSError *error) {
        fail(error);
    }];

}
+ (void)joinConferenceWithGlobalConferenceIDSuccess:(GNSuccessBlock)success
                                               fail:(GNFailBlock)fail {
    
    CTConfDetailReq *req = [[CTConfDetailReq alloc]init];
    req.conferenceId = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID];
    
    [GNHTTPManager req:req success:^(id results) {
        
        GNLog(@"获取会议详情成功");
        success(results);
        
    } fail:^(NSError *error) {
        GNLog(@"获取会议详情失败");
        fail(error);
        
    }];
}


+ (void)createConf:(NSString *)confNumber
      conferenceId:(NSString *)conferenceId
           subject:(NSString *)subject
          userName:(NSString *)userName
            userId:(NSString *)userId
      invitedUsers:(NSArray *)invitedUsers
  invitedTerminals:(NSArray *)invitedTerminals
           success:(GNSuccessBlock)success
              fail:(GNFailBlock)fail {
    
    
    CHITConferenceJoinReq *req = [[CHITConferenceJoinReq alloc]init] ;
    req.confId = conferenceId ;
    req.confNumber = confNumber ;
    req.subject = subject ;
    req.userName = userName;
    req.clientType = @"ios" ;
    req.userId = userId;
    req.invitedUsers = invitedUsers ;
    req.invitedTerminals = invitedTerminals ;
    
    [GNHTTPManager req:req success:^(id results) {
        
        success(results);
    } fail:^(NSError *error) {
        
        fail(error);
    }];
}

@end
