//
//  HConferenceModel.h
//  VidyoSample
//
//  Created by user on 17/4/23.
//  Copyright © 2017年 com.changhongit. VidyoSample. All rights reserved.
//

#import <JSONModel/JSONModel.h>
//#import "ContactModel.h"
@protocol HConferenceModel <NSObject>

@end

@interface HConferenceModel : JSONModel
@property (nonatomic,copy)NSString<Optional> * id;

@property (nonatomic,copy)NSString<Optional> * globalConferenceID;
//@property (nonatomic,copy)NSString<Optional> * conferenceId;
@property (nonatomic,copy)NSString<Optional> * name;
@property (nonatomic,copy)NSString<Optional> * hasPIN;
@property (nonatomic,copy)NSString<Optional> * roomPIN;
@property (nonatomic,copy)NSString<Optional> * isLocked;
@property (nonatomic,copy)NSString<Optional> * moderatorPIN;
@property (nonatomic,copy)NSString<Optional> * description;
@property (nonatomic,copy)NSString<Optional> * beginTime;
@property (nonatomic,copy)NSString<Optional> * endTime;
@property (nonatomic,copy)NSString<Optional> * portalAddress;
@property (nonatomic,copy)NSString<Optional> * admin;
@property (nonatomic,copy)NSString<Optional> * adminPwd;
//@property (nonatomic,copy)NSString<Optional> * roomURL ;
@property (nonatomic,copy)NSString<Optional> * roomKey;

@property (nonatomic,copy)NSString<Optional> * status;

@property (nonatomic,copy)NSString<Optional> *userNames;
//@property (nonatomic,copy)NSArray <Optional,ContactModel> * users;



@property (nonatomic,copy)NSString<Optional> *conferenceId;
@property (nonatomic,copy)NSString<Optional> *number;
@property (nonatomic,copy)NSString<Optional> *roomURL;
@property (nonatomic,copy)NSString<Optional> *subject;

@property (nonatomic,copy)NSString<Optional> *conferencePin;
@property (nonatomic,copy)NSString<Optional> *participantId;
@property (nonatomic,copy)NSString<Optional> *participantToken;
@property (nonatomic,copy)NSString<Optional> *roomId;
@property (nonatomic,copy)NSString<Optional> *uccsURL;
@property (nonatomic,copy)NSString<Optional> *conferenceName;


@end
