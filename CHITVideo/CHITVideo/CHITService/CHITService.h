//
//  CHITService.h
//  CHitVideo
//
//  Created by user on 2018/9/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^GNSuccessBlock)(id results);

typedef void (^GNFailBlock)(NSError * error);

@interface CHITService : NSObject
//服务是否已经启动
@property (nonatomic,assign) BOOL videoStart;
//是否正在分享图片
@property (nonatomic,assign) BOOL isShareImage;

/**
 ============================================================================
 ============================================================================
 //------------------------------VideoService--------------------------------
 ============================================================================
 ============================================================================
 */
/**
 创建一个单例
 
 @return 类对象
 */
+ (id)instance;
/**
 是否需要log
 与#uninitialize()成对出现;
 初始化成功返回CHITVIDEO_LOGIC_STARTED通知
 @param log  是否需要日志
 @param view 是否需要父试图
 @return 调用方法是否成功
 */
+ (BOOL)initialize:(BOOL)log view:(NSView *)view;
/**
 释放CHITVIDEO资源
 */
+ (void)uninitialize;

/**
 日志规则设置
 
 @param log 日志规则
 @return 方法是否发送成功
 */
+ (BOOL)logLevel:(NSString *)log;
/**
 加入会议室
 
 若成功则收到CHITVIDEO_CONFERENCE_ACTIVE通知
 若失败则收到CHITVIDEO_JOIN_FAILED通知
 
 @param portalURL       potral地址
 @param roomKey         房间ID
 @param displayName     显示的名字
 @param pin             房间密码
 @param muteVideo       是否mute视频
 @param muteMicrophone  是否mute麦克风
 @param muteSpeaker     是否mute扬声器
 @return
 CHITVIDEO_CALL_STATE_IDLE = 0;  调用入会正常
 CHITVIDEO_CALL_STATE_RINGING = 1; 当前处于来电邀请状态
 CHITVIDEO_CALL_STATE_CALLING = 2; 当前处于Call状态
 CHITVIDEO_CALL_STATE_JOINING = 3; 当前正在加入会议
 CHITVIDEO_CALL_STATE_IN_CONFERENCE = 4; 当前已在会议中
 CHITVIDEO_CALL_STATE_DISCONNECTING = 5; 当前正在离会中
 CHITVIDEO_CALL_STATE_PORTAL = 6; 当前portal为空
 CHITVIDEO_CALL_STATE_ROOMKEY = 7; 当前roomKey为空
 CHITVIDEO_CALL_STATE_DISPLAYNAME = 8; 当前displayName为空
 CHITVIDEO_CALL_STATE_OTHER = 9;  服务没有开启
 @return 会议状态码
 */

+ (int)joinConference:(NSString *)portalURL
              roomKey:(NSString *)roomKey
             userName:(NSString *)displayName
           andRoomPIN:(NSString *)pin
            muteVideo:(BOOL)muteVideo
       muteMicrophone:(BOOL)muteMicrophone
          muteSpeaker:(BOOL)muteSpeaker;
/**
 挂断会议, YES表示请求退出会议成功，NO表示请求退出会议失败。
 
 当会议结束后会收到CHITVIDEO_CONFERENCE_CLEARED通知。
 
 @return 调用方法是否成功
 */
+ (BOOL)leaveConference;

/**
 摄像机切换,YES表示成功，NO表示失败
 参数0表示前置摄像头 1表示后置摄像头
 
 @param camera 摄像头
 @return 调用方法是否成功
 */
+ (BOOL)switchCamera:(int)camera;
/**
 静音麦克风，摄像头，扬声器（会前配置）
 
 @param camera 相机
 @param microphone 麦克风
 @param speaker 扬声器
 */
+ (void)conferenceMuteCamera:(BOOL)camera muteMicrophone:(BOOL)microphone muteSpeaker:(BOOL)speaker;
/**
 关闭/打开摄像头,YES表示成功，NO表示失败（会中）
 
 成功返回CHITVIDEO_MUTED_VIDEO通知
 
 @param mute 是否mute
 @return 调用方法是否成功
 */
