//
//  GNRegex.h
//  GN-OC
//
//  Created by Xianxiangdaishu on 2018/2/6.
//  Copyright © 2018年 XXDS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GNRegex : NSObject

+ (BOOL)isMobile:(NSString *)mobile ;

+ (BOOL)isValidUrlStr:(NSString *)urlStr ;

+ (BOOL)isNumber:(NSString *)string ;


/**
 判断对象是否有效
 
 @param object <#object description#>
 @return <#return value description#>
 */
+ (BOOL)isValid:(id)object ;

@end
