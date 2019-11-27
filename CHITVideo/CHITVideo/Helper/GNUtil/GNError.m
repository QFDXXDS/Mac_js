//
//  GNError.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/5/28.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNError.h"

@implementation GNError

+ (NSError *)WSRspError:(NSDictionary *)dic {

    NSInteger code = 10001;
    NSString *desc = dic[CT_WS_RETURNVALUE];
    NSError *error = [[NSError alloc]initWithDomain:@"websocketReponseError" code:code userInfo:@{NSLocalizedDescriptionKey:desc}];
    return  error;

}

+ (NSError *)WSTimeoutError {
    
    NSError *error = [[NSError alloc]initWithDomain:@"websocketReponseTimeout" code:10001 userInfo:@{NSLocalizedDescriptionKey:@"响应超时"}];
    return  error;
}
+ (NSError *)WSLinkError {
    
    NSError *error = [[NSError alloc]initWithDomain:@"websocketLinkFail" code:10002 userInfo:@{NSLocalizedDescriptionKey:@"失去连接"}];
    return  error;
}

@end
