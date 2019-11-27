//
//  GNHTTPReq.m
//  WeVideoKit
//
//  Created by Xianxiangdaishu on 2018/1/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNHTTPReq.h"

@implementation GNHTTPReq

- (NSString *)GNHTTPMethod {
    
    return @"POST" ;
}

- (id)GNParameters {
    
    return  [CTHelper wrapperParameters:self];
}
- (NSString *)serviceUrl {

    return @"";
}

@end
