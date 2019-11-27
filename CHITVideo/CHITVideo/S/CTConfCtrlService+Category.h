//
//  CTConfCtrlService+Category.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/7/9.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CTConfCtrlService.h"

@interface CTConfCtrlService (Category)

+ (void)confMode:(NSString *)mode ;

+ (void)pinWithURI:(NSString *)participantURI limit:(int)limit mode:(BOOL)mode preview:(BOOL)show ;


@end
