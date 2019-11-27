//
//  CTWSManager.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/5/11.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CTWSManager : NSObject

+ (instancetype)shareInstance ;

+ (void)sendLink:(GNSuccessBlock) success ;

@end
