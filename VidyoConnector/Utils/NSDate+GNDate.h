//
//  NSDate+GNDate.h
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2018/9/11.
//  Copyright © 2018年 com.changhongit. VidyoSample. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (GNDate)

+ (NSString *)ly_currentDateString;
    
+ (NSString *)ly_displayTimeWithDate:(NSString *)dateString;
    
+ (NSDate *)ly_dateWithLyDateFormatString:(NSString *)dateString;
    
+ (NSString *)ly_callLogDetailDay:(NSString *)dayString; //2016-08-29
+ (NSString *)ly_callLogDetailTime:(NSString *)timeString; //12:12:31
    
+ (NSString *)ly_displayLogTimeWithDate:(NSDate *)date;
    
+ (NSDate *)ly_dateWithTime:(UInt64)time;
    
+ (NSString *)logDate:(NSDate *)date;
    
+ (NSString *)ly_displayTimeWithTime:(UInt64)time;
    
+ (NSString *)ly_displayDetailTimeWithTime:(UInt64)time;
    
+ (NSString *)ly_confLogDisplayTime:(UInt64)time;


+ (NSString *)ly_confTime ;

@end
