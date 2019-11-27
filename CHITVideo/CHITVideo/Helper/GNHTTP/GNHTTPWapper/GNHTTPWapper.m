//
//  GNHTTPWapper.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/22.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNHTTPWapper.h"
#import <objc/runtime.h>
#import "GNHTTPReq.h"

@implementation GNHTTPWapper

+ (NSString *)wapperWithReq:(id <GNHTTPProtocol > ) req  {
    
    NSString *s = [self wapperWithReq:req class:[req class]];
    NSString *s0 = [self wapperWithReq:req class:[req superclass]];

    return [NSString stringWithFormat:@"%@%@",s,s0];
}
+ (NSString *)wapperWithReq:(id <GNHTTPProtocol > ) req class:(Class)cls {
    
    NSString *s = @"";
    GNHTTPReq *object = req ;
    
    unsigned int count = 0;
    Ivar *ivar = class_copyIvarList(cls, &count);
    
    for (int i = 0; i< count; i++) {
        
        Ivar iv = ivar[i];
        const char *c = ivar_getName(iv);
        NSString *key = [[NSString stringWithCString:c encoding:NSUTF8StringEncoding] substringFromIndex:1] ;
        
        id value = [object valueForKey:key];
        s = [NSString stringWithFormat:@"%@/%@",s,value];
    }
    free(ivar);
    
    return s;

}

@end
