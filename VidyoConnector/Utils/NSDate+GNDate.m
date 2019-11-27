//
//  NSDate+GNDate.m
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2018/9/11.
//  Copyright © 2018年 com.changhongit. VidyoSample. All rights reserved.
//

#import "NSDate+GNDate.h"

static NSDateFormatter *dayFormatter;
static NSDateFormatter *defaultFormatter;

static NSDateFormatter *confFormatter;

static NSDateFormatter *tempFormatter;

@implementation NSDate (GNDate)
+ (NSString *)ly_currentDateString {
    NSDate *date = [NSDate date];
    NSDateFormatter *formatter = [self ly_defaultFormatter];
    return [formatter stringFromDate:date];
}
    
+ (NSString *)logDate:(NSDate *)date {
    NSDateFormatter *formatter = [self ly_defaultFormatter];
    return [formatter stringFromDate:date];
}
    
+ (NSString *)ly_displayTimeWithDate:(NSString *)dateString {
    NSDateFormatter *f = [self ly_defaultFormatter];
    
    NSDate *theDate = [f dateFromString:dateString];
    NSDate *currentDate = [NSDate date];
    
    NSDateFormatter *dayf = [self ly_dayFormatter];
    
    
    NSString *theDay = [dayf stringFromDate:theDate];
    NSString *currentDay = [dayf stringFromDate:currentDate];
    
    
    NSTimeInterval interval = [currentDate timeIntervalSinceDate:theDate];
    
    NSString *result;
    if (interval < 60) {
        result = [NSString stringWithFormat:@"1分钟内"];
    } else if (interval < 3600) {
        result = [NSString stringWithFormat:@"%.f分钟前", interval/60];
    } else if ([theDay isEqualToString:currentDay]) {
        NSDateFormatter *tempf = [self ly_tempFormatter];
        [tempf setDateFormat:@"aa hh:mm"];
        result = [NSString stringWithFormat:@"%@", [tempf stringFromDate:theDate]];
    } else {
        NSDateFormatter *tempf = [self ly_tempFormatter];
        [tempf setDateFormat:@"MM/dd"];
        result = [tempf stringFromDate:theDate];
    }
    return result;
}
    
+ (NSDate *)ly_dateWithLyDateFormatString:(NSString *)dateString {
    NSDateFormatter *f = [self ly_defaultFormatter];
    
    NSDate *theDate = [f dateFromString:dateString];
    return theDate;
}
    
+ (NSDateFormatter *)ly_defaultFormatter {
    if (!defaultFormatter) {
        defaultFormatter = [self ly_dateFormatter];
        defaultFormatter.dateFormat = @"yyyy-MM-dd HH:mm:ss";
    }
    return defaultFormatter;
}
    
+ (NSDateFormatter *)ly_dayFormatter {
    if (!dayFormatter) {
        dayFormatter = [self ly_dateFormatter];
        dayFormatter.dateFormat = @"yyyy-MM-dd";
    }
    return dayFormatter;
}
    
    //临时的
+ (NSDateFormatter *)ly_tempFormatter {
    if (!tempFormatter) {
        tempFormatter = [self ly_dateFormatter];
    }
    return tempFormatter;
}

+ (NSDateFormatter *)ly_confFormatter {
    if (!confFormatter) {
        confFormatter = [[NSDateFormatter alloc]init];
        confFormatter.dateFormat = @"hh时mm分ss秒" ;
    }
    return confFormatter;
}

+ (NSDateFormatter *)ly_dateFormatter {
    NSDateFormatter *f = [[NSDateFormatter alloc] init];
    f.AMSymbol = @"上午";
    f.PMSymbol = @"下午";
    f.timeZone = [NSTimeZone localTimeZone];
    return f;
}
    
    
+ (NSString *)ly_callLogDetailDay:(NSString *)dayString {
    NSDate *currentDate = [NSDate date];
    NSDateFormatter *dayf = [self ly_dayFormatter];
    
    NSString *currentDay = [dayf stringFromDate:currentDate];
    
    if ([dayString isEqualToString:currentDay]) {
        return @"今天";
    } else {
        return dayString;
    }
}
    
