//
//  GNDefault.m
//  GN-OC
//
//  Created by Xianxiangdaishu on 2017/11/22.
//  Copyright © 2017年 XXDS. All rights reserved.
//

#import "GNDefault.h"

@implementation GNDefault

+ (void)setObject:(id)value key:(NSString *)key {

    [[self userDefault] setObject:value forKey:key];
    [[self userDefault] synchronize];
}

+ (id)objectForKey:(NSString *)key {
    
   return  [[self userDefault] objectForKey:key];
}
+ (NSUserDefaults *)userDefault {
    
    return [NSUserDefaults standardUserDefaults];
}
@end
