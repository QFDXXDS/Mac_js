//
//  GNPath.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/4/3.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GNPath : NSObject

+ (NSString *)logPath:(NSString *)globalConferenceID ;

+ (NSString *)logFolder ;

+ (NSString *)zipFolder ;

+ (NSString *)zipPath ;

+ (NSString *)logName ;

@end
