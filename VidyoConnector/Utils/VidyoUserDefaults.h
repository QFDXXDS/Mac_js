//
//  VidyoUserDefaults.h
//  VidyoSample
//
//  Created by user on 16/12/30.
//  Copyright © 2016年 com.changhongit. VidyoSample. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VidyoUserDefaults : NSObject
+(void)setDefault:(NSString *)key value:(id)value;
+ (id)getDefault:(NSString *)key;
//本地存储信息
+ (void)setUserDefault:(NSString *)key value:(id)value;
//本地存储portal
+ (void)setPortalDefault:(NSString *)value;
//根据key获取本地存储的信息
+ (id)getUserDefault:(NSString *)key;
//获取portal本地存储的信息
+ (id)getPortalfaultAtIndex:(id)index;
//清楚本地缓存
+ (void)cleanUserDefaults;
+ (void)removePortal:(NSString *)value;
@end