+ (BOOL)muteCamera:(BOOL)mute;
/**
 关闭/打开麦克风,YES表示成功，NO表示失败（会中）
 
 成功返回CHITVIDEO_MUTED_AUDIO_IN通知
 
 @param mute 是否mute
 @return 调用方法是否成功
 */
+ (BOOL)muteMicrophone:(BOOL)mute;
/**
 关闭/打开听筒，YES表示成功，NO表示失败（会中）
 
 成功返回CHITVIDEO_MUTED_AUDIO_OUT通知
 
 @param mute 是否mute
 @return 调用方法是否成功
 */
+ (BOOL)muteSpeaker:(BOOL)mute;
/**
 获取摄像头的状态
 type:   0.表示视频muted，1.表示视频被服务器mute
 @return 返回参数
 */
+ (NSDictionary *)getCameraStatus;

/**
 获取麦克风的状态
 type:   0.表示麦克风muted，1.表示麦克风被服务器mute
 @return 返回参数
 */
+ (NSDictionary *)getMicrophoneStatus;

/**
 获取扬声器张状态
 type:  0.表示扬声器muted
 @return 返回参数
 */
+ (NSDictionary *)getSpeakerStatus;
/**
 是否显示参会人名称
 
 @param isShow 1显示，0不显示
 */
+ (BOOL)showParticipantName:(int)isShow;
/**
 应用程序进入applicationDidBecomeActive
 
 */
+ (void)didBecomeActive;

/**
 应用程序进入applicationWillResignActive
 
 */
+ (void)willResignActive;
/**
 是否需要在后台持续运行
 
 @param enable 是否
 @return 方法调用是否成功
 */
+ (BOOL)enableBackground:(BOOL)enable;

/**
 是否禁止原生的CHITVIDEO工具栏
 
 @param enable 默认为NO
 @return 方法调用是否成功
 */
+ (BOOL)enableMenuBar:(BOOL)enable;
/**
 是否显示视频红框
 
 @param enable 默认为YES
 @return 方法调用是否成功
 */
+ (BOOL)enableRedBorder:(BOOL)enable;
/**
 是否显示本地视频
 返回YES表示设置成功，返回NO表示设置失败
 传入YES表示显示本地视频，传入NO表示只显示远端视频，不显示本地视频
 
 @param ishow 是否显示本地视频
 @return 方法调用是否成功
 */
+ (BOOL)showPreview:(BOOL)ishow;
/**
 是否显示自视
 返回YES表示设置成功，返回NO表示设置失败
 传入YES表示显示自视，传入NO表示不显示自视
 enabling self video only when there are no other participant in conference.
 @param ishow 是否显示自视
 @return 方法调用是否成功
 */
+ (BOOL)showSelfViewLoopback:(BOOL)ishow;

/**
 调整视频窗口的大小和位置(请在主线程调用该方法)
 返回YES表示设置成功，返回NO表示设置失败
 
 成功返回CHITVIDEO_RESIZE通知
 
 @param xPos x轴位置
 @param yPos y轴位置
 @param width 视频宽度
 @param height 视频高度
 @return 方法调用是否成功
 */
+ (BOOL)resizeWithxPos:(int)xPos
                  yPos:(int)yPos
                 width:(int)width
                height:(int)height;

/**
 调整视频横竖屏
 UIDeviceOrientationPortrait 竖屏状态（home键在下面）
 UIDeviceOrientationPortraitUpsideDown  竖屏状态（home键在上面）
 UIDeviceOrientationLandscapeRight  横屏状态（home键在左边）
 UIDeviceOrientationLandscapeLeft  横屏状态（home键在右边）
 UIDeviceOrientationFaceUp  屏幕朝上
 UIDeviceOrientationFaceDown  屏幕朝下
 
 @param duration 当前设备的方向
 @return 方法调用是否成功
 */
