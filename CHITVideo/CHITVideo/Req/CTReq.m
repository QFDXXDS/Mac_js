//
//  CTReq.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/13.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CTReq.h"

#define SOURCE_PATH @"/management/conference/"

@implementation CTReq


- (instancetype)init {
    
    if (self = [super init]) {
        
        self.globalConferenceID = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID];
    }
    return self ;
}


@end



@implementation CTInterConfReq

- (NSString *)serviceUrl {
    
    NSString *serviceUrl = [SOURCE_PATH stringByAppendingString:@"joinSuccess"];
    return serviceUrl;
}
@end

@implementation CTLeaveConfReq

- (NSString *)serviceUrl {
    
    NSString *serviceUrl = [SOURCE_PATH stringByAppendingString:@"leaveMeeting"];

    return serviceUrl;
}

@end

@implementation CTHandupReq

- (NSString *)serviceUrl {
    
    NSString *serviceUrl = [SOURCE_PATH stringByAppendingString:@"sethandUp"];

    return serviceUrl;
}

@end

@implementation CTConfDetailReq

- (NSString *)serviceUrl {
    
//    NSString *serviceUrl = [SOURCE_PATH stringByAppendingString:@"detail"];

    return @"rest/management/conference/detail";
}
- (NSString *)GNHTTPMethod {
    
    return @"GET";
}

@end

@implementation CTUploadLogReq

- (NSString *)serviceUrl {
    
    NSString *domain = [GNDefault objectForKey:CT_BASE_DOMAIN];
    NSString *URL = [NSString stringWithFormat:@"%@:80/fileMgmt/upload",domain];
    return URL;
}

@end



@implementation CTNewReq


@end

@implementation CTGetTenantReq

- (NSString *)serviceUrl {
    
    NSString *serviceUrl = [SOURCE_PATH stringByAppendingString:@"tenant"];

    return serviceUrl;
}
- (NSString *)GNHTTPMethod {
    
    return @"GET";
}

@end

@implementation CTAnonymousUserReq

- (NSString *)serviceUrl {
    
    return @"/user/visitor";
}

@end

@implementation CTConfDetailReq1

- (NSString *)serviceUrl {
    
    return @"/management/getConfByRoomIdOrConfId";
}
- (NSString *)GNHTTPMethod {
    
    return @"GET";
}

@end


@implementation CTConfDetailReq2

- (NSString *)serviceUrl {
    
    return @"/management/getConfByRoomNum";
}
- (NSString *)GNHTTPMethod {
    
    return @"GET";
}

@end


@implementation CTWakeReq

- (NSString *)serviceUrl {
    
    return @"/status/addWake";
}
@end

@implementation CTShareConferenceReq

- (NSString *)serviceUrl {
    
    return @"/share/conference";
}

- (NSString *)GNHTTPMethod {
    
    return @"GET";
}

@end


@implementation CTShareRoomReq

- (NSString *)serviceUrl {
    
    return @"rest/share/roomUrl";
}

- (NSString *)GNHTTPMethod {
    
    return @"GET";
}

@end

