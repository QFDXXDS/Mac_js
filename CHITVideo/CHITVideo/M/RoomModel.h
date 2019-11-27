//
//  RoomModel.h
//  VidyoSample
//
//  Created by user on 17/4/10.
//  Copyright © 2017年 com.changhongit. VidyoSample. All rights reserved.
//




@interface RoomModel : NSObject

@property (nonatomic,copy)NSString * globalConferenceID;
@property (nonatomic,copy)NSString * conferenceId;
@property (nonatomic,copy)NSString * name;
@property (nonatomic,copy)NSString * hasPIN;
@property (nonatomic,copy)NSString * roomPIN;
@property (nonatomic,copy)NSString * isLocked;
@property (nonatomic,copy)NSString * moderatorPIN;
@property (nonatomic,copy)NSString * description;
@property (nonatomic,copy)NSString * beginTime;
@property (nonatomic,copy)NSString * endTime;
@property (nonatomic,copy)NSString * portalAddress;
@property (nonatomic,copy)NSString * admin;
@property (nonatomic,copy)NSString * adminPwd;
@property (nonatomic,copy)NSString * roomURL ;
@property (nonatomic,copy)NSString * roomKey;
@property (nonatomic,copy)NSString * status;
@property (nonatomic,copy)NSString * ownerId;
@property (nonatomic,copy)NSString * locked;


@property (nonatomic,copy)NSString * userId;
@property (nonatomic,copy)NSString * roomId;

@property (nonatomic,copy)NSString *subject;

@property (nonatomic,copy)NSString * participantId;


@property (nonatomic,copy)NSString *ownerName;
//@property (nonatomic,copy) RoomInfoModel<Optional> * info;
//@property (nonatomic,copy) NSString<Optional> * msg;
//@property (nonatomic,copy) NSString<Optional> * status;


@end
