//
//  CHITPrivateService.h
//  CHitVideo
//
//  Created by user on 2018/9/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CHITPrivateService : NSObject
/**
 SDK 初始化
 
 */
+ (void)initializeManger ;

/**
 通过第三方应用入会
 
 @param weblink 有效连接
 @param displayName 名称
 @param login 是否已登录
 */
+ (BOOL)joinConferenceWithWeblink:(NSString *)weblink
                      displayName:(NSString *)displayName
                            login:(BOOL )login ;

/**
 二维码入会
 
 @param QR 二维码扫描结果
 @param displayName 名称
 @param login 是否登录
 */
+ (BOOL)joinConferenceWithQR:(NSString *)QR
                 displayName:(NSString *)displayName
                       login:(BOOL )login ;

/**
 会议号入会
 
 @param roomNumber 会议号
 @param cossUrl cossUrl
 @param cossPort cossPort
 @param displayName displayName
 @param login 登录状态
 */
+ (void)joinConferenceWithRoomNumber:(NSString *)roomNumber
                             cossUrl:(NSString *)cossUrl
                            cossPort:(NSString *)cossPort
                         displayName:(NSString *)displayName
                               login:(BOOL )login ;

/**
 通过roomId入会
 
 @param roomId 会议室Id
 */

+ (void)joinConferenceWithRoomId:(NSString *)roomId ;


/**
 设置相机、麦克风、外放状态（每次入会前调用）
 
 @param muteCamera 相机状态
 @param muteMicrophone 麦克风状态
 @param muteSpeaker 外放状态
 */
+ (void)muteCamera:(BOOL )muteCamera
    muteMicrophone:(BOOL )muteMicrophone
       muteSpeaker:(BOOL ) muteSpeaker ;

/**
 唤醒后执行
 
 @param weblink 有效连接
 */
+ (void)wakeUp:(NSString *)weblink ;

/**
 设置用户信息
 
 @param cossUrl 域名
 @param cossPort 端口
 @param userToken 用户token
 @param displayName 用户名
 */
+ (void)setUserInfoWithCossUrl:(NSString *)cossUrl
                      cossPort:(NSString *)cossPort
                        userId:(NSString *)userId

                     userToken:(NSString *)userToken
                   displayName:(NSString *)displayName ;

/**
 加入会议，JSON可以为字符串或则字典
 必须包含字段
 globalConferenceID
 roomURL
 roomPIN
 conferenceId
 */
+ (void)joinConferenceWithJSON:(id )JSON ;

/**
 获取会议状态
 0 当前处于空闲状态
 1 当前处于来电邀请状态
 2 当前处于Call状态
 3 当前正在加入会议
 4 当前已在会议中
 5 当前正在离会中
 @return 会议状态码
 */

+ (int )getConferenceState;
/**
 判断是否进入ChitSDK
 
 @return 进入返回YES,没有进入返回NO
 */
+ (BOOL)didAccessChitSDK ;

+ (void)getShareInfoWithRoomId:(NSString *)roomId ;

/**
 适配新平台join入口


 @param roomNumber 会议号
 @param conferenceId 会议id
 @param subject 主题
 @param displayName 名字
 @param invitedUsers 用户数组
 @param invitedTerminals 终端数组
 @param login 是否登录
 */
+ (void)roomNumber:(NSString *)roomNumber
      conferenceId:(NSString *)conferenceId
           subject:(NSString *)subject
          userName:(NSString *)displayName
      invitedUsers:(NSArray *)invitedUsers
  invitedTerminals:(NSArray *)invitedTerminals
             login:(BOOL)login ;

@end
