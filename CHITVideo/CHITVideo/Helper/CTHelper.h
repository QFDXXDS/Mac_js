//
//  CTHelper.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/10.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GNProxyConfig.h"

@interface CTHelper : NSObject

/**
解析获得的URL

 @param roomURL <#roomURL description#>
 @return portal和key
 */
+ (NSArray *)confResWithRoomURL:(NSString *)roomURL ;

/**
 framework的资源bundle

 @return <#return value description#>
 */
+ (NSBundle *)bundle ;

/**
 封装HTTP参数

 @param object req请求对象
 @return dictionary
 */
+ (id)wrapperParameters:(id)object ;

/**
 判断对象是否有效

 @param object <#object description#>
 @return <#return value description#>
 */
+ (BOOL)isValid:(id)object ;

+ (BOOL)isInnerSDK ;
/**
 字符串转字典

 @param JSON <#JSON description#>
 @return <#return value description#>
 */
+ (NSDictionary *)toDic:(id )JSON ;
/**
 转JSON字符串
 
 @param object <#object description#>
 @return <#return value description#>
 */
+ (NSString *)toJSONString:(id )object ;


/**
 <#Description#>

 @param req req description
 */
+ (NSString *)WSWrapperReq:(id<GNWSProtocol> )req;

/**
 处理第三方或则二维码读取的链接
 
 @param urlInfo 链接字符串
 @return roomId
 */
+ (NSString *)anonymousInfoWithUrlInfo:(NSString *)urlInfo ;

/**
 获取域名

 @param urlInfo 网页唤醒参数
 @return 域名
 */
+ (NSString *)domainWithUrlInfo:(NSString *)urlInfo ;

/**
 解析网页的openid

 @param webLink 网页唤醒参数
 @return openid
 */
+ (NSString *)getOpenID:(NSString *)webLink ;
/**
 会中邀请
 */
+ (void)inviteContact ;

+ (void)shareInfo:(id)results ;

@end