+ (NSString *)ly_callLogDetailTime:(NSString *)timeString {
    NSDateFormatter *f = [self ly_dateFormatter];
    [f setDateFormat:@"HH:mm:ss"];
    NSDate *date = [f dateFromString:timeString];
    
    NSDateFormatter *tempf = [self ly_tempFormatter];
    [tempf setDateFormat:@"aa hh:mm"];
    return [tempf stringFromDate:date];
}
    
+ (NSDate *)ly_dateWithTime:(UInt64)time {
    time += (5*60+43)*1000;
    
    NSDate *date2017 = [NSDate ly_dateWithLyDateFormatString:@"1900-01-01 00:00:00.000"];
    
    UInt64 interval = time / 1000;
    NSDate *date = [NSDate dateWithTimeInterval:interval sinceDate:date2017];
    
    UInt64 haomiao = time % 1000;
    
    NSDateFormatter *f = [[NSDateFormatter alloc] init];
    f.timeZone = [NSTimeZone localTimeZone];
    f.dateFormat = @"yyyy-MM-dd HH:mm:ss";
    
    NSDate *timeDate = [NSDate ly_dateWithLyDateFormatString:[NSString stringWithFormat:@"%@.%@", [f stringFromDate:date], @(haomiao)]];
    
    
    
    return timeDate;
}
    
+ (NSString *)ly_displayLogTimeWithDate:(NSDate *)date {
    NSCalendar *calender = [NSCalendar currentCalendar];
    calender.timeZone = [NSTimeZone localTimeZone];
    
    if ([calender isDateInToday:date]) {
        NSDateFormatter *f = [self ly_dateFormatter];
        f.dateFormat = @"HH:mm";
        
        NSString *time = [f stringFromDate:date];
        NSString *hourStr = [time substringToIndex:2];
        NSString *minStr = [time substringFromIndex:3];
        int hour = [hourStr intValue];
        
        NSString *prefix;
        if (hour >= 0 && hour <= 4) {
            prefix = @"凌晨";
        } else if (hour >= 5 && hour <= 11) {
            prefix = @"上午";
        } else if (hour == 12) {
            prefix = @"中午";
        } else if (hour >= 13 && hour <= 18) {
            hour -= 12;
            prefix = @"下午";
        } else if (hour >= 19 && hour <= 23) {
            prefix = @"晚上";
            hour -= 12;
        }
        
        NSString *result = [NSString stringWithFormat:@"%@ %02d:%@", prefix, hour, minStr];
        
        return result;
    } else if ([calender isDateInYesterday:date]) {
        return @"昨天";
    } else {
        NSDateFormatter *f = [self ly_dateFormatter];
        f.dateFormat = @"M月d日";
        return [f stringFromDate:date];
    }
}
    
+ (NSString *)ly_displayTimeWithTime:(UInt64)time{
    
    NSDate *date = [self ly_dateWithTime:time];
    NSString *dateString = [self ly_displayLogTimeWithDate:date];
    
    
    //    NSString *displayTime = [self ly_displayTimeWithDate:dateString];
    
    //    NSString *displayTime = [self ly_displayTimeWithDate:dateString];
    
    return dateString;
    
}
+ (NSString *)ly_displayDetailTimeWithTime:(UInt64)time{
    NSDate *date = [self ly_dateWithTime:time];
    
    NSDateFormatter *f = [self ly_defaultFormatter];
    
    return [f stringFromDate:date];
}
+ (NSString *)ly_confLogDisplayTime:(UInt64)time{
    NSDate *date = [self ly_dateWithTime:time];
    NSDate *date1 = [[NSDate alloc]init];
    
    int unitYear = NSCalendarUnitYear;
    NSCalendar *calender = [NSCalendar currentCalendar];
    NSDateComponents *newCmps = [calender components:unitYear fromDate:date];
    NSDateComponents *selfCmps = [calender components:unitYear fromDate:date1];
    NSDateFormatter *f = [[NSDateFormatter alloc]init];
    NSString *str ;
    
    if (newCmps.year == selfCmps.year) {
        f.dateFormat = @"M月d日 HH:mm:ss";
        str = [f stringFromDate:date];
        
    }else{
        f.dateFormat = @"yyyy-MM-dd HH:mm:ss";
        str = [f stringFromDate:date];
    }
    return str;
}

+ (NSString *)ly_confTime{
    
    NSDate *date = [[NSDate alloc]init];
    
    NSDateFormatter *f =  [self ly_confFormatter];
    return [f stringFromDate:date];
}


@end
