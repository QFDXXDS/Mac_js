//
//  GNWSReq.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/2/2.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNWSReq.h"

@implementation GNWSReq


- (NSString *)name {
    
    NSString *name = NSStringFromClass(self.class);
    return  [name substringFromIndex:4] ;
}

@end

//@implementation GNWSHeartReq
//
//
//@end


@implementation CHITKeepAliveRequest


@end
