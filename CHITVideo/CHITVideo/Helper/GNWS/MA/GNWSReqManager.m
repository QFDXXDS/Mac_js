//
//  GNWSReqManager.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/5/28.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNWSReqManager.h"
#import "GNWSReqObject.h"
#import "GNError.h"
#define RSP_INTERVAL  5

static GNWSReqManager *ma= nil ;

@interface GNWSReqManager()

@property (nonatomic,strong)NSMutableDictionary *reqDic;  //存入所有请求

@end

@implementation GNWSReqManager


- (NSMutableDictionary *)reqDic {
    
    if (!_reqDic) {
        
        _reqDic = [NSMutableDictionary new];
    }
    return _reqDic;
}

+ (instancetype)shareInstance {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
        ma = [[GNWSReqManager alloc]init];
    });
    return ma ;
}
+ (void)req:(NSString *)req success:(GNSuccessBlock )success fail:(GNFailBlock )fail {
    
    [self shareInstance];
    if (!success || !fail)  return ;
    
    GNWSReqObject *object = [[GNWSReqObject alloc]init];
    object.req = req;
    object.success = success ;
    object.fail = fail;
    object.date = [NSDate new];
    
    NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:[req dataUsingEncoding:NSUTF8StringEncoding] options:0 error:nil];
    NSDictionary *value = dic[CT_WS_VALUE] ;
    NSString *key = [NSString stringWithFormat:@"%@",value[CT_WS_TRANSTD]];
    
    [ma.reqDic setObject:object forKey:key];
}
+ (void)detectReqObject {
    
    [GNWSReqManager shareInstance];
    if (ma.reqDic.count == 0) return ;
    [ma.reqDic enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
        
        GNWSReqObject *object = obj;
        NSDate *date = object.date;
        NSTimeInterval interval = [date timeIntervalSinceNow];
        if (fabs(interval) > RSP_INTERVAL) {
            
            object.fail?object.fail([GNError WSTimeoutError]):nil;
            [ma.reqDic removeObjectForKey:key];
            [[NSNotificationCenter defaultCenter]postNotificationName:GNWSResponseTimeoutNotification object:nil];

            *stop = YES ;
        }
    }];
}
+ (void)responseObject:(NSDictionary *)dic {
    
    NSDictionary *value = dic[CT_WS_VALUE] ;
    NSString *key = [NSString stringWithFormat:@"%@",value[CT_WS_TRANSTD]];
    GNWSReqObject *object = [ma.reqDic objectForKey:key];
    
    if(object ) {

        NSString *returnValue = value[CT_WS_RETURNVALUE];
        if ([returnValue isEqualToString:@"OK"] ) {

            object.success?object.success(value):nil;
        } else {

            NSError *error = [GNError WSRspError:value];
            object.fail ? object.fail(error) : nil;
        }
        [ma.reqDic removeObjectForKey:key];
    }
}
+ (void)clear {
    
    [self shareInstance];
    if (ma.reqDic.count == 0) return ;
    [ma.reqDic removeAllObjects];
}

@end
