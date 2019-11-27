
//
//  GNProxyConfig.h
//  WeVideoKit
//
//  Created by Xianxiangdaishu on 2018/1/5.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#ifndef GNProxyConfig_h
#define GNProxyConfig_h

@protocol GNHTTPProtocol <NSObject>

- (NSString *)GNHTTPMethod ;

- (id )GNParameters ;

- (NSString *)serviceUrl ;

@end

@protocol GNWSProtocol <NSObject>

- (NSString *)opt ;

- (NSString *)name ;

@end


#endif /* GNProxyConfig_h */
