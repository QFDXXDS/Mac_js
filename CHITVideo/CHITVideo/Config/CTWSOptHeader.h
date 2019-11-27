//
//  CTWSOptHeader.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/2/5.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#ifndef CTWSOptHeader_h
#define CTWSOptHeader_h

//心跳检测
#define CT_HEART_CHECK                   @"2_1"
//app信息
#define CT_APP_INFO                      @"2_2"
//查询正在会议详情
#define CT_CONF_DETAIL                   @"4_9"
//麦克风、相机状态、相机前后置状态
#define CT_CONF_HARDWARE_STATUS          @"4_11"
//麦克风、相机状态、相机前后置状态
#define CT_CONF_INITIAL_STATUS           @"5_7"
//锁定会议
#define CT_CONF_LOCK                     @"5_11"
//接收到邀请信息
#define CT_CONF_ACCEPT                 @"5_1"


/*
 --------------------------------------------------------------------------------
 
 --------------------------------------------------------------------------------
 */

//登陆
#define CHIT_LOGIN_IN                   @"1_1"
//登出
#define CHIT_LOGIN_OUT                  @"1_2"
//查询联系人
#define CHIT_SEARCH_CONTACT             @"1_3"
//修改个人信息
#define CHIT_UPDATE_PER                 @"1_4"
//修改密码
#define CHIT_REVISE_PWD                 @"1_5"
//根据用户ID查询
#define CHIT_USERID_SEARCH              @"1_6"
//新增个人联系人
#define CHIT_ADD_CONTACT                @"1_7"
//删除个人联系人
#define CHIT_DELETE_CONTACT             @"1_8"
//查询个人联系人
#define CHIT_ME_CONTACT                 @"1_9"
//被踢下线
#define CHIT_RELOGIN                    @"1_10"
//查询个人添加的联系人
#define CHIT_ME_CONTACTSEARCH           @"1_11"



//心跳检测
#define CHIT_HEART_CHECK                @"2_1"
//查询组织机构
#define CHIT_SEARCH_ORG                 @"3_1"



//查询正在进行的会议
#define CHIT_ACTION_CON                 @"4_1"
//查询历史会议
#define CHIT_HISTORY_CON                @"4_2"
//创建／修改会议模板
#define CHIT_CREATE_TEMPLATE            @"4_3"
//删除会议模板
#define CHIT_DELETE_TEMPLATE            @"4_4"
//查询会议模板
#define CHIT_SEARCH_TEMPLATE            @"4_5"
//查询正在会议详情
#define CHIT_CON_DETAIL                   @"4_6"
//查询历史会议详情
#define CHIT_CON_HISTORY                   @"4_7"
//查询当前会议状态
#define CHIT_CON_STATUS                  @"4_8"


//接收到邀请信息
#define CHIT_CON_ACCEPT                 @"5_1"
//加入会议室成功
#define CHIT_CON_ENTER                  @"5_2"
//拒绝入会
#define CHIT_CON_REFUSE                 @"5_3"
//离开会议
#define CHIT_CON_LEAVE                  @"5_4"
//创建立即会议
#define CHIT_CON_CREATE                 @"5_5"
//邀请入会
#define CHIT_CON_INVATE                 @"5_6"

/* 二期新增接口 */

//摄像头，麦克风关闭/开启
#define CHIT_CON_HARDWARE_CTRL                 @"5_7"

////其他参会人摄像头，麦克风关闭/开启
//#define CHIT_CON_MICROPHONE_OTHER           @"5_8"
////其他参会人断开/重连/踢出
//#define CHIT_CON_LEAVE_OTHOR                @"5_9"

//结束会议
#define CHIT_CON_END                         @"5_10"


//会议模式设置切换
#define CHIT_CON_MODE                           @"5_12"
//演讲者设置
#define CHIT_CON_MODE_LECTURE                   @"5_13"
//点名设置/取消点名
#define CHIT_CON_CALLNAME                        @"5_14"
//参会人举手/取消举手
#define CHIT_CON_HANDUP                          @"5_15"


#endif /* CTWSOptHeader_h */