//+ (BOOL)setDeviceOrientation:(UIDeviceOrientation)duration;
//+ (BOOL)setInterfaceOrientation:(UIInterfaceOrientation)duration;
/**
 设置显示人数
 
 @param limit 显示人数
 */
+ (BOOL)setParticipantsLimit:(int)limit;
/**
 PINHIGH / PINDOCK
 
 @param participantURI 参会人uri
 @param pin yes表示PINHIGH
 */
+ (void)pinParticipant:(NSString*)participantURI pin:(BOOL)pin;
/**
 获取会议状态
 
 CHITVIDEO_CALL_STATE_IDLE = 0;  当前处于空闲状态
 CHITVIDEO_CALL_STATE_RINGING = 1; 当前处于来电邀请状态
 CHITVIDEO_CALL_STATE_CALLING = 2; 当前处于Call状态
 CHITVIDEO_CALL_STATE_JOINING = 3; 当前正在加入会议
 CHITVIDEO_CALL_STATE_IN_CONFERENCE = 4; 当前已在会议中
 CHITVIDEO_CALL_STATE_DISCONNECTING = 5; 当前正在离会中
 
 @return 会议状态码
 */
+ (int)getCallState;
/**
 显示或隐藏被隐藏的参会人员
 */
+ (void)toggleVideoDock;

/**
 显示或隐藏被隐藏的共享屏幕
 */
+ (void)toggleApplicationDock;

/**
 是否显示被隐藏的共享屏幕
 
 @param willShow YES显示，NO隐藏
 */
+ (void)showApplicationDock:(BOOL)willShow;
/**
 是否显示被隐藏的参会人
 
 @param willShow YES显示，NO隐藏
 */
+ (void)showParticipantDock:(BOOL)willShow;
/**
 被隐藏的共享屏幕是否可见
 
 @return NO 不可见， YES 可见
 */
+ (BOOL)isApplicationDockVisible;
/**
 被隐藏的参会人是否可见
 
 @return NO 不可见， YES 可见
 */
+ (BOOL)isParticipantDockVisible;

/**
 获取参会人员和屏幕共享的数量
 */
+ (NSDictionary *)getVideoDockCount;
/**
 获取参会人列表
 
 @return 参会人列表（name,paticipantUri）
 */
+ (NSArray *)getParticipants;
/**
 获取我在会议中的信息（只有当会议室是Actinve时有效）
 
 @return participantUri 会议中的Uri
 participantID  会议中的ID
 */
+ (NSDictionary *)getMyConferenceInfo;
/**
 获取屏幕共享的信息
 @return （目前仅返回了共享数量的信息）
 */
+ (id)getShareApplicationInfo;
/**
 重新设置自己预览的名称
 
 @param displayname 名称
 @return 方法调用是否成功
 */
+ (BOOL)setSelfDisplayName:(NSString *)displayname;
/**
 重新设置显示名称
 
 @param displayname 用户名称
 @param uri 参会人的uri
 @return 方法调用是否成功
 */
+ (BOOL)setDisplayName:(NSString *)displayname uri:(NSString *)uri;
/**
 分享图片
 @param image 图片
 */
//+ (void)startShareImage:(UIImage *)image;
/**
 取消分享图片
 */
+ (void)stopShareImage;
/**
 设置字体显示
 
 @param fontPath 字体路径
 */
+ (void)readFromAssets:(NSString *)fontPath;
/**
 开启高清画质
 
 @param enable 是否开启最佳画质 （默认是NO）
 @return 是否开启成功
 */
+ (BOOL)bestVideoQuality:(BOOL)enable;
/**
 总是使用VidyoProxy
 
 @param enable 是否开启代理 （默认是NO）
 */
+ (void)enableForceProxy:(BOOL)enable;
/**
 总是使用自定义Proxy
 
 @param address 代理地址
 @param port 代理port
 */
+ (void)enableProxy:(NSString *)address port:(NSString *)port;
/**
 取消自定义代理
 */
+ (void)disableProxy;


