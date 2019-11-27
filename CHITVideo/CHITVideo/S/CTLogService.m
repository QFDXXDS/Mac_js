//
//  CTLogService.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/4/3.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CTLogService.h"
#import "GNPath.h"
#import "GNDate.h"
#import "CTService.h"


@implementation CTLogService
{
    NSString *logPath ;
    NSArray * fileArray;
    NSFileHandle *fileHandle ;
}
+ (instancetype)sharedInstance {
    
    static CTLogService *s = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        s = [[CTLogService alloc]init];
    });
    return s;
}

+ (void)LOG {
    
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        
        [CTService uploadLogSuccess:nil fail:nil] ;
    
        NSString *globalConferenceID = [GNDefault objectForKey:CT_GLOBAL_CONFERENCEID];
        CTLogService *s = [self sharedInstance];
        
        NSString *fileName = [NSString stringWithFormat:@"%@_%@",[GNDate currentTime],globalConferenceID];
        s->logPath = [GNPath logPath:fileName];
        s->fileHandle = [NSFileHandle fileHandleForWritingAtPath:s->logPath];
    });
}
+ (void)receiveLog:(NSString * )log {
    
    if(CT_ConfStatus.didInterSDKBool){
        
        CTLogService *s = [self sharedInstance];
        log = [log stringByAppendingString:@"\n"];
        [s->fileHandle seekToEndOfFile];
        [s->fileHandle writeData:[log dataUsingEncoding:NSUTF8StringEncoding]];
    }
}
+ (void)receiveLocalLog:(id )log {
    
    NSString *LOGString = @"" ;
    if ([log isKindOfClass:[NSDictionary class]]) {
        
        LOGString = [CTHelper toJSONString:log];
    } else {
        LOGString = log;
    }
    LOGString = [NSString stringWithFormat:@"%@--%@",[GNDate currentTime],LOGString];
    [self receiveLog:LOGString];
}
+ (NSString *)logPath {
    
    CTLogService *s = [self sharedInstance];
    return s->logPath;
}
+ (NSArray *)fileArray {
    
    CTLogService *s = [self sharedInstance];
    NSFileManager *ma = [NSFileManager defaultManager];
    s->fileArray = [ma contentsOfDirectoryAtPath:[GNPath logFolder] error:nil];

    return s->fileArray;
}
+ (void)removeFile {
    
    CTLogService *s = [self sharedInstance];
    NSArray *fileArray = s->fileArray ;

    NSFileManager *ma = [NSFileManager defaultManager];
    for (NSString *fileName in fileArray) {
        
        NSString *logfilePath = [NSString stringWithFormat:@"%@/%@",[GNPath logFolder],fileName];
        [ma removeItemAtPath:logfilePath error:nil];
    }
}
@end
