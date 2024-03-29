//
//  GNDeviceInfo.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/20.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNDeviceInfo.h"
//#import <UIKit/UIDevice.h>
#import <sys/utsname.h>

@implementation GNDeviceInfo

+ (NSString *)appName {
    
    return  [ [self infoDic] objectForKey:@"CFBundleName"];
}

+ (NSString *)appVersion {
    
    NSString *s = [NSString stringWithFormat:@"%@_%@",[self appName],[ [self infoDic] objectForKey:@"CFBundleShortVersionString"]] ;
    return s;
}

+ (NSString *)appBuddleId {
    
    return [ [self infoDic] objectForKey:@"CFBundleIdentifier"];
}
+ (NSDictionary *)infoDic {
    
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    return infoDictionary;
}
# pragma mark -获取终端信息

+ (NSString *)userTerminalType {
    
    NSString *s = [self phoneType];
    if ([s hasPrefix:@"iPhone"]) {
        
        return @"mobile";
    } else {
        
        return @"pad";
    }
}
+ (NSString *)terminalOSType {
    
    return @"ios";
}
+ (NSString *)terminalBrand {
    
    return @"apple";
}

+ (NSString *)terminalMode {
    
    return [self phoneType];
}

+ (NSString *)terminalOS {
    
    NSString *s = [NSString stringWithFormat:@"IOS %@",[self systemInfo]] ;
    return s;
}