/**
 ============================================================================
 ============================================================================
 -----------------------------------BasicService-----------------------------
 ============================================================================
 ============================================================================
 */
/**
 service请求的ip地址或者域名地址
 
 @param address 请求地址
 */
+ (void)serviceAddress:(NSString *)address;
//MARK: 联系人相关服务
/**
 模糊查询联系人呢
 
 @param searchStr 输入字符
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)searchConatctWithStr:(NSString *)searchStr
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail;
/**
 修改联系人信息
 
 @param avatar 头像
 @param mail 邮箱
 @param mobile 电话
 @param name 姓名
 @param officeTel 办公电话
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)reviseConatctWithAvatar:(NSString *)avatar
                           mail:(NSString *)mail
                         mobile:(NSString *)mobile
                           name:(NSString *)name
                      officeTel:(NSString *)officeTel
                         userid:(NSString *)userid
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail ;
/**
 用户id查询
 
 @param userid 用户Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)searchConatctWithUserid:(NSString *)userid
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail ;


/**
 查询机构
 
 @param org   机构Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)searchOrgWithOrg:(NSString *)org
//                tenantid:(NSString *)tenantid
                 success:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail ;

/**
 新增个人联系人
 
 @param usersid 用户Id数组
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)addContactArray:(NSArray *)usersid
                success:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail ;
/**
 删除个人联系人
 
 @param usersid 用户Id数组
 @param success 成功回调
 @param fail 失败回调
 */

+ (void)delContactArray:(NSArray *)usersid
                success:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail ;
/**
 查询个人联系人
 
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)searchContactSuccess:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail ;
//MARK: 会议相关服务
/**
 获取正在进行的会议列表
 
 @param success 成功回调
 @param fail 失败回调
 */
+(void)confListWithUserId:(NSString *)userId
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail;
/**
 获取历史会议列表
 
 @param page 当前页
 @param size 长度
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)conferenceHistoryListPage:(NSInteger)page
                         pageSize:(NSInteger)size
                           userId:(NSString *)userId
                          success:(GNSuccessBlock)success
                             fail:(GNFailBlock)fail;
/**
 获取模版列表
 
 @param page 当前页
 @param size 长度
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)templateListWithPage:(NSInteger)page
                    pageSize:(NSInteger)size
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail;
/**
 删除会议模板
 
 @param Id 模板Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)delTemplateWithId:(NSString *)Id
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail;
/**
 查看会议详情
 
 @param conferenceid 会议Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)conferenceDetailWithId:(NSString *)conferenceid
                       success:(GNSuccessBlock)success
                          fail:(GNFailBlock)fail;
/**
 查看历史会议详情
 
 @param globalConferenceID 会议Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)conferenceHistoryWithId:(NSString *)globalConferenceID
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail ;

/**
 创建／更新模板
 
 @param templateId 模板Id  （不传id则为创建模板，否则即为更新模板）
 @param title 模板标题
 @param userIdArr 模板标题
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)createTemplateWithId:(NSString *)templateId
                       title:(NSString *)title
                   userIdArr:(NSArray *)userIdArr
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail;


/**
 删除会议模板
 
 @param templateId 模板Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)removeTemplateWithId:(NSString *)templateId
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail;



/**
 创建会议
 
 @param title 会议标题
 @param userIdArr 参会人员id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)createConferenceWithTitle:(NSString *)title
                        userIdArr:(NSArray *)userIdArr
                          success:(GNSuccessBlock)success
                             fail:(GNFailBlock)fail;

/**
 修改密码
 MARK: 用户相关
 @param oldPWD 旧密码
 @param newPWD 新密码
 @param userid 用户Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)revisePWDWithOldPWD:(NSString *)oldPWD
                     newPWD:(NSString *)newPWD
                     userid:(NSString *)userid
                    success:(GNSuccessBlock)success
                       fail:(GNFailBlock)fail ;

/**
 用户登出
 
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)loginOutSuccess:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail ;




//MARK: 登录相关
/**
 发起登录
 
 @param loginName 账户名
 @param password 密码
 @param tenant 租户名
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)loginWithLoginName:(NSString *)loginName
                  password:(NSString *)password
                    tenant:(NSString *)tenant
                   success:(GNSuccessBlock)success
                      fail:(GNFailBlock)fail ;

/**
 环境配置
 
 @param domain 可以是域名，可以是域名和端口
 */
