//
//  CTWSService.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/2/5.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GNBlockConfig.h"

@interface CTWSService : NSObject

/**
获取会议详情

 @param success <#success description#>
 @param fail <#fail description#>
 */
+ (void)WSConfDetailSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail ;

/**
 发送App设备类型

 @param success <#success description#>
 @param fail <#fail description#>
 */
+ (void)WSAppInfoSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail ;

/**
 发送硬件状态

 @param hardware 相机、麦克风
 @param status on、off、front、after
 @param success <#success description#>
 @param fail <#fail description#>
 */
+ (void)WSParticipantUE:(NSString *)UE
                 status:(NSString *)status
                success:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail ;

// 获取会议初始化状态
+ (void)WSConfInitialSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail ;


/**
 锁定、解锁会议

 @param action 锁定、解锁会议
 @param success <#success description#>
 @param fail <#fail description#>
 */
+ (void)WSLock:(NSString *)action success:(GNSuccessBlock)success fail:(GNFailBlock)fail ;


/**
 订阅会议

 @param success <#success description#>
 @param fail <#fail description#>
 */
+ (void)subscribeConferencSuccess:(GNSuccessBlock)success
                             fail:(GNFailBlock)fail ;

+ (void)interConfCallFlag:(NSString *)callFlag
             devicePartId:(NSString *)devicePartId
           participantURI:(NSString *)participantURI
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail ;

+ (void)handupWithAction:(NSString *)action
                 success:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail ;


+ (void)leaveConfSuccess:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail ;


+ (void)getParticipantsWithId:(NSString *)Id
                      success:(GNSuccessBlock)success
                         fail:(GNFailBlock)fail ;

+ (void)getConferenceSuccess:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail ;

+ (NSArray<NSNumber *> *)getSelfHardWareStateParticipants:(NSArray *)participants ;

+ (NSDictionary *)getParticipantWithId:(NSString *)Id participants:(NSArray *)participants ;

+ (NSArray<NSNumber *> *)getParticipantEffectivityCount:(NSArray *)participants ;

+ (void)participantMediaChangedNotify:(NSString *)mediaType
                                muted:(NSString *)muted
                            direction:(NSString *)direction
                              success:(GNSuccessBlock)success
                                 fail:(GNFailBlock)fail ;


+ (void)WhiteBoardStartedNotify:(NSString *)sessionURL
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail ;


+ (void)WhiteBoardStopdNotifySuccess:(GNSuccessBlock)success
                                fail:(GNFailBlock)fail ;


@end



