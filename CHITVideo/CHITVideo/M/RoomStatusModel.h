//
//  RoomStatus.h
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2018/1/18.
//  Copyright © 2018年 com.changhongit. VidyoSample. All rights reserved.
//


#import "LectureAttrModel.h"
#import "CurrentCalledModel.h"


@interface RoomStatusModel : NSObject

@property (nonatomic,copy)NSString *locking;  //会议是否被锁定
@property (nonatomic,copy)NSString *conferenceMode;  //会议模式
@property (nonatomic,copy)NSString *cameraStatus;  // 全局摄像头状态 on/off
@property (nonatomic,copy)NSString *microphoneStatus; // 全局麦克风状态 on/off

@property (nonatomic,strong)LectureAttrModel *currentLecture;
@property (nonatomic,strong)CurrentCalledModel *currentCalled;

@end


//    roomStatus =     {
//        cameraStatus = on;
//        currentModeAttribute =         {
//            currentCalled = "<null>";
//            currentLecture = "<null>";
//        };
//        locking = 0;
//        microphoneStatus = on;
//        mode = discussion;
//    };
