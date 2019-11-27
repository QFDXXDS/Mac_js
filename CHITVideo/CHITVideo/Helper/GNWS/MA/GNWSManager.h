//
//  GNWSManager.h
//  GN-OC
//
//  Created by Xianxiangdaishu on 2018/1/15.
//  Copyright © 2018年 XXDS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "GNBlockConfig.h"
#import "GNProxyConfig.h"

@interface GNWSManager : NSObject

+ (instancetype)shareInstance ;

+ (void)sendReq:(id <GNWSProtocol> )req success:(GNSuccessBlock )success fail:(GNFailBlock )fail;

+ (void)sendLink:(NSString *)WSURLString ;

+ (void)close ;

@end
