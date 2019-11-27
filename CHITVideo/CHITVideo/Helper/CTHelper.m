//
//  CTHelper.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/10.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CTHelper.h"
#import <objc/runtime.h>
#import "GNDeviceInfo.h"
#import "GNDate.h"
#import "GNPath.h"
#import "GNHTTPReq.h"

#import "GNWSReq.h"


static  int transId = 0 ;

@implementation CTHelper


+ (NSArray *)confResWithRoomURL:(NSString *)roomURL {
    
    NSMutableArray *tempArray = [NSMutableArray new];
    NSArray *confArray = [roomURL componentsSeparatedByString:@"&key="];
    NSString *confURL = confArray[0];
    NSString *confKey = confArray[1];
    
    NSArray *URLArray = [confURL componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"/"]];
    confURL = URLArray[2];
    
    [tempArray addObject:confURL];
    [tempArray addObject:confKey];
    
    return [tempArray copy];
}
+ (NSBundle *)bundle {
    
    NSBundle * refreshBundle = nil ;
   

//#if ChitVideoDynamic
//    refreshBundle = [NSBundle bundleForClass:[CTHelper class]];
//#else
    refreshBundle = [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"CHITVideoBundle" ofType:@"bundle"]];

//#endif
    return refreshBundle ;
}
+ (id)wrapperParameters:(id)object {
    
    NSMutableDictionary *temp = [NSMutableDictionary new];
    
    [self assemblaWithDic:temp object:object class:[object class]];
    
    if (![[object superclass] isKindOfClass:[GNHTTPReq class]]){
        
        [self assemblaWithDic:temp object:object class:[object superclass]];
    }
    return temp;
}
+ (void)assemblaWithDic:(NSMutableDictionary *)dic object:(id)object class:(Class ) cls{
    
    unsigned int count = 0;

    Ivar *ivar = class_copyIvarList(cls, &count);
    
    for (int i = 0; i< count; i++) {
        
        Ivar iv = ivar[i];
        const char *c = ivar_getName(iv);
        NSString *key = [[NSString stringWithCString:c encoding:NSUTF8StringEncoding] substringFromIndex:1] ;

        id value = [object valueForKey:key];
        if (value) {
            
            [dic setObject:value forKey:key];
        }
    }
    free(ivar);
    
}
+ (BOOL)isValid:(id)object {
    
    if (object && ![object isKindOfClass:[NSNull class]]) {
        
        return YES;
    }
    return NO;
}
+ (BOOL)isInnerSDK {
    
    
    return  [[GNDeviceInfo appBuddleId] isEqualToString:CT_JISHI_BUNDLE_ID] && CT_ConfStatus.isLogin ;
}


+ (NSDictionary *)toDic:(id )JSON {
    
    NSDictionary *dic = nil;
    if ([CTHelper isValid:JSON]) {
    
        if ([JSON isKindOfClass:[NSString class]]) {
            
            NSData *data = [JSON dataUsingEncoding:NSUTF8StringEncoding];
            dic = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        }
        if ([JSON isKindOfClass:[NSDictionary class]]) {
            
            dic = JSON;
        }
    }
    return dic;
}

