//
//  GNHTTPRequest.m
//  WeVideoKit
//
//  Created by Xianxiangdaishu on 2018/1/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNHTTPObject.h"

//#define SOURCE_PATH @"/management/conference"
#define GNHTTPTimerout 15

@interface  GNHTTPObject ()

@property (nonatomic,strong)AFHTTPRequestSerializer *reqSerializer;

@property (nonatomic,strong)AFHTTPResponseSerializer *rspSerializer;

@end

@implementation GNHTTPObject

- (AFHTTPSessionManager *)AFManager {
    
    if (!_AFManager) {
        
        _AFManager = [[AFHTTPSessionManager alloc]initWithBaseURL:nil];
        _AFManager.requestSerializer = self.reqSerializer;
        _AFManager.responseSerializer = self.rspSerializer;
    }
    id token = [GNDefault objectForKey:CT_TOKEN] ;
    if (token)
        [_AFManager.requestSerializer setValue:token forHTTPHeaderField:@"token"];
    
    return _AFManager ;
}
- (AFHTTPRequestSerializer *)reqSerializer {
    
    if (!_reqSerializer) {
        
        _reqSerializer = [AFJSONRequestSerializer serializer];
        _reqSerializer.timeoutInterval = GNHTTPTimerout;
    }
    return _reqSerializer;
}
- (AFHTTPResponseSerializer *)rspSerializer {
    
    if (!_rspSerializer ) {
        _rspSerializer = [AFJSONResponseSerializer serializer];
        _rspSerializer.acceptableContentTypes = [NSSet setWithObjects: @"application/json", @"text/json", @"text/javascript",@"text/html",@"application/hal+json", nil];
        
    }
    return _rspSerializer;
}

+ (instancetype )sharedInstance {
    
    static GNHTTPObject *ma =nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
        ma = [[GNHTTPObject alloc]init];
    });
    return ma;
}

@end
