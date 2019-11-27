//
//  GNHTTPWapper.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/22.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GNHTTPWapper : NSObject

+ (NSString *)wapperWithReq:(id <GNHTTPProtocol > ) req  ;
@end
