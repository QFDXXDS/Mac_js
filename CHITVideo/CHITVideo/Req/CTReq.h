//
//  CTReq.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/13.
//  Copyright © 2018年 changhongit. All rights reserved.
//


#import "GNHTTPReq.h"


@interface CTReq : GNHTTPReq

@property (nonatomic,copy)NSString *globalConferenceID;  //会议ID

@end
//入会通知
@interface CTInterConfReq : CTReq

@property (nonatomic,copy)NSString *participantURI;
@property (nonatomic,copy)NSString *callFlag;            //主叫还是被叫
@property (nonatomic,copy)NSString *participantID;       //参会人ID
@property (nonatomic,copy)NSString *supplement;          //补充参会人入会(会控终端补齐)
@property (nonatomic,copy)NSString *userTerminalType;    //终端类型, 枚举：mobile, pc, meetingController(会控终端)，长虹终端, polycomTerminal, polycomMCU,pad等
@property (nonatomic,copy)NSString *displayName;       //参会人名称

@end
// 离开会议通知
@interface CTLeaveConfReq : CTReq

@property (nonatomic,copy)NSString *userTerminalType;    //终端类型, 枚举：mobile, pc, meetingController(会控终端)，长虹终端, polycomTerminal, polycomMCU,pad等

@end
// 举手
@interface CTHandupReq : CTReq

@property (nonatomic,copy)NSString *action;  //枚举: up/down = 举手/取消举手
@property (nonatomic,copy)NSString *userTerminalType;    //终端类型, 枚举：mobile, pc, meetingController(会控终端)，长虹终端, polycomTerminal, polycomMCU,pad等

@end

// 查询会议详情
@interface CTConfDetailReq : GNHTTPReq

@property (nonatomic,copy)NSString *conferenceId;
@end
//   上传日志信息
@interface CTUploadLogReq : CTReq

@end


//  没有globalConferenceID

@interface CTNewReq : GNHTTPReq

@end
//   查询租户信息
@interface CTGetTenantReq : CTNewReq


@end
//  创建匿名用户
@interface CTAnonymousUserReq : CTNewReq

@property (nonatomic,copy)NSString *displayname;
@end

//  HTTP获取即将加入的会议室详情
@interface CTConfDetailReq1 : CTNewReq

@property (nonatomic,copy)NSString *confIdOrRoomId;

@end

//  HTTP获取即将加入的会议室详情
@interface CTConfDetailReq2 : CTNewReq

@property (nonatomic,copy)NSString *roomNumber;
@end


@interface CTWakeReq : CTNewReq

@property (nonatomic,copy)NSString *openId;
@end

@interface CTShareConferenceReq : CTNewReq

@property (nonatomic,copy)NSString *globalConferenceID;
@end

@interface CTShareRoomReq : CTNewReq

@property (nonatomic,copy)NSString *roomId;
@end





