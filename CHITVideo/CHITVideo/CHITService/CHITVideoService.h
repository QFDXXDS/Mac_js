//
//  CHITVideoService.h
//  CHitVideo
//
//  Created by user on 2018/9/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <Lmi/VidyoClient/VidyoConnector_Objc.h>

@interface CHITVideoService : NSObject
//服务是否已经启动
@property (nonatomic,assign,readonly) BOOL videoStart;
//是否正在分享图片
@property (nonatomic,assign,readonly) BOOL isShareImage;

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
+ (BOOL)initialize:(BOOL)log view:(NSViewController *)controller ;
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
 @param url 服务器url
 @param port 入会port
 @param displayName displayName
 @param login 登录状态
 */
+ (void)joinConferenceWithRoomNumber:(NSString *)roomNumber
                                 url:(NSString *)url
                                port:(NSString *)port
                         displayName:(NSString *)displayName
                               login:(BOOL )login ;
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



+ (void)cancelConference;

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
 聊天消息
 当接收到消息时会收到CHITVIDEO_GROUP_CHAT通知，通知内容为NSDictionary
 
 @param message 消息内容
 @return 调用方法是否成功
 */
+ (BOOL)sendGroupChatMsg:(NSString *)message;

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
             andHeight:(int)height;

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


+ (void)stopVideo ;

+ (VCConnector *)connector ;

@end