+ (void)domain:(NSString *)domain ;


/**
 配置后台模式，视频质量，代理模式

 @param backgrandMode 后台模式
 @param quanlityMode 视频质量
 @param proxyMode 代理模式
 */
+ (void)backgrandMode:(BOOL)backgrandMode quanlityMode:(BOOL)quanlityMode proxyMode:(BOOL)proxyMode ;

/**
 ============================================================================
 ============================================================================
 -----------------------------------ConfService------------------------------
 ============================================================================
 ============================================================================
 
 
 
 
 */
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
 离开会议室同时告知服务端
 
 @param globalConferenceID 会议Id
 @param uid 用户Id
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


/**
 ============================================================================
 ============================================================================
 -----------------------------------PrivateService---------------------------
 ============================================================================
 ============================================================================
 */

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
 唤醒后执行
 
 @param weblink 有效连接
 */
+ (void)wakeUp:(NSString *)weblink ;

/**
 设置用户信息
 
 @param cossUrl 域名
 @param cossPort 端口
 @param userId
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
 ============================================================================
 ============================================================================
 -----------------------------------HTTP-----------------------------
 ============================================================================
 ============================================================================
 */

+ (void)getRoomInfoWithUserId:(NSString *)userId
                      success:(GNSuccessBlock)success
                         fail:(GNFailBlock)fail ;


+ (void)createConf:(NSString *)conference
             owner:(NSDictionary *)owner
             users:(NSArray *)users
           success:(GNSuccessBlock)success
              fail:(GNFailBlock)fail ;


+ (void)roomNumber:(NSString *)roomNumber
      conferenceId:(NSString *)conferenceId
           subject:(NSString *)subject
          userName:(NSString *)displayName
      invitedUsers:(NSArray *)invitedUsers
  invitedTerminals:(NSArray *)invitedTerminals
             login:(BOOL)login ;


+ (void)getTerminalListWithDeviceType:(NSString *)deviceType
                              success:(GNSuccessBlock)success
                                 fail:(GNFailBlock)fail ;


+ (void)getTerminalTypeSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail ;

+ (void)confInvite:(NSString *)globalConferenceID
             users:(NSArray *)users
           success:(GNSuccessBlock)success
              fail:(GNFailBlock)fail ;

+ (void)setRoomWithRoomId:(NSString *)roomId
                     lock:(BOOL)isLocked
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail ;

+ (void)setRoomWithRoomId:(NSString *)roomId
                  roomPIN:(NSString *)roomPIN
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail ;


/**
 ============================================================================
 ============================================================================
 -----------------------------------websocket-----------------------------
 ============================================================================
 ============================================================================
 */


+ (void)WSLink:(NSString *)url ;

+ (void)WSClose ;


/**
 ============================================================================
 ============================================================================
 -----------------------------------新平台-----------------------------
 ============================================================================
 ============================================================================
 */


/**
 
 socket
 */
+ (void)AdmissionRequestSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail ;
/**

 HTTP
 */
+ (void)GetTerminalsRequestLimitNumber:(NSInteger)limitNumber searchName:(NSString *)searchName success:(GNSuccessBlock)success fail:(GNFailBlock)fail ;

+ (void)GetUsersRequestLimitNumber:(NSInteger)limitNumber departmentId:(NSString *)departmentId success:(GNSuccessBlock)success fail:(GNFailBlock)fail ;

+ (void)getUserListPageNum:(NSInteger)pageNum pageSize:(NSInteger)pageSize success:(GNSuccessBlock)success fail:(GNFailBlock)fail ;

@end
