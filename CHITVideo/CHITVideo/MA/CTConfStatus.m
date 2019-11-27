//
//  CTConfStatus.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/2/8.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CTConfStatus.h"

@implementation CTConfStatus

+ (instancetype)shareInstance {
    
    static CTConfStatus *s = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
        s = [[CTConfStatus alloc]init];
    });
    return s ;
}

- (BOOL)didInterConfBool {
    
    int state = [CHITVideoService  getCallState] ;
    
    if (state == 4) {
        
        return YES;
    } else {
        
        return NO;
    }
}


@end
