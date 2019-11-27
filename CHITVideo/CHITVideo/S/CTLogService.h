//
//  CTLogService.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/4/3.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CTLogService : NSObject

+ (void)LOG ;

+ (void)receiveLog:(NSString *)log ;

+ (void)receiveLocalLog:(id )log ;

+ (NSString *)logPath ;

+ (NSArray *)fileArray ;

+ (void)removeFile ;

@end
