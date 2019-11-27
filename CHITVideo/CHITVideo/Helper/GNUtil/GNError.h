//
//  GNError.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/5/28.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GNError : NSObject

+ (NSError *)WSRspError:(NSDictionary *)dic ;

+ (NSError *)WSTimeoutError ;

+ (NSError *)WSLinkError ;


@end
