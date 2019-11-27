//
//  NSError+Ctegory.m
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2018/9/13.
//  Copyright © 2018年 com.changhongit. VidyoSample. All rights reserved.
//

#import "NSError+Ctegory.h"
#import <objc/runtime.h>
@implementation NSError (Ctegory)

- (NSError *)wrapperError {
    
    NSData *data = self.userInfo[@"com.alamofire.serialization.response.error.data"];
    if (data) {
        NSDictionary *json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        NSString *mes = json[@"message"];
        if (mes.length > 0) {

            NSError *error = [[NSError alloc]initWithDomain:@"错误描述" code:1000 userInfo:@{NSLocalizedDescriptionKey:mes}];
            return error;

        }
    }
    
    return self;
    
}

+ (NSError *)wrapperError:(id )desc {
    
    if (desc) {
        
        NSData *d = [NSJSONSerialization dataWithJSONObject:desc options:0 error:nil];
        NSError *error = [[NSError alloc]initWithDomain:@"错误描述" code:1000 userInfo:@{NSLocalizedDescriptionKey:[[NSString alloc]initWithData:d encoding:NSUTF8StringEncoding ]}];
        
        return error;
    }
    return nil ;
}


@end