+ (NSString *)systemInfo {
    
    struct utsname  systemInfo;
    uname(&systemInfo);
    NSString*platform = [NSString stringWithCString: systemInfo.machine encoding:NSASCIIStringEncoding];
    
    return platform;
}
+ (NSString *)phoneType {
    
    NSString *platform = [self systemInfo];
    
    //    if([platform isEqualToString:@"iPhone1,1"])  return @"iPhone 2G";
    
    //    if([platform isEqualToString:@"iPhone1,2"])  return @"iPhone 3G";
    //
    //    if([platform isEqualToString:@"iPhone2,1"])   return@"iPhone 3GS";
    
    if([platform isEqualToString:@"iPhone3,1"])   return@"iPhone 4";
    
    if([platform isEqualToString:@"iPhone3,2"])   return@"iPhone 4";
    
    if([platform isEqualToString:@"iPhone3,3"])  return@"iPhone 4";
    
    if([platform isEqualToString:@"iPhone4,1"])  return@"iPhone 4S";
    
    if([platform isEqualToString:@"iPhone5,1"])  return@"iPhone 5";
    
    if([platform isEqualToString:@"iPhone5,2"])  return@"iPhone 5";
    
    if([platform isEqualToString:@"iPhone5,3"])  return@"iPhone 5c";
    
    if([platform isEqualToString:@"iPhone5,4"])  return@"iPhone 5c";
    
    if([platform isEqualToString:@"iPhone6,1"])  return@"iPhone 5s";
    
    if([platform isEqualToString:@"iPhone6,2"])  return@"iPhone 5s";
    
    if([platform isEqualToString:@"iPhone7,1"])  return@"iPhone 6 Plus";
    
    if([platform isEqualToString:@"iPhone7,2"])  return@"iPhone 6";
    
    if([platform isEqualToString:@"iPhone8,1"])  return@"iPhone 6s";
    
    if([platform isEqualToString:@"iPhone8,2"])  return@"iPhone 6s Plus";
    
    if([platform isEqualToString:@"iPhone8,4"])  return@"iPhone SE";
    
    if([platform isEqualToString:@"iPhone9,1"])  return@"iPhone 7";
    
    if([platform isEqualToString:@"iPhone9,2"])   return@"iPhone 7 Plus";
    
    if([platform isEqualToString:@"iPhone10,1"]) return@"iPhone 8";
    
    if([platform isEqualToString:@"iPhone10,4"]) return@"iPhone 8";
    
    if([platform isEqualToString:@"iPhone10,2"]) return@"iPhone 8 Plus";
    
    if([platform isEqualToString:@"iPhone10,5"]) return@"iPhone 8 Plus";
    
    if([platform isEqualToString:@"iPhone10,3"]) return@"iPhone X";
    
    if([platform isEqualToString:@"iPhone10,6"]) return@"iPhone X";
    
    if([platform isEqualToString:@"iPod1,1"])  return@"iPod Touch 1G";
    
    if([platform isEqualToString:@"iPod2,1"])  return@"iPod Touch 2G";
    
    if([platform isEqualToString:@"iPod3,1"])  return@"iPod Touch 3G";
    
    if([platform isEqualToString:@"iPod4,1"])  return@"iPod Touch 4G";
    
    if([platform isEqualToString:@"iPod5,1"])  return@"iPod Touch 5G";
    
    if([platform isEqualToString:@"iPad1,1"])  return@"iPad 1G";
    
    if([platform isEqualToString:@"iPad2,1"])  return@"iPad 2";
    
    if([platform isEqualToString:@"iPad2,2"])  return@"iPad 2";
    
    if([platform isEqualToString:@"iPad2,3"])  return@"iPad 2";
    
    if([platform isEqualToString:@"iPad2,4"])  return@"iPad 2";
    
    if([platform isEqualToString:@"iPad2,5"])  return@"iPad Mini 1G";
    
    if([platform isEqualToString:@"iPad2,6"])  return@"iPad Mini 1G";
    
    if([platform isEqualToString:@"iPad2,7"])  return@"iPad Mini 1G";
    
    if([platform isEqualToString:@"iPad3,1"])  return@"iPad 3";
    
    if([platform isEqualToString:@"iPad3,2"])  return@"iPad 3";
    
    if([platform isEqualToString:@"iPad3,3"])  return@"iPad 3";
    
    if([platform isEqualToString:@"iPad3,4"])  return@"iPad 4";
    
    if([platform isEqualToString:@"iPad3,5"])  return@"iPad 4";
    
    if([platform isEqualToString:@"iPad3,6"])  return@"iPad 4";
    
    if([platform isEqualToString:@"iPad4,1"])  return@"iPad Air";
    
    if([platform isEqualToString:@"iPad4,2"])  return@"iPad Air";
    
    if([platform isEqualToString:@"iPad4,3"])  return@"iPad Air";
    
    if([platform isEqualToString:@"iPad4,4"])  return@"iPad Mini 2G";
    
    if([platform isEqualToString:@"iPad4,5"])  return@"iPad Mini 2G";
    
    if([platform isEqualToString:@"iPad4,6"])  return@"iPad Mini 2G";
    
    if([platform isEqualToString:@"iPad4,7"])  return@"iPad Mini 3";
    
    if([platform isEqualToString:@"iPad4,8"])  return@"iPad Mini 3";
    
    if([platform isEqualToString:@"iPad4,9"])  return@"iPad Mini 3";
    
    if([platform isEqualToString:@"iPad5,1"])  return@"iPad Mini 4";
    
    if([platform isEqualToString:@"iPad5,2"])  return@"iPad Mini 4";
    
    if([platform isEqualToString:@"iPad5,3"])  return@"iPad Air 2";
    
    if([platform isEqualToString:@"iPad5,4"])  return@"iPad Air 2";
    
    if([platform isEqualToString:@"iPad6,3"])  return@"iPad Pro 9.7";
    
    if([platform isEqualToString:@"iPad6,4"])  return@"iPad Pro 9.7";
    
    if([platform isEqualToString:@"iPad6,7"])  return@"iPad Pro 12.9";
    
    if([platform isEqualToString:@"iPad6,8"])  return@"iPad Pro 12.9";
    
    //    if([platform isEqualToString:@"i386"])  return@"iPhone Simulator";
    
    //    if([platform isEqualToString:@"x86_64"])  return@"iPhone Simulator";
    
    return platform;
    
}
+ (NSString *)systemVersion {
    
    return @"" ;
}
//+ (BOOL )isX {
//    
//    if (CT_SCREEN_H == 812) {
//        
//        return YES;
//    }
//    return NO ;
//}
@end
