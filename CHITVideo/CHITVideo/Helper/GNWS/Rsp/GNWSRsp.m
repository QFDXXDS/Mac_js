//
//  GNWSRsp.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/2/2.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNWSRsp.h"
#import "GNRegex.h"
#import "GNJSON.h"
#import "GNWSReqManager.h"


@implementation GNWSRsp


+ (void)WSReciveMessage:(id)message {
    
    NSDictionary * jsonDic = [GNJSON toJSON:message];
    if ([GNRegex isValid:jsonDic]) {
        
        GNLog(@"WSReciveMessage is %@",jsonDic);
        [GNWSReqManager responseObject:jsonDic];
        
        
    NSArray *ConferenceEvents = @[@"AbstractConferenceEvent",@"ApproveRejectPresentationEvent",@"ApproveRejectRaiseHandEvent",@"ConferenceStateChangedEvent",@"ConferenceTerminatedEvent",@"LecturerSetUnsetEvent",@"MeetingLockedUnlockedEvent",@"NameCalledEvent",@"ParticipantAudioMutedUnmutedEvent",@"ParticipantConnectedEvent",@"ParticipantDisconnectedEvent",@"ParticipantLowerHandEvent",@"ParticipantRaiseHandEvent",@"ParticipantVideoBlockedUnblockedEvent",@"PollerSetUnsetEvent",@"PollingStartedStoppedEvent",@"RecordingStartedStoppedEvent",@"RequestToPresentEvent",@"WhiteBoardSessionStartedEvent"] ;

        NSString *name = jsonDic[@"name"] ;
//        NSString *value = jsonDic[CT_WS_VALUE] ;

        if ([name isEqualToString:@"InviteToConfEvent"] ) {
            
            [[NSNotificationCenter defaultCenter]postNotificationName:CTWSConfInviteNotification object:jsonDic];
            return ;
        }
        if ([ConferenceEvents containsObject:name]) {

            [[NSNotificationCenter defaultCenter]postNotificationName:CTWSConfDetailNotification object:jsonDic];
        }
    }
}



@end
