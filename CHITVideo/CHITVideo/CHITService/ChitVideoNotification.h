//
//  ChitVideoNotification.h
//  WWXVidyoNew
//
//  Created by user on 2017/11/15.
//  Copyright © 2017年 xx. All rights reserved.
//

#ifndef ChitVideoNotification_h
#define ChitVideoNotification_h

//ChitVideo初始化成功通知
static NSString * ChitVideoNotificationStartSuccess = @"CHITVIDEO_LOGIC_STARTED";

//游客加入会议失败通知
static NSString * ChitVideoNotificationGuestJoinFail     = @"CHITVIDEO_JOIN_FAILED";
/*
     登录/登出通知
     state 状态
     {
        CLIENT_USER_SIGNED_SUCCESS = 0,  成功
        CLIENT_USER_SIGNED_FAILED = 1    失败
     }
     case 类型
     {
        CLIENT_USER_SIGNED_IN = 0,        登录
        CLIENT_USER_SIGNED_OUT = 1,       登出
        CLIENT_SERVER_SIGNED_OUT = 2,     被踢登出
        CLIENT_BIND_USER_TIMEOUT = 3,     超时
        CLIENT_AUTHENTICATION_FAILED = 4, 认证失败，用户可能被禁、被删除、可以尝试重新登录
        CLIENT_EMCP_RETRIES_EXCEEDED = 5, 尝试次数超过上限
     }
     error 错误代码
     {
        #ChitVideoErrorCode.h
     }
 */
static NSString * ChitVideoNotificationSignedStatus      = @"CHITVIDEO_SIGNED_STATUS";

//收到呼叫请求通知
static NSString * ChitVideoNotificationIncomingCall      = @"CHITVIDEO_INCOMING_CALL";

//入会成功通知
static NSString * ChitVideoNotificationConferenceActive  = @"CHITVIDEO_CONFERENCE_ACTIVE";
//会议室清空
static NSString * ChitVideoNotificationConferenceCleared =  @"CHITVIDEO_CONFERENCE_CLEARED";

//参会人改变通知
static NSString * ChitVideoNotificationPaticipantsChange = @"CHITVIDEO_PARTICIPANTS_CHANGED";


/**
     ChatMessage 收到Message通知
     type{
        GROUP   = 0,
        PRIVATE = 1
     }
 */
static NSString * ChitVideoNotificationTextMessage       = @"CHITVIDEO_CHAT";

/**
     muted通知
     type{
        MUTED_VIDEO           = 0,  视频muted
        MUTED_AUDIO_IN        = 1,  麦克风muted
        MUTED_AUDIO_OUT       = 2,  扬声器muted
        MUTED_SERVER_VIDEO    = 3,  视频被服务器mute
        MUTED_SERVER_AUDIO_IN = 4,  麦克风被服务器mute
     }
     mute
    {
        YES 表示被mute
        NO 表示不被mute
     }
     error 错误代码
    {
        #ChitVideoErrorCode.h
     }
 */
static NSString * ChitVideoNotificationMutedVideo        = @"CHITVIDEO_MUTED_STATUS";

/*
    点击屏幕通知
    state 类型
    {
      CLIENT_TOUCH_STATE_START = 0, Touch started
      CLIENT_TOUCH_STATE_MOVE,      Moved during touch
      CLIENT_TOUCH_STATE_STOP,      Touch stopped
      CLIENT_TOUCH_STATE_UNKNOWN,   Touch state is not recognized
    }
*/
static NSString * ChitVideoNotificationTouch             = @"CHITVIDEO_TOUCH";

//重新改变大小通知
static NSString * ChitVideoNotificationResize            = @"CHITVIDEO_RESIZE";

/**
 获取视频流
 
 width:Width of shared frame

 height:Height of shared frame;

 format:
 The fourcc code of the frame format. Default value is ARGB. Other values supported are I420 & YUV12.
 e.g. To encode ARGB, the 1st 8 bits should be 'A', 2nd 8 bits should be 'R', 3rd 8 bits should be 'G'
 and the last (most significant) 8 bits should be 'B'.

 size:
 The size of the data buffer holding the frame

 data:
 Frame data start. Frame data must be contiguous in memory so that it can be passed to VidyoClientSendEvent
 @note Do not add structure members below
 @note When calling VidyoClientSendEvent set event data size to sizeof(VidyoClientInEventVideoFrame)+VidyoClientInEventVideoFrame.size

*/
static NSString * ChitVideoNotificationVideoFrame        = @"CHITVIDEO_RECEIVED_VIDEO_FRAME";


/*
     获取屏幕分享的信息
     type 类型
     {
         0，接受屏幕分享
         1，移除屏幕分享
         2，关闭屏幕分享
     }
 */
static NSString * ChitVideoNotificationShares            = @"CHITVIDEO_SHARE_WINDOWS";


//获取日志通知
static NSString * ChitVideoNotificationReceiveLog        = @"CHITVIDEO_LOG";


// 会中邀请参会人(需要登录后响应)
extern  NSString *const ChitVideoInviteContactNotification ;

extern  NSString *const  CTWSConfInviteNotification ;
#endif /* ChitVideoNotification_h */
