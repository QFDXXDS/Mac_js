//
//  ChityoWSConf.h
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2017/9/27.
//  Copyright © 2017年 com.changhongit. VidyoSample. All rights reserved.
//

#ifndef CHITNotificationConfig_h
#define CHITNotificationConfig_h



//被踢下线
static NSString * CHReLoginNoti = @"CHReLoginNoti";
//用户收到入会邀请的通知
static NSString * CHInvatedToJoinConferenceNoti = @"invatedToJoinConference";
//好友下线的通知
static NSString * CHContactStatusChangeNoti = @"contactStatusChange";
//socket重连
static NSString * CHWSReconnectNoti = @"CHWSReconnectNoti";
//退出登录通知
static NSString * CHLoginOutNoti = @"CHLoginOutNoti";

/* 二期新增功能 */

static NSString  * CHConfCtrlDetailNoti = @"CHConfCtrlDetailNoti";


//控制硬件打开麦克风、摄像头
static NSString  * CHChangeHardwareCtrlNoti = @"CHChangeHardwareCtrlNoti";
//切换会议模式
static NSString  * CHConfChangeModeNoti = @"CHConfChangeModeNoti";
//当前演讲者是谁，前提是进入模式情况下
static NSString  * CHConfLectureNoti = @"CHConfLectureNoti";
//点名设置/取消点名
static NSString * CHConfCallNameNoti = @"CHConfCallNameNoti";


static NSString * CHITDidLoginSuccessNotification = @"CHITDidLoginSuccessNotification";


#endif /* ChityoWSConf_h */
