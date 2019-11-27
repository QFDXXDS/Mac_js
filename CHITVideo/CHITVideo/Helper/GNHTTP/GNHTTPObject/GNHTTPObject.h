//
//  GNHTTPRequest.h
//  WeVideoKit
//
//  Created by Xianxiangdaishu on 2018/1/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking.h"


@interface GNHTTPObject : NSObject

@property (nonatomic,strong)AFHTTPSessionManager *AFManager;

+ (instancetype )sharedInstance ;


@end
