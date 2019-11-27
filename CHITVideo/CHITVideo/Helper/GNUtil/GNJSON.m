//
//  GNJSON.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/5/28.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNJSON.h"

@implementation GNJSON

+ (id)toJSON:(id )data {
    
    NSData *d = nil ;
    if ([data isKindOfClass:[NSString class]]){
        
        d = [data dataUsingEncoding:NSUTF8StringEncoding];
    } else {
        
        d = data;
    }
    id json = [NSJSONSerialization JSONObjectWithData:d options:0 error:nil];
    return  json;
}

+ (NSString *)toString:(id )json {

    NSData *d = [NSJSONSerialization dataWithJSONObject:json options:0 error:nil];
    NSString *s = [[NSString alloc]initWithData:d encoding:NSUTF8StringEncoding];
    return s;
}
@end
