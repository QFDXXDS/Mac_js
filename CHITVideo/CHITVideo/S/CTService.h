//
//  CTService.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/13.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GNBlockConfig.h"

@interface CTService : NSObject

+ (void)interConfCallFlag:(NSString *)callFlag
            participantID:(NSString *)participantID
           participantURI:(NSString *)participantURI
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail ;

+ (void)leaveConfSuccess:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail ;

+ (void)handupWithAction:(NSString *)action
                 success:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail ;

+ (void)getTenantSuccess:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail ;

+ (void)uploadLogSuccess:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail ;

+ (void)createAnonymousUserWithDisplayname:displayname
                                   success:(GNSuccessBlock)success
                                      fail:(GNFailBlock)fail ;

+ (void)joinConferenceWithRoomId:(NSString *)roomId
                         success:(GNSuccessBlock)success
                            fail:(GNFailBlock)fail ;

+ (void)joinConferenceWithRoomNumber:(NSString *)roomNumber
                             success:(GNSuccessBlock)success
                                fail:(GNFailBlock)fail ;

+ (void)joinConferenceWithGlobalConferenceIDSuccess:(GNSuccessBlock)success
                                               fail:(GNFailBlock)fail ;

+ (void)addWakeOpenId:(NSString *)penId
              success:(GNSuccessBlock)success
                 fail:(GNFailBlock)fail ;

+ (void)getShareRoomInfoSuccess:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail ;

+ (void)getShareRoomInfoWithRoomId:(NSString *)roomId
                           Success:(GNSuccessBlock)success
                              fail:(GNFailBlock)fail ;


+ (void)createConf:(NSString *)confNumber
      conferenceId:(NSString *)conferenceId
           subject:(NSString *)subject
          userName:(NSString *)userName
            userId:(NSString *)userId
      invitedUsers:(NSArray *)invitedUsers
  invitedTerminals:(NSArray *)invitedTerminals
           success:(GNSuccessBlock)success
              fail:(GNFailBlock)fail ;
@end
