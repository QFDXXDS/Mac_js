//
//  CHITConfService.h
//  CHitVideo
//
//  Created by user on 2018/9/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CHITConfService : NSObject
/**
 邀请用户入会
 
 @param conferenceid 会议id
 @param userIdArr    被邀请者id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)invateUserToConference:(NSString *)conferenceid
                     userIdArr:(NSArray *)userIdArr
                       success:(GNSuccessBlock)success
                          fail:(GNFailBlock)fail;

/**
 拒接入会邀请
 
 @param conferenceid 会议id
 @param uid          被邀请者id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)refuseToJoinConference:(NSString *)conferenceid
                        userId:(NSString *)uid
                       success:(GNSuccessBlock)success
                          fail:(GNFailBlock)fail;
/**
 加入会议室 （通知服务器）
 
 @param globalConferenceID  会议室id
 @param uid            用户id
 @param participantID  参会人id
 @param participantURI 参会人Uri
 
 @param callFlag       Called(被叫) / Caller(主叫)
 */
+(void)joinConference:(NSString *)globalConferenceID
               userId:(NSString *)uid
        participantId:(NSString *)participantID
       participantURI:(NSString *)participantURI
             callFlag:(NSString *)callFlag
              success:(GNSuccessBlock)success
                 fail:(GNFailBlock)fail;

/**
 离开会议（通知服务器）
 
 @param globalConferenceID 会议id
 @param uid          用户id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)leaveConference:(NSString *)globalConferenceID
                 userId:(NSString *)uid
                success:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail;

/**
 查询会议状态
 
 @param conferenceId 会议Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)getConferenceStatus:(NSString *)conferenceId
                    success:(GNSuccessBlock)success
                       fail:(GNFailBlock)fail ;
@end
