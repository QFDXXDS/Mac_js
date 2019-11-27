//
//  UserManager.h
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2017/9/28.
//  Copyright © 2017年 com.changhongit. VidyoSample. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTUserModal.h"

@interface CTUserManager : NSObject

@property (nonatomic,strong)CTUserModal *model;

+(CTUserManager *)instance;

+ (void)setUpUserModelWithDic:(NSDictionary *)dic ;

+ (NSString *)name ;

+ (NSString *)userid ;

+ (NSString *)token ;

+ (NSString *)org ;

+ (BOOL)isLogin ;

+ (void)loginSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail ;

+ (void)loginOut ;

+ (NSString *)roomNumber ;

@end
