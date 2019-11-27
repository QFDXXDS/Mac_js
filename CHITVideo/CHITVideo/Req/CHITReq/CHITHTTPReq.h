//
//  CHITHTTPReq.h
//  CHITVideo
//
//  Created by Xianxiangdaishu on 2018/9/14.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNHTTPReq.h"

@interface CHITHTTPReq : GNHTTPReq

@property (nonatomic,copy)NSString *userToken;
@end


@interface CHITRoomInfoReq : GNHTTPReq

@property (nonatomic,copy)NSString *userId;
@end

@interface CHITRoomSetReq : CHITHTTPReq

@property (nonatomic,copy)NSString *roomId;
@property (nonatomic,assign)BOOL isLocked;
@property (nonatomic,assign)BOOL hasPIN;
@property (nonatomic,copy)NSString *roomPIN;

@end
@interface CHITConfListReq : CHITRoomInfoReq

@end
@interface CHITConfHistoryReq : CHITRoomInfoReq

@end

@interface CTRoomSetReq : CHITHTTPReq

@property (nonatomic,copy)NSString *roomId;
@property (nonatomic,strong)NSNumber *locked;
@property (nonatomic,strong)NSNumber *hasPIN;
@property (nonatomic,copy)NSString *roomPIN;

@end

@interface CHITCreateConfReq : CHITHTTPReq

@property (nonatomic,copy)NSString *conference;
@property (nonatomic,copy)NSString *groupId;
@property (nonatomic,strong)NSDictionary *owner ;
@property (nonatomic,strong)NSArray *users ;


@end



@interface CHITConfInviteReq : CHITCreateConfReq

@property (nonatomic,copy)NSString *globalConferenceID;

@end
@interface CHITHistoryDetailReq : CHITConfInviteReq


@end


//查询终端类别
//@interface CHITTerminalTypeReq :CHITHTTPReq
//
//
//@end
////查询终端对应列表
//@interface CHITTerminalListReq :CHITHTTPReq
//
//@property (nonatomic,copy)NSString *deviceType;
//@end




// MARK: 登录相关
@interface CHITLoginReq :GNHTTPReq

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

@property (nonatomic,copy)NSString *loginId;

//@property (nonatomic,copy)NSString *email;
@property (nonatomic,copy)NSString *password;

//"email":"yzhao@chit.com",
//"password":"yzhao"
//}

@end

@interface CHITMineLoginoutReq : CHITHTTPReq

@end

//修改密码
@interface CHITMinePWDReq : CHITHTTPReq



//@property (nonatomic,copy)NSString *oldPassword;
//@property (nonatomic,copy)NSString *userid;

//@property (nonatomic,copy)NSString *originalPwd;

@property (nonatomic,strong)NSDictionary *user;

@end


@interface CHITUserListReq : CHITHTTPReq


@end

@interface CHITConferenceListReq : CHITHTTPReq

//@property (nonatomic,copy)NSString *userId;
@end
@interface CHITConferenceJoinReq : CHITHTTPReq


@property (nonatomic,copy)NSString *confNumber;
@property (nonatomic,copy)NSString *subject;
@property (nonatomic,copy)NSString *userName;
@property (nonatomic,copy)NSString *clientType;

@property (nonatomic,copy)NSString *confId;
@property (nonatomic,copy)NSString *confPin;
@property (nonatomic,copy)NSString *userId;
@property (nonatomic,strong)NSArray *invitedUsers ;
@property (nonatomic,strong)NSArray *invitedTerminals ;

@end

// 会议相关
@interface CHITConferenceMgmtReq : CHITHTTPReq


@end

@interface CHITConferenceConferenceIdReq : GNHTTPReq

@property (nonatomic,copy)NSString *conferenceId;
@end

@interface CHITConferencePageReq : CHITHTTPReq

@property (nonatomic,strong)NSDictionary *pageRequest;

@end




// 终端相关
@interface CHITTerminalListReq : CHITHTTPReq


@end

@interface CHITTerminalMgmtReq : CHITHTTPReq


@end
@interface CHITTerminalTypeReq : CHITHTTPReq


@end

@interface CHITTerminalMgmtPageReq : CHITHTTPReq


@end
@interface CHITTerminalMgmtSearchReq : CHITHTTPReq


@end
@interface CHITTerminalMgmtTerminalIdReq : CHITHTTPReq


@end

// 组织相关
@interface CHITTenantReq : CHITHTTPReq



@end

@interface CHITTenantMgmtReq : CHITHTTPReq

@property (nonatomic,copy)NSString *tenantId;

@end


// 联系人相关
@interface CHITUserMgmtReq : CHITHTTPReq


@end
@interface CHITUserMgmtPageReq : CHITHTTPReq

@property (nonatomic,strong)NSNumber *pageNum;
@property (nonatomic,strong)NSNumber *pageSize;

@end
@interface CHITUserMgmtSearchReq : CHITHTTPReq


@end


@interface CHITUserMgmtDeptIdReq : CHITHTTPReq

@property (nonatomic,copy)NSString *deptId;

@end

@interface CHITUserMgmtUserIdReq : CHITHTTPReq

@property (nonatomic,copy)NSString *userId;

@end




