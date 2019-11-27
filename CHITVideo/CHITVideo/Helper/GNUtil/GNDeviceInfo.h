//
//  GNDeviceInfo.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/20.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GNDeviceInfo : NSObject

+ (NSString *)appName ;

+ (NSString *)appVersion ;

+ (NSString *)appBuddleId ;

+ (NSString *)userTerminalType ;

+ (NSString *)terminalBrand ;

+ (NSString *)terminalMode ;

+ (NSString *)terminalOS ;

+ (NSString *)terminalOSType ;

+ (NSString *)systemVersion ;
        
//+ (BOOL )isX ;

@end