+ (NSString *)toJSONString:(id )object {
    
    NSData *data = [NSJSONSerialization dataWithJSONObject:object options:0 error:nil];
    NSString *s = [[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];
    return s;
}
+ (NSString *)WSWrapperReq:(id <GNWSProtocol >)req  {
    
//    NSMutableDictionary *json = [NSMutableDictionary new] ;
//    NSMutableDictionary *body = [self changeToJson:[req class] object:req];
//
//    [json setObject:body forKey:@"body"];
//
//    NSString *token = [GNDefault objectForKey:CT_TOKEN] ;
//
//    if (![[req opt] isEqual: @"1_1"]) {
//
//        if (token)   [json setObject:token forKey:@"token"] ;
//    }
//    [json setObject:[req opt] forKey:@"opt"];
//    [json setObject:@(seqCount++) forKey:@"seq"];

    
    NSMutableDictionary *temp = [NSMutableDictionary new];
    NSMutableDictionary *json = [NSMutableDictionary new] ;
    
    NSMutableDictionary *value = [self changeToJson:[req class] object:req temp:temp];
    [value setObject:@(transId++) forKey:@"transId"];
    

    [json setObject:value forKey:@"value"];
    [json setObject:[req name] forKey:@"name"];
    
    return [self toJSONString:json];
}
+ (NSMutableDictionary *)changeToJson:(id )cls object:(id)object temp:(NSMutableDictionary *)temp {
    
    
    unsigned int count = 0;
    Ivar *ivar = class_copyIvarList(cls, &count);
    for (int i = 0; i< count; i++) {
        
        Ivar iv = ivar[i];
        const char *c = ivar_getName(iv);
        
        NSString *key = [[NSString stringWithCString:c encoding:NSUTF8StringEncoding] substringFromIndex:1] ;
        id value = [object valueForKey:key];
        
        if (!value) {
            continue;
        }
        [temp setObject:value forKey:key];
        
    }
    free(ivar);
    
    NSString *className = NSStringFromClass([cls superclass]) ;
    if (![className isEqualToString:@"GNWSReq"]) {
        
        [self changeToJson:[cls superclass] object:object temp:temp];
    }
    return temp;
}
+ (NSString *)anonymousInfoWithUrlInfo:(NSString *)urlInfo {
//http://imtest.byshang.cn/#/roomDirect/room5b767582-0c5a-4b22-969c-6028d7f77831/46252
    NSArray *array = nil ;
    if ([urlInfo containsString:@"?"]) {
        
        array = [urlInfo componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"/?"]];
    } else {
        array = [urlInfo componentsSeparatedByString:@"/"];
    }
    NSInteger count = array.count ;
    return array[count-2];
}
+ (NSString *)domainWithUrlInfo:(NSString *)urlInfo {
    
    NSArray *array = [urlInfo componentsSeparatedByString:@"/#/"];
    NSString *s = array[0] ;
    if (![s containsString:@":"]) {
        
        s = [s stringByReplacingOccurrencesOfString:@"http" withString:@"http:"] ;
    }
    return s ;
}
+ (NSString *)getOpenID:(NSString *)webLink {
    
    //    "ucstar://qirJoinConference?ConferenceLink=http://localhost:3000/#/roomDirect/roomf0a17f2b-7793-4ede-bb59-9d7154d96cb5?roomNumber=46202982&openId=KwSZpcAJN6GcWapMPzeKWidBjH2iaRmC"
    
    NSArray *temp = [webLink componentsSeparatedByString:@"&openId="];
    return temp.lastObject ;
}

+ (void)inviteContact {
    
    id obj = [GNDefault objectForKey:CT_CONF_JSON];
    [[NSNotificationCenter defaultCenter] postNotificationName:ChitVideoInviteContactNotification object:obj];
}

+ (void)shareInfo:(id)results {
    
    
    GNLog(@"shareInfo is %@",results) ;
    NSString *appInvokerPageURL = results[@"appInvokerPageURL"];
     NSString *cellphoneDialInURL = results[@"cellphoneDialInURL"];
     NSString *downloadURL = results[@"downloadURL"];
     NSString *h323DialInURL = results[@"h323DialInURL"];
     NSString *ownerName = results[@"ownerName"];
     NSString *roomName = results[@"roomName"];
     NSString *roomNum = results[@"roomNum"];
    
    NSString *roomPIN = results[@"roomPIN"];
    if (![CTHelper isValid:roomPIN]) {
        
        roomPIN = @"暂无" ;
    }
    
    NSString *sipDialInURL = results[@"sipDialInURL"];
    NSString *telephoneDialInURL = results[@"telephoneDialInURL"];
    
    
    NSString *title = [NSString stringWithFormat:@"%@邀请您参加%@",ownerName,roomName];
    NSString *content = @"您有如下入会方式：";
    NSString *content1 = @"软件客户端入会";
    NSString *link = [NSString stringWithFormat:@"参会链接：%@",appInvokerPageURL];
    NSString *roomNumber = [NSString stringWithFormat:@"搜索会议号：%@",roomNum];
    
    NSString *PWD = [[appInvokerPageURL componentsSeparatedByString:@"***"] lastObject];
    NSString *rumPWD = [NSString stringWithFormat:@"会议密码：%@",PWD];
    


//    NSString *shareInfo = [NSString stringWithFormat:@"%@\n会议号：%@\n会议密码：%@\n电话呼叫串：%@\n手机呼叫串：%@->%@\nH323呼叫串：%@\nSIP呼叫串：%@\n会议链接：%@",roomName,roomNum,roomPIN,telephoneDialInURL,cellphoneDialInURL,telephoneDialInURL,h323DialInURL,sipDialInURL,appInvokerPageURL];
    
    
    NSString *shareInfo = [NSString stringWithFormat:@"%@\n\n%@\n\n%@\n%@\n\n%@\n\n%@",title,content,content1,link,roomNumber,rumPWD];

    
    NSPasteboard *pb = [NSPasteboard generalPasteboard];
    [pb setString:shareInfo forType:NSPasteboardTypeString];
    
    
    
}
@end
