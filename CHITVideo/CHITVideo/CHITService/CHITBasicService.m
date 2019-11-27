//
//  CHITBasicService.m
//  CHitVideo
//
//  Created by user on 2018/9/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CHITBasicService.h"
#import "CHITReq.h"
#import "GNWSManager.h"
#import "GNRegex.h"
#import "GNDeviceInfo.h"
#import "GNHTTPManager.h"

#define PORTAL_PREFIX @"ws://"
#define PORTAL_SUFFIX @":7010/jc-uccp/ws/uccp.do"
#define PORTAL_SUFFIX_SUFFIX @"/jc-uccp/ws/uccp.do"


@implementation CHITBasicService

+(void)serviceAddress:(NSString *)address{
    
}
+ (void)searchConatctWithStr:(NSString *)searchStr
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail {
    
    ContactSearchReq *req = [[ContactSearchReq alloc]init];
    req.opt = CHIT_SEARCH_CONTACT;
    if (searchStr.length > 0) {
        if ([GNRegex isMobile:searchStr]) {
            req.mobile = searchStr;
        } else {
            req.name = searchStr ;
            
        }
    }
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
    
}

+ (void)reviseConatctWithAvatar:(NSString *)avatar
                           mail:(NSString *)mail
                         mobile:(NSString *)mobile
                           name:(NSString *)name
                      officeTel:(NSString *)officeTel
                         userid:(NSString *)userid
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail {
    
    ContactReviseReq *req = [[ContactReviseReq alloc]init];
    req.opt = CHIT_UPDATE_PER;
    req.userid = userid;
    
    if (avatar) {
        req.avatar = avatar ;
    }
    if (mail) {
        req.mail = mail;
    }
    if (name) {
        req.name = name ;
    }
    if (mobile) {
        req.mobile = mobile;
    }
    if (officeTel) {
        req.officeTel = officeTel;
    }
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
    
}
+ (void)searchConatctWithUserid:(NSString *)userid
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail {
    
    ContactSearchOneReq *req = [[ContactSearchOneReq alloc]init];
    req.opt = CHIT_USERID_SEARCH ;
    req.userid = userid;
    
    
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results);
    } fail:^(NSError *error) {
        fail(error);
    }];
}



+ (void)searchOrgWithOrg:(NSString *)org
//                tenantid:(NSString *)tenantid
                 success:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail {
    
    ContactOrgReq *req = [[ContactOrgReq alloc]init];
    req.opt = CHIT_SEARCH_ORG;
    if (org) {
        req.organizationid = org;
    }
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
    
}

+ (void)addContactArray:(NSArray *)usersid
                success:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail {
    ContactAddReq *req = [[ContactAddReq alloc]init];
    req.opt = CHIT_ADD_CONTACT ;
    req.usersid = usersid;
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
    
}

+ (void)delContactArray:(NSArray *)usersid
                success:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail {
    ContactDelReq *req = [[ContactDelReq alloc]init];
    req.opt = CHIT_DELETE_CONTACT ;
    req.usersid = usersid;
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
    
}

