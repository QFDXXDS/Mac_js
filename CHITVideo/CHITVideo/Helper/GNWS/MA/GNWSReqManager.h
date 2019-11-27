//
//  GNWSReqManager.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/5/28.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GNWSReqManager : NSObject


+ (void)req:(NSString *)req success:(GNSuccessBlock )success fail:(GNFailBlock )fail ;

+ (void)detectReqObject;

+ (void)responseObject:(NSDictionary *)dic ;

+ (void)clear ;
@end
