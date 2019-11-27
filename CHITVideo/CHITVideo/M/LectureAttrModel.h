//
//  LectureAttrModel.h
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2018/1/18.
//  Copyright © 2018年 com.changhongit. VidyoSample. All rights reserved.
//



@interface LectureAttrModel : NSObject

@property (nonatomic,copy)NSString *internalID;          //演讲者的Coss系统ID
@property (nonatomic,copy)NSString *participantID;      //演讲者的participantID
@property (nonatomic,copy)NSString *participantURI;     //演讲者的participantURI
@property (nonatomic,copy)NSString *displayName;        //演讲者的显示名
@property (nonatomic,copy)NSString *userTerminalType;   //演讲者终端类型
@property (nonatomic,copy)NSString *startTime;         //演讲开始时间
@end

