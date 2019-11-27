//
//  CHITReq.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/8/23.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GNWSReq.h"
#import "GNHTTPReq.h"
//模糊查询联系人
@interface ContactSearchReq : GNWSReq

//@property (nonatomic, copy) NSString * uid;
@property (nonatomic, copy) NSString * name;
@property (nonatomic, copy) NSString * mobile;

@end
//修改用户个人信息
@interface ContactReviseReq : GNWSReq

@property (nonatomic,copy)NSString *avatar;
@property (nonatomic,copy)NSString *mail;
@property (nonatomic,copy)NSString *mobile;
@property (nonatomic,copy)NSString *name;
@property (nonatomic,copy)NSString *officeTel;
@property (nonatomic,copy)NSString *userid;

@end
//查询个人信息
@interface ContactSearchOneReq : GNWSReq

@property (nonatomic,copy)NSString *userid;

@end



//查询组织结构以及当前组织结构下的人员
@interface ContactOrgReq : GNWSReq

@property (nonatomic,copy)NSString *organizationid;
//@property (nonatomic,copy)NSString *tenantid;

@end

//新增个人联系人
@interface ContactAddReq : GNWSReq

@property (nonatomic,strong)NSArray *usersid;
@end

//删除个人联系人
@interface ContactDelReq : GNWSReq

@property (nonatomic,strong)NSArray *usersid;

@end

//查询个人联系人
@interface ContactMeReq : GNWSReq

@property (nonatomic,copy)NSString *organizationid;
//@property (nonatomic,copy)NSString *tenantid;

@end


//MARK: 会议相关请求
@interface ConferenceReq : GNWSReq

@property (nonatomic,strong)NSNumber *page;
@property (nonatomic,strong)NSNumber *size;

@end

@interface ConferenceDetailReq : GNWSReq


@property (nonatomic, copy) NSString * conferenceId;
@property (nonatomic, copy) NSString * globalConferenceID;
@property (nonatomic, copy) NSString * name;
@property (nonatomic, copy) NSArray  * users;

@end

@interface ConferenceInvateReq : GNWSReq

@property (nonatomic, copy) NSString * conferenceId;
@property (nonatomic, copy) NSArray  * usersid;

@end

@interface ConferenceJoinReq : GNWSReq

@property (nonatomic, copy) NSString * globalConferenceID;
@property (nonatomic, copy) NSString * userid;
@property (nonatomic, copy) NSString * participantID;
@property (nonatomic, copy) NSString * participantURI;
@property (nonatomic, copy) NSString * callFlag;
@property (nonatomic,copy)NSString * userTerminalType;

@end

@interface ConferenceTemplateDelReq : GNWSReq

@property (nonatomic,copy)NSString *id;
@end

@interface ConferenceStatusReq : GNWSReq

@property (nonatomic,copy)NSString *globalConferenceID;
@end

////MARK: 用户相关
//
//@interface MineLoginoutReq : GNWSReq
//
//@end
//
////修改密码
//@interface MinePWDReq : GNWSReq
//
//
//
//@property (nonatomic,copy)NSString *oldPassword;
//@property (nonatomic,copy)NSString *userid;
//
//@property (nonatomic,copy)NSString *originalPwd;
//
//
//@end


//MARK: 登录相关
//@interface LoginReq :GNWSReq
//
//@property (nonatomic,copy)NSString *loginName;      //
//@property (nonatomic,copy)NSString *password;       //
//@property (nonatomic,copy)NSString *tenant;         //
//
//@property (nonatomic,copy)NSString *userTerminalType;   //终端类型
//@property (nonatomic,copy)NSString *terminalBrand;  //终端品牌
//@property (nonatomic,copy)NSString *terminalMode;   //终端型号
//@property (nonatomic,copy)NSString *terminalOS;     //终端操作系统
//@property (nonatomic,copy)NSString *appVersion;     //App版本号
//@property (nonatomic,copy)NSString *terminalOSType;  //操作系统类型
//
//@end
//




@interface CHITAdmissionRequest : GNWSReq

@property (nonatomic,copy)NSString *token;

@end
