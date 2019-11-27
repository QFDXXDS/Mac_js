//
//  GNRegex.m
//  GN-OC
//
//  Created by Xianxiangdaishu on 2018/2/6.
//  Copyright © 2018年 XXDS. All rights reserved.
//

#import "GNRegex.h"

@implementation GNRegex

+ (BOOL)isValid:(id)object {
    
    if (object && ![object isKindOfClass:[NSNull class]]) {
        
        return YES;
    }
    return NO;
}

+ (BOOL)isMobile:(NSString *)mobile {
    
    NSString *regex = @"^[0-9]*$";
    
    return [self regex:regex string:mobile];
    
}
+ (BOOL)isValidUrlStr:(NSString *)urlStr {
    
    NSString * regex = @"^[a-zA-Z0-9:/.]*$";
    
    return [self regex:regex string:urlStr];
}
+ (BOOL)isNumber:(NSString *)string {
    
    NSString * regex = @"^[0-9]*$";
    
    return [self regex:regex string:string];
}
+ (BOOL)regex:(NSString *)regex string:(NSString *)string {
    
    NSPredicate *urlTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [urlTest evaluateWithObject:string];
}

@end
