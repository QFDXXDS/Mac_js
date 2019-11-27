//
//  GNPath.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/4/3.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNPath.h"
#import "GNDeviceInfo.h"
#import "GNDate.h"

@implementation GNPath

+ (NSString *)documentsPath {
    
    NSString *path = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject] ;
    return path;
}

+ (NSString *)logPath:(NSString *)globalConferenceID {
    
    NSString *logFolder = [self logFolder];
    NSString *logFilePath = [NSString stringWithFormat:@"%@/%@.log",logFolder,globalConferenceID];

    NSFileManager *ma = [NSFileManager defaultManager];
    
    if (![ma fileExistsAtPath:logFilePath]) {
        [ma createFileAtPath:logFilePath contents:nil attributes:nil];
    }
    return logFilePath;
}

+ (NSString *)logFolder {
    
    NSString *logFolder = [NSString stringWithFormat:@"%@/ChitVideo",[self documentsPath]];
    NSFileManager *ma = [NSFileManager defaultManager];
    
    if(![ma fileExistsAtPath:logFolder]){
        [ma createDirectoryAtPath:logFolder withIntermediateDirectories:YES attributes:nil error:nil];
    }
    return logFolder;
}

+ (NSString *)zipFolder {
    
    NSString *zipFolder = [NSString stringWithFormat:@"%@/ChitVideoZip",[self documentsPath]];
    NSFileManager *ma = [NSFileManager defaultManager];
    
    if(![ma fileExistsAtPath:zipFolder]){
        [ma createDirectoryAtPath:zipFolder withIntermediateDirectories:YES attributes:nil error:nil];
    }
    return zipFolder;
}

+ (NSString *)zipPath {
    
    NSString *zipFolder = [self zipFolder];
    NSString * zipPath = [NSString stringWithFormat:@"%@/ChitVideo.zip",zipFolder];
    
    return zipPath;
}

+ (NSString *)logName {
    
    NSString *disPlayname = [GNDefault objectForKey:CT_DISPLAYNAME] ;
    NSString *version = [GNDeviceInfo appVersion];
    NSString *logName = [NSString stringWithFormat:@"iOS_%@_%@_",disPlayname,version];
    return logName;
}


@end
