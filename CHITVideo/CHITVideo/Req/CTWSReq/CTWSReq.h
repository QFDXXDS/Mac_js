//
//  CTWSReq.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/2/2.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNWSReq.h"

@interface CTWSConfDetailReq : GNWSReq

@property (nonatomic, copy) NSString * globalConferenceID;

@end

@interface CTWSAppInfoReq : GNWSReq

@property (nonatomic,copy)NSString *userTerminalType;
@end

@interface CTWSHardwareStatusReq : GNWSReq

@property (nonatomic,copy)NSString *participantUE;

@property (nonatomic,copy)NSString *globalConferenceID;

@property (nonatomic,copy)NSString *participantUEStatus;
@end

@interface CTWSConfInitialReq : GNWSReq

@property (nonatomic, copy) NSString * globalConferenceID;

@end

@interface CTWSConfLockReq : GNWSReq

@property (nonatomic, copy) NSString * globalConferenceID;
@property (nonatomic,copy)NSString *action;             //lock/unlock

@end



@interface CHITRaiseHandRequest : GNWSReq

@property (nonatomic, copy) NSString * conferenceId;
@property (nonatomic,copy)NSString *participantId;

@end

@interface CHITLowerHandRequest : CHITRaiseHandRequest

@end


@interface CHITParticipantJoinedNotifyRequest : CHITRaiseHandRequest

@property (nonatomic,copy)NSString *participantURI;
@property (nonatomic,copy)NSString *devicePartId ;


@end

@interface CHITParticipantLeftNotifyRequest : CHITRaiseHandRequest


@end


@interface CHITSubscribeConferenceRequest : CHITRaiseHandRequest


@end


@interface CHITInviteParticipantRequest : GNWSReq

@property (nonatomic,copy)NSString *conferenceId;
@property (nonatomic,copy)NSString *ipAddress;
@property (nonatomic,copy)NSString *terminalId;
@property (nonatomic,copy)NSString *userId;

//@property (nonatomic,strong)NSArray *users;

@end


@interface CHITGetParticipantsRequest : CHITRaiseHandRequest


@end


@interface CHITGetConferenceRequest : CHITRaiseHandRequest


@end

@interface CHITParticipantMediaChangedNotifyRequest : CHITRaiseHandRequest


@property (nonatomic,copy)NSString *mediaType;
@property (nonatomic,copy)NSString *muted;
@property (nonatomic,copy)NSString *direction;
@end


@interface CHITWhiteBoardStartedNotifyRequest : CHITRaiseHandRequest


@property (nonatomic,copy)NSString *sessionURL;

@end

@interface CHITWhiteBoardStoppedNotifyRequest : CHITRaiseHandRequest


@end


