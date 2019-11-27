//
//  GNHTTPManager.m
//  WeVideoKit
//
//  Created by Xianxiangdaishu on 2018/1/5.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNHTTPManager.h"
#import "GNHTTPObject.h"
#import "GNHTTPReq.h"
#import "GNHTTPWapper.h"
#import "GNPath.h"
#import "NSError+Ctegory.h"

@implementation GNHTTPManager

+ (void)req:(id <GNHTTPProtocol>)req
    success:(GNSuccessBlock )success
       fail:(GNFailBlock)fail {
    
    GNHTTPObject *ma = [GNHTTPObject sharedInstance];
    NSString *method = [req GNHTTPMethod];
    NSString *parameters = [req GNParameters] ;
    NSString *URL = [self URLStrWithReq:req];
    URL = [URL stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];

    
    GNLog(@"%@-%@-%@",method,parameters,URL);
    [[NSNotificationCenter defaultCenter]postNotificationName:GNLocalLogNotification object:[NSString stringWithFormat:@"%@--%@",parameters,URL] ];
    
    void (^s)(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject)  = ^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        
        [[NSNotificationCenter defaultCenter]postNotificationName:GNLocalLogNotification object:responseObject];
        
        NSDictionary *result = responseObject ;
        NSString *returnValue = result[@"returnValue"] ;
        
        success(responseObject);

//        if ([returnValue containsString:@"OK"] ) {
//
//             success(responseObject);
//        } else {
//
//
//            fail([NSError wrapperError:result]) ;
//
//        }
        
       
    };
    void (^f)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error)  = ^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        
        NSError *e = [error wrapperError];
        [[NSNotificationCenter defaultCenter]postNotificationName:GNLocalLogNotification object:e.localizedDescription];
            
        fail(e);
    };
    
    if ([method isEqualToString: @"GET"]) {
        
        [ma.AFManager GET:URL parameters:nil progress:nil success:s failure:f];
        
    } else if([method isEqualToString: @"POST"]){
        
        [ma.AFManager POST:URL parameters:parameters progress:nil success:s failure:f];
    }
}
+ (NSString *)URLStrWithReq:(id <GNHTTPProtocol>)req {
    
    NSString *URlStr = nil;
    NSString *serviceUrl = [req serviceUrl] ;
    
    URlStr = [NSString stringWithFormat:@"%@%@",[GNDefault objectForKey:CT_HTTP_BASEURL],serviceUrl];
    
    if ([[req GNHTTPMethod] isEqualToString:@"GET"]) {
        
        URlStr = [NSString stringWithFormat:@"%@%@",URlStr,[GNHTTPWapper wapperWithReq:req]];
    }
    
    return URlStr ;
}

+ (void)upload:(id <GNHTTPProtocol>)req
       zapPath:(NSString *)zipPath
       success:(GNSuccessBlock )success
          fail:(GNFailBlock)fail {
    
    GNHTTPObject *ma = [GNHTTPObject sharedInstance];

    GNLog(@"%@-%@-%@",[req GNHTTPMethod],[req GNParameters],[req serviceUrl]);

    [ma.AFManager POST:[req serviceUrl] parameters:nil constructingBodyWithBlock:^(id<AFMultipartFormData>  _Nonnull formData) {
        
        NSString *logName = [GNPath logName];
        NSString *fileName = [NSString stringWithFormat:@"%@%@.zip",logName,[GNDate currentTime]];
        [formData appendPartWithFileURL:[NSURL fileURLWithPath:zipPath] name:@"file" fileName:fileName mimeType:@"" error:nil];
        
    } progress:nil success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        
        GNLog(@"日志上传  成功") ;
        success(nil);
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        
        NSError *e = [error wrapperError];
        GNLog(@"日志上传  失败 ") ;
        fail(e) ;
    }];
}
@end
