//
//  GNDate.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/4/3.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNDate.h"

@implementation GNDate
{
    
    NSDateFormatter *f ;
}

+ (instancetype)sharedInstance {

    static GNDate *d = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        d = [[GNDate alloc]init];
        [d setConfig];
    });
    return d ;
}
- (void)setConfig {
    
    f = [[NSDateFormatter alloc]init];
    [f setDateFormat:@"yyyy-MM-dd-HH:mm:ss:SSS"];
}
+ (NSString *)currentTime {
    
    GNDate *d = [self sharedInstance];
    return  [d->f stringFromDate:[NSDate new] ];
}


@end
