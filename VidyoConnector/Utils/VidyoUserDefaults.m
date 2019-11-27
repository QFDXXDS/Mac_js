//
//  VidyoUserDefaults.m
//  VidyoSample
//
//  Created by user on 16/12/30.
//  Copyright © 2016年 com.changhongit. VidyoSample. All rights reserved.
//

#import "VidyoUserDefaults.h"

#define UserDefaults @"UserDefaults"
#define PoratlDefaults @"PoratlDefaults"

static VidyoUserDefaults * _shareDefaults = nil;


@implementation VidyoUserDefaults
+ (VidyoUserDefaults *)shareNetworking{
    static dispatch_once_t onceToken;
    _dispatch_once(&onceToken, ^{
        _shareDefaults = [[self alloc] init];
    });
    return _shareDefaults;
}


+(void)setDefault:(NSString *)key value:(id)value{
    [[NSUserDefaults standardUserDefaults] setObject:value forKey:key];
    [[NSUserDefaults standardUserDefaults] synchronize];
}
//本地用户的存储信息
+ (void)setUserDefault:(NSString *)key value:(id)value{
    NSDictionary * userDic = [[NSUserDefaults standardUserDefaults] dictionaryForKey:UserDefaults];
    
    if (!userDic) {
        userDic = [NSDictionary dictionary];
    }
    NSMutableDictionary * defaultDic = [NSMutableDictionary dictionaryWithDictionary:userDic];
    [defaultDic setValue:value forKey:key];
    
    [[NSUserDefaults standardUserDefaults] setObject:defaultDic forKey:UserDefaults];
    [[NSUserDefaults standardUserDefaults] synchronize];
}
+ (id)getDefault:(NSString *)key{
    id userDic =  [[NSUserDefaults standardUserDefaults] objectForKey:key];
    return userDic;
}
//根据key获取本地存储的信息
+ (id)getUserDefault:(NSString *)key{
    NSDictionary * userDic =  [[NSUserDefaults standardUserDefaults] dictionaryForKey:UserDefaults];
    if([userDic objectForKey:key]){
        return [userDic objectForKey:key];
    }
    return nil;
}
//portal本地存储
+ (void)setPortalDefault:(NSString *)value{
    NSArray * portals = [[NSUserDefaults standardUserDefaults] arrayForKey:PoratlDefaults];
    if (!portals) {
        portals = [NSArray array];
    }
    NSMutableArray * defaultPortal = [NSMutableArray arrayWithArray:portals];
    if (![defaultPortal containsObject:value]) {
        [defaultPortal insertObject:value atIndex:0];
    }else{
        NSString * portal = value;
        [defaultPortal removeObject:value];
        [defaultPortal insertObject:portal atIndex:0];
    }
    [[NSUserDefaults standardUserDefaults] setObject:defaultPortal forKey:PoratlDefaults];
    [[NSUserDefaults standardUserDefaults] synchronize];
}
//根据key获取本地存储的信息
+ (id)getPortalfaultAtIndex:(id)index{
    NSArray * portals = [[NSUserDefaults standardUserDefaults] arrayForKey:PoratlDefaults];
    if (!portals || portals.count == 0) {
        if (index) {
            return @"";
        }
        return @[];
    }else{
        if (index) {
            return portals[[index integerValue]];
        }
    }
    return portals;
}
+ (void)removePortal:(NSString *)value{
    NSArray * portals = [[NSUserDefaults standardUserDefaults] arrayForKey:PoratlDefaults];
    if (!portals) {
        portals = [NSArray array];
    }
    NSMutableArray * defaultPortal = [NSMutableArray arrayWithArray:portals];
    [defaultPortal removeObject:value];
    [[NSUserDefaults standardUserDefaults] setObject:defaultPortal forKey:PoratlDefaults];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
}
//清除本地缓存
+ (void)cleanUserDefaults{
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:PoratlDefaults];
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:UserDefaults];
    [[NSUserDefaults standardUserDefaults] synchronize];
}
@end
