//
//  CHITHTTPReq.m
//  CHITVideo
//
//  Created by Xianxiangdaishu on 2018/9/14.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CHITHTTPReq.h"



@implementation CHITHTTPReq

- (NSString *)userToken {
    
    return [GNDefault objectForKey:CT_TOKEN] ;
}

@end
@implementation CHITRoomInfoReq

- (NSString *)serviceUrl {
    
    return @"rest/room/owner";
}
- (NSString *)GNHTTPMethod {

    return @"GET";
}


@end

@implementation CHITRoomSetReq

- (NSString *)serviceUrl {
    
    return @"/room/owner/setting";
}

@end

@implementation CHITConfListReq

- (NSString *)serviceUrl {
    
    return @"/management/conference/currentList";
}
- (NSString *)GNHTTPMethod {
    
    return @"GET";
}

@end

@implementation CHITConfHistoryReq

- (NSString *)serviceUrl {
    
    return @"rest/management/conference/historyList";
}
- (NSString *)GNHTTPMethod {
    
    return @"GET";
}

@end



@implementation CTRoomSetReq

- (NSString *)serviceUrl {
    
    return @"rest/room/owner/setting";
}

@end

@implementation CHITCreateConfReq

//- (void)setUsers:(NSArray *)users {
//
//    NSMutableArray *temp = [NSMutableArray new];
//
//
//    NSString *device = @"device";
//
//    for (id model in users) {
//
//        NSMutableDictionary *dic = [NSMutableDictionary new];
//        if ([model isKindOfClass:[ContactModel class]]) {
//
//            ContactModel *cModel = model ;
//            dic[_id] = cModel.userid?cModel.userid:cModel.id ;
//            dic[name] = cModel.name ;
//            dic[participantType] = user ;
//
//        }
//        if ([model isKindOfClass:[CHITTerminalModel class]]) {
//
//            CHITTerminalModel *tModel = model ;
//
//            dic[_id] = tModel.id ;
//            dic[name] = tModel.displayName ;
//            dic[participantType] = device ;
//        }
//
//        [temp addObject:dic];
//    }
//    _users = [NSArray arrayWithArray:temp] ;
//
//}
//- (NSDictionary *)owner {
//
//    return @{
//
//             _id: [CTUserManager userid],
//             name: [CTUserManager name],
//             participantType:user ,
//             } ;
//}

- (NSString *)serviceUrl {
    
    return @"rest/management/conference/quick";
}

//- (NSString *)serviceUrl {
//
//    return @"portal/rest/conference/join";
//}

@end

@implementation CHITConfInviteReq


- (NSString *)serviceUrl {
    
//    return @"/management/conference/invite";
    
    return @"rest/management/conference/invite" ;
}

@end

@implementation CHITHistoryDetailReq


- (NSString *)serviceUrl {
    
    return @"rest/management/conference/currentDetail";
}
- (NSString *)GNHTTPMethod {
    
    return @"GET";
}


@end

//@implementation CHITTerminalTypeReq
//
//- (NSString *)serviceUrl {
//
//    return @"/devices/deviceTypeList";
//}
//- (NSString *)GNHTTPMethod {
//
//    return @"GET" ;
//}

//@end


//@implementation CHITTerminalListReq
//
//- (NSString *)serviceUrl {
//
//    return @"/devices/complexPrecisePagingQueryByType";
//}
//- (NSString *)GNHTTPMethod {
//
//    return @"GET" ;
//}
//@end



@implementation CHITLoginReq

- (NSString *)serviceUrl {
    
    return @"portal/rest/login";
}

@end

@implementation CHITMineLoginoutReq

- (NSString *)serviceUrl {
    
    return @"portal/rest/logout";
}

@end
@implementation CHITMinePWDReq

- (NSString *)serviceUrl {
    
    return @"portal/rest/user/update";
}

@end
@implementation CHITUserListReq

- (NSString *)serviceUrl {
    
    return @"portal/rest/user/list";
}

@end
@implementation CHITTerminalListReq

- (NSString *)serviceUrl {
    
    return @"portal/rest/terminal/list";
}

@end
@implementation CHITConferenceListReq

- (NSString *)serviceUrl {
    
    return @"portal/rest/conference/list";
//    return @"rest/management/conference/currentList";

}

@end
@implementation CHITConferenceJoinReq

- (NSString *)serviceUrl {
    
    return @"portal/rest/conference/join";
}

@end



// 会议相关
@implementation CHITConferenceMgmtReq

- (NSString *)GNHTTPMethod {
    
    return @"GET" ;
}
- (NSString *)serviceUrl {
    
    return @"rest/conference-mgmt";
}

@end

@implementation CHITConferenceConferenceIdReq

- (NSString *)GNHTTPMethod {
    
    return @"GET" ;
}
- (NSString *)serviceUrl {
    
    return @"rest/conference-mgmt/conference";
}

@end

@implementation CHITConferencePageReq
- (NSString *)serviceUrl {
    
    return @"rest/conference-mgmt/page-confs";
}

@end


// 终端相关
@implementation CHITTerminalMgmtReq


- (NSString *)GNHTTPMethod {
    
    return @"GET" ;
}
- (NSString *)serviceUrl {
    
    return @"/terminal-mgmt";
}

@end
@implementation CHITTerminalTypeReq

- (NSString *)GNHTTPMethod {
    
    return @"GET" ;
}
- (NSString *)serviceUrl {
    
    return @"/terminal-mgmt/types";
}

@end

@implementation CHITTerminalMgmtPageReq


- (NSString *)serviceUrl {
    
    return @"/terminal-mgmt/page";
}

@end
@implementation CHITTerminalMgmtSearchReq


- (NSString *)serviceUrl {
    
    return @"/terminal-mgmt/search";
}

@end
@implementation CHITTerminalMgmtTerminalIdReq
- (NSString *)GNHTTPMethod {
    
    return @"GET" ;
}

- (NSString *)serviceUrl {
    
    return @"/terminal-mgmt/terminal";
}

@end

// 组织机构
@implementation CHITTenantReq

- (NSString *)GNHTTPMethod {
    
    return @"GET" ;
}
- (NSString *)serviceUrl {
    
    return @"/tenant-mgmt";
}

@end

@implementation CHITTenantMgmtReq

- (NSString *)GNHTTPMethod {
    
    return @"GET" ;
}
- (NSString *)serviceUrl {
    
    return @"/tenant-mgmt/tenant";
}

@end


// 联系人相关
@implementation CHITUserMgmtReq
- (NSString *)GNHTTPMethod {
    
    return @"GET" ;
}
- (NSString *)serviceUrl {
    
    return @"/user-mgmt";
}

@end
@implementation CHITUserMgmtPageReq

- (NSString *)serviceUrl {
    
    return @"rest/user-mgmt/page";
}
- (id)GNParameters {
    
    return @{
             @"userToken":self.userToken,
             @"pageRequest": @{
                     @"pageNum":_pageNum,
                     @"pageSize": _pageSize
                     }
             };
}


@end
@implementation CHITUserMgmtSearchReq

- (NSString *)serviceUrl {
    
    return @"/user-mgmt/search";
}

@end

@implementation CHITUserMgmtDeptIdReq

- (NSString *)GNHTTPMethod {
    
    return @"GET" ;
}
- (NSString *)serviceUrl {
    
    return @"/user-mgmt/dept";
}

@end
@implementation CHITUserMgmtUserIdReq
- (NSString *)GNHTTPMethod {
    
    return @"GET" ;
}
- (NSString *)serviceUrl {
    
    return @"rest/user-mgmt/user/";
}

@end
