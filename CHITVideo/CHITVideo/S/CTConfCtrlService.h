//
//  CTConfCtrlService.h
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2018/1/20.
//  Copyright © 2018年 com.changhongit. VidyoSample. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CTConfCtrlService : NSObject

+ (void)addNotification ;

+ (void)uploadURI ;

+ (void)ConfDetail:(NSDictionary *)dic ;

+ (BOOL)isLecture ;

+ (BOOL)isCalledName ;

@end
