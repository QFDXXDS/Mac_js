//
//  UserModal.m
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2017/9/28.
//  Copyright © 2017年 com.changhongit. VidyoSample. All rights reserved.
//

#import "CTUserModal.h"

@implementation CTUserModal


- (NSString *)name {
    
    
    return  _lastName.length > 0 ? [_lastName stringByAppendingString: _firstName] : _firstName ;
}
@end