+ (void)searchContactSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail {
    
    ContactMeReq *req = [[ContactMeReq alloc]init];
    req.opt = CHIT_ME_CONTACT ;
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
}
+ (void)confListWithUserId:(NSString *)userId
                   success:(GNSuccessBlock)success
                      fail:(GNFailBlock)fail {
    
//    ConferenceReq * req = [[ConferenceReq alloc] init];
//    req.opt = CHIT_ACTION_CON;
//
//    [GNWSManager sendReq:req success:^(id results) {
//
//        success(results) ;
//    } fail:^(NSError *error) {
//        fail(error) ;
//    }];
    
//    CHITConfListReq *req = [[CHITConfListReq alloc]init];
//    req.userId = userId;
    
    CHITConferenceListReq *req = [[CHITConferenceListReq alloc]init];
    
    [GNHTTPManager req:req success:success fail:fail];
}
+ (void)conferenceHistoryListPage:(NSInteger)page
                         pageSize:(NSInteger)size
                           userId:(NSString *)userId
                          success:(GNSuccessBlock)success
                             fail:(GNFailBlock)fail{
    
//    CHITConfHistoryReq *req = [[CHITConfHistoryReq alloc]init];
//    req.userId = userId ;
    
    CHITConferencePageReq *req = [[CHITConferencePageReq alloc]init];
    
    req.pageRequest = @{
                        @"pageNum":@(page),
                        @"pageSize": @(size)
                        } ;
    
    [GNHTTPManager req:req success:^(id results) {
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
    
//    ConferenceReq * req = [[ConferenceReq alloc] init];
//    req.opt      = CHIT_HISTORY_CON;
//    req.page = @(page);
//    req.size = @(size);
    
//    [GNWSManager sendReq:req success:^(id results) {
//
//        success(results) ;
//    } fail:^(NSError *error) {
//        fail(error) ;
//    }];
}

+ (void)templateListWithPage:(NSInteger)page
                    pageSize:(NSInteger)size
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail{
    
    ConferenceReq * req = [[ConferenceReq alloc] init];
    req.opt = CHIT_SEARCH_TEMPLATE;
    req.page = @(page);
    req.size = @(size);
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
}

+ (void)delTemplateWithId:(NSString *)Id
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail{
    
    ConferenceTemplateDelReq *req = [[ConferenceTemplateDelReq alloc]init];
    req.opt = CHIT_DELETE_TEMPLATE ;
    req.id = Id ;
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
}

+ (void)createTemplateWithId:(NSString *)globalConferenceID
                       title:(NSString *)title
                   userIdArr:(NSArray *)userIdArr
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail{
    
    ConferenceDetailReq * req = [[ConferenceDetailReq alloc] init];
    req.opt     = CHIT_CREATE_TEMPLATE;
    req.globalConferenceID   = globalConferenceID;
    req.name    = title;
    req.users = userIdArr;
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
}

+ (void)conferenceDetailWithId:(NSString *)globalConferenceID
                       success:(GNSuccessBlock)success
                          fail:(GNFailBlock)fail{
    
    
    ConferenceDetailReq * req = [[ConferenceDetailReq alloc] init];
    req.opt          = CHIT_CON_DETAIL;
    req.globalConferenceID = globalConferenceID;
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
    
}

+ (void)conferenceHistoryWithId:(NSString *)globalConferenceID
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail{
    
    
//    CHITHistoryDetailReq *req = [[CHITHistoryDetailReq alloc]init];
//    req.globalConferenceID = globalConferenceID ;
    
    
    CHITConferenceConferenceIdReq *req = [[CHITConferenceConferenceIdReq alloc]init];
    req.conferenceId = globalConferenceID ;
    
    
    [GNHTTPManager req:req success:^(id results) {
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
    
    
    
//    [GNWSManager sendReq:req success:^(id results) {
//        
//        success(results) ;
//    } fail:^(NSError *error) {
//        fail(error) ;
//    }];
    
    
    
}
+ (void)removeTemplateWithId:(NSString *)globalConferenceID
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail{
    
    ConferenceDetailReq * req = [[ConferenceDetailReq alloc] init];
    req.opt   = CHIT_DELETE_TEMPLATE;
    req.globalConferenceID    = globalConferenceID;
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results) ;
    } fail:^(NSError *error) {
        fail(error) ;
    }];
}

+ (void)createConferenceWithTitle:(NSString *)title
                        userIdArr:(NSArray *)userIdArr
                          success:(GNSuccessBlock)success
                             fail:(GNFailBlock)fail{
    
    ConferenceDetailReq * req = [[ConferenceDetailReq alloc] init];
    req.opt     = CHIT_CON_CREATE;
    req.name    = title;
    req.users = userIdArr;
    
    
    [GNWSManager sendReq:req success:^(id results) {
        
        success(results);
    } fail:^(NSError *error) {
        fail(error);
    }];
    
    
    
}

+ (void)revisePWDWithOldPWD:(NSString *)oldPWD
                     newPWD:(NSString *)newPWD
                     userid:(NSString *)userid
                    success:(GNSuccessBlock)success
                       fail:(GNFailBlock)fail {
    
    CHITMinePWDReq *req = [[CHITMinePWDReq alloc]init];
    
    req.user = @{
                 @"password":newPWD
                 
                 } ;
//    req.opt = CHIT_REVISE_PWD;
//    req.oldPassword = oldPWD;
//    req.originalPwd = newPWD;
//    req.userid = userid;
//
//    [GNWSManager sendReq:req success:^(id results) {
//        success(results);
//    } fail:^(NSError *error) {
//        fail(error);
//    }];
    
    [GNHTTPManager req:req success:^(id results) {
        
        success(results);
    } fail:^(NSError *error) {
        
        fail(error);
    }];
}

+ (void)loginOutSuccess:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail {
    
//    MineLoginoutReq *req = [[MineLoginoutReq alloc]init];
//    req.opt = CHIT_LOGIN_OUT;
//
//    [GNWSManager sendReq:eq success:^(id results) {
//        success(results);
//    } fail:^(NSError *error) {
//        fail(error);
//    }];
    
    CHITMineLoginoutReq *req = [[CHITMineLoginoutReq alloc]init];
    
    [GNHTTPManager req:req success:success fail:fail];
}


+ (void)loginWithLoginName:(NSString *)loginName
                  password:(NSString *)password
                    tenant:(NSString *)tenant
                   success:(GNSuccessBlock)success
                      fail:(GNFailBlock)fail {
    
//    LoginReq *req = [[LoginReq alloc]init];
//    req.opt = CHIT_LOGIN_IN;
//    req.loginName = loginName;
//    req.password = password;
//    req.tenant = tenant;
//
//    req.userTerminalType = [GNDeviceInfo userTerminalType];
//    req.terminalBrand = [GNDeviceInfo terminalBrand];
//    req.terminalMode = [GNDeviceInfo terminalMode];
//    req.terminalOS = [GNDeviceInfo terminalOS];
//    req.appVersion = [GNDeviceInfo appVersion];
//    req.terminalOSType = [GNDeviceInfo terminalOSType];
//
//
//    [GNWSManager sendReq:req success:^(id results) {
//
//        success(results);
//    } fail:^(NSError *error) {
//
//        fail(error);
//    }];
    
    CHITLoginReq *req = [[CHITLoginReq alloc]init];
    req.loginId = loginName ;
    req.password = password ;
    
    [GNHTTPManager req:req success:success fail:fail];
}
+ (void)domain:(NSString *)domain {
    
    NSString *ws_url = nil ;
    NSString *http_url = nil ;
    
    if ([domain containsString:@"http://"]) {
        
        domain = [[domain componentsSeparatedByString:@"://"] lastObject];
    }
    
    
    if ([domain containsString:@":"]) {
        
        ws_url = [NSString stringWithFormat:@"%@%@%@",PORTAL_PREFIX,domain,PORTAL_SUFFIX_SUFFIX];
        http_url = [NSString stringWithFormat:@"http://%@/jc-",domain] ;
    } else {
        ws_url = [NSString stringWithFormat:@"%@%@%@",PORTAL_PREFIX,domain,PORTAL_SUFFIX] ;
        http_url = [NSString stringWithFormat:@"http://%@:7010/jc-",domain] ;
    }
    
    ws_url = [ws_url stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet characterSetWithCharactersInString:@"`#%^{}\"[]|\\<> "].invertedSet];
    
    
    GNLog(@"http_url is %@", http_url) ;
    GNLog(@"ws_url is %@", ws_url) ;

    [GNDefault setObject:ws_url key:CT_WS_BASEURL];
    [GNDefault setObject:http_url key:CT_HTTP_BASEURL];
    
}



+ (void)AdmissionRequestSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail {
    
    CHITAdmissionRequest *req = [[CHITAdmissionRequest alloc]init];
//    req.name = @"AdmissionRequest" ;
    req.token = [GNDefault objectForKey:CT_TOKEN] ;
    [GNWSManager sendReq:req success:^(id results) {
//        success(results);
    } fail:^(NSError *error) {
//        fail(error);
    }];
}

+ (void)getUserListPageNum:(NSInteger)pageNum pageSize:(NSInteger)pageSize success:(GNSuccessBlock)success fail:(GNFailBlock)fail {

//    CHITUserListReq *req = [[CHITUserListReq alloc]init];
    
    CHITUserMgmtPageReq *req = [[CHITUserMgmtPageReq alloc]init] ;
    req.pageSize =  @(pageSize);
    req.pageNum =  @(pageNum);
    
    [GNHTTPManager req:req success:success fail:fail];
}


@end
