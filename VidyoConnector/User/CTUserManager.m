//
//  UserManager.m
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2017/9/28.
//  Copyright © 2017年 com.changhongit. VidyoSample. All rights reserved.
//

#import "CTUserManager.h"


//#define  CHIT_HTTP_BASEURL @"http://cossdev.byshang.cn:7010/jc-"

static CTUserManager * _userManager = nil;

@interface CTUserManager ()

@property (nonatomic,assign)BOOL isLogin;

@end

@implementation CTUserManager


+(CTUserManager *)instance{
    static dispatch_once_t token;
    dispatch_once(&token, ^{
        _userManager = [[self alloc] init];
        
    });
    return _userManager;
}


+ (void)setUpUserModelWithDic:(NSDictionary *)dic {
    [self instance];
    NSError *err ;
    _userManager.model = [[CTUserModal alloc]initWithDictionary:dic[@"loginUser"] error:&err];
    _userManager.model.token = dic[@"userToken"];
    
    [CHITService setUserInfoWithCossUrl:[VidyoUserDefaults getDefault:PORTAL_DOMAIN] cossPort:@"7010" userId:_userManager.model.userId userToken:_userManager.model.token displayName:_userManager.model.name];
    
//    [CHITService setUserInfoWithCossUrl: cossPort:@"7010" userToken:_userManager.model.token displayName:_userManager.model.name];

    _userManager.isLogin = YES;
    
    
}

+ (NSString *)token {

    return _userManager.model.token;
}
+ (NSString *)name {
    
    return  _userManager.model.name ;
}
+ (NSString *)userid {
    
    return _userManager.model.userId;
}
+ (NSString *)org {

//    OrgModel *org = _userManager.model.organization[0];
    
    return @"" ;
}
+ (NSString *)roomNumber
{
    NSDictionary *virtualRoom = _userManager.model.virtualRooms[0];
    return  virtualRoom[@"roomNumber"];
}
+ (BOOL)isLogin {

    [CTUserManager instance];
    return _userManager.isLogin;
}

+ (void)loginSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail {
    
    [self instance];

    NSString *userName = [VidyoUserDefaults getUserDefault:@"userName"] ;
    NSString *userPassword = [VidyoUserDefaults getUserDefault:@"userPassword"] ;
    
    [CHITService loginWithLoginName:userName password:userPassword tenant:@"chit" success:^(id results) {
        
        [self setUpUserModelWithDic:results];
        [CHITService WSLink:nil];
        
        success ? success(results) : nil;

        [[NSNotificationCenter defaultCenter]postNotificationName:CHITDidLoginSuccessNotification object:nil];

        
    } fail:^(NSError *error) {
        
       fail ? fail(error) : nil ;
    }] ;
}

+ (void)loginOut {
    
    _userManager.isLogin = NO ;
}

@end
