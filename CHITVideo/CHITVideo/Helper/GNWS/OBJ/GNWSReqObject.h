//
//  GNWSReqObject.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/5/28.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GNWSReq.h"

@interface GNWSReqObject : NSObject

//@property (nonatomic,strong)GNWSReq *req;

@property (nonatomic,copy)NSString *req;
@property (nonatomic,strong)NSDate *date;
@property (nonatomic,copy)GNSuccessBlock success;
@property (nonatomic,copy)GNFailBlock fail;

@end
