//
//  GNHTTPManager.h
//  WeVideoKit
//
//  Created by Xianxiangdaishu on 2018/1/5.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GNBlockConfig.h"
#import "GNProxyConfig.h"

@interface GNHTTPManager : NSObject

+ (void)req:(id <GNHTTPProtocol>)req
    success:(GNSuccessBlock )success
       fail:(GNFailBlock)fail ;

+ (void)upload:(id <GNHTTPProtocol>)req
       zapPath:(NSString *)zipPath
       success:(GNSuccessBlock )success
          fail:(GNFailBlock)fail ;

@end
