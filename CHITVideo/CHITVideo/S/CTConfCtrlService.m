//
//  CTConfCtrlService.m
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2018/1/20.
//  Copyright © 2018年 com.changhongit. VidyoSample. All rights reserved.
//

#import "CTConfCtrlService.h"
#import "CTConfDetailModel.h"
#import "CTService.h"
#import "CTWSService.h"
#import "CTConfCtrlService+Category.h"
//#import "VidyoControlTools.h"


@interface CTConfCtrlService()

@property (nonatomic,copy)NSString *selfURI;      //自己的URI

@property (nonatomic,copy)NSString *lectureURI;   //当前演讲者的URI

@property (nonatomic,copy)NSString *callNameURI;  // 被点名的URI

@property (nonatomic,copy)NSString *pinURI;       // 被PINHigh的URI

@property (nonatomic,copy)NSString *devicePartId;  //vidyoc成员id

@property (nonatomic,strong)LectureAttrModel *attrModel;

@property (nonatomic,strong)CurrentCalledModel *calledModel ;

@property (nonatomic,copy)NSString *setLecturerId ; //l演讲者ID

@property (nonatomic,copy)NSString *setCallId ; //点名者ID

@end

@implementation CTConfCtrlService

+ (instancetype)sharedInstance {
    
    static CTConfCtrlService *s = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        s = [[CTConfCtrlService alloc]init];
        [s addNotification];
    });
    return s;
}
- (void)addNotification {
    
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(participantChange) name:ChitVideoNotificationPaticipantsChange object:nil];
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(conferenceActive) name:ChitVideoNotificationConferenceActive object:nil];

    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(confClear) name:ChitVideoNotificationConferenceCleared object:nil];
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(confClear) name:ChitVideoNotificationGuestJoinFail object:nil];
}
+ (void)addNotification {

    [self sharedInstance];
}
+ (void)uploadURI {
    
    if ([CHITVideoService getCallState] == 4) {
        
        CTConfCtrlService *s = [self sharedInstance];
        [s uploadURI];
    }
    
}
+ (void)ConfDetail:(NSDictionary *)dic {
    
    CTConfCtrlService *s = [self sharedInstance];
    [s ConfDetail:dic];
}
#pragma mark  监听通知
- (void)confClear {
    
//    [self cancelLecture];
//    [self cancelCallName];
    _lectureURI = nil;
    _selfURI = nil;
    _callNameURI = nil;
    _pinURI = nil ;
    _setCallId = nil ;
    _setLecturerId = nil ;
    
}
- (void)participantChange {   // 成员改变(肯定能取到自己的URI)
    
    NSDictionary *dic = [CHITVideoService getMyConferenceInfo];
    NSString *participantUri = dic[@"participantUri"] ;
    if (participantUri.length > 0) {
        
        if (![_selfURI isEqualToString:participantUri]) {

            _selfURI = dic[@"participantUri"];
            _devicePartId = dic[@"participantID"] ;
            
            [self uploadURI];
        }
    }
}

- (void)conferenceActive {
    
//        [VidyoControlTools uploadHardwareStatus];
    
        [CTWSService getConferenceSuccess:^(id results) {
            
            NSArray *participants = results[@"participants"] ;
            NSString *callerId = results[@"callerId"] ;
            CT_ConfStatus.whiteBoardSessionURL = results[@"whiteBoardSessionURL"] ;
            
            if(participants.count == 0)  return ;
            
            if ([CTHelper isValid:results[@"lecturerId"]]) {
                
                _setLecturerId = results[@"lecturerId"] ;
                //          找到演讲者
                NSDictionary *participant = [CTWSService getParticipantWithId:_setLecturerId participants:participants] ;
                if (![CTHelper isValid:participants]) return ;
                
                [self setupURI:participant];
                //           找到点名的人
//                if ([CTHelper isValid:callerId] && ![callerId isEqualToString:_setLecturerId]) {
//
//                    NSDictionary *participant = [CTWSService getParticipantWithId:callerId participants:participants] ;
//
//                    [self setCalledURI:participant];
//                }
                
                
                if (CT_ConfStatus.isPVConf) {

                    [CHITVideoService muteCamera:YES];
                }
            }
        } fail:^(NSError *error) {
            
        }];
}
- (void)uploadURI {

    CT_ConfStatus.isUploadURIBool = YES;
    
    [CTWSService interConfCallFlag:@"" devicePartId:_devicePartId participantURI:_selfURI success:^(id results) {
        
//        NSString *lecturerId = results[@"lecturerId"];
//        [self getParticipantsWithLecturerId: lecturerId];
        GNLog(@"上传PID成功");
    } fail:^(NSError *error) {
        
        GNLog(@"上传PID失败");
    }];
}
- (void)ConfDetail:(NSDictionary *)results {
    
    
    NSString *name = results[@"name"] ;
    NSDictionary *value = results[CT_WS_VALUE] ;

    if ([name isEqual:@"ConferenceStateChangedEvent"]) {
        
        if ([value[@"locked"] boolValue]) {
            
//            [SVProgressHUD showInfoWithStatus:@"会议被锁定"];
        } else {
//            [SVProgressHUD showInfoWithStatus:@"会议被解锁"];
        }
        
    } else if ([name isEqual:@"LecturerSetUnsetEvent"]) {
        
        if ([value[@"set"] boolValue]) {
            
            _setLecturerId = value[@"lecturerId"];
            [self getParticipantsWithLecturerId: _setLecturerId];
            
        } else {

            [CHITVideoService muteCamera:NO];
            [CHITVideoService muteMicrophone:NO] ;

            [self cancelLecture];
//            [SVProgressHUD showInfoWithStatus:@"取消演讲者"];
        }
        
    }else if ([name isEqual:@"NameCalledEvent"]) {
        

            _setCallId = value[@"participantId"];
            [self getParticipantsWithParticipantId:_setCallId ];
        
    }else if ([name isEqual:@"ParticipantConnectedEvent"]) {
        
//        [[NSNotificationCenter defaultCenter]postNotificationName:ChitVideoNotificationPaticipantsChange object:nil];
        NSDictionary *participant = value[@"participant"];
        
        if([CTHelper isValid:participant[@"participantId"]]) {

            
            if ([_setLecturerId isEqualToString:participant[@"participantId"]]) {

                [self getParticipantsWithLecturerId: _setLecturerId];
            }
//            我是演讲者
//            if ([_selfURI isEqualToString:_lectureURI]) {
//
//                if ([_setCallId isEqualToString:participant[@"participantId"]]) {
//
//                    [self getParticipantsWithParticipantId: _setCallId];
//                }
//            }
        }
    }else if ([name isEqual:@"ParticipantDisconnectedEvent"]) {
        
    
//      不在会议中停止执行
        if (!CT_ConfStatus.didInterSDKBool) return ;
        
        NSString *participantId = value[@"participantId"];

//        我是演讲者
        if ([_selfURI isEqualToString:_lectureURI]) {
//          点名的人离开会议
            if ([_setCallId isEqualToString:participantId]) {
            
//                [SVProgressHUD showInfoWithStatus:@"点名成员离开会议"];
                [CHITVideoService showPreview:YES];
                [CHITVideoService setParticipantsLimit:4] ;
            }
        } else {
            
            if ([_setLecturerId isEqualToString:participantId]) {
                
//                [SVProgressHUD showInfoWithStatus:@"演讲者离开会议"];
                [CHITVideoService showPreview:YES];
                [CHITVideoService setParticipantsLimit:4] ;
            }
        }

//        [[NSNotificationCenter defaultCenter]postNotificationName:ChitVideoNotificationPaticipantsChange object:nil];
    }
}
- (void) getParticipantsWithLecturerId:(NSString *)lecturerId {
    
    if (![CTHelper isValid:lecturerId]) return ;
    
    [CTWSService getParticipantsWithId:lecturerId success:^(id results) {
        GNLog(@"getParticipantsWithId_%@",results) ;
        [self setupURI:results];
    } fail:^(NSError *error) {
        
    }];

}
- (void) getParticipantsWithParticipantId:(NSString *)participantId {
    
    if (![CTHelper isValid:participantId]) return ;
    
    [CTWSService getParticipantsWithId:participantId success:^(id results) {
        
        [self setCalledURI:results];
        
    } fail:^(NSError *error) {
        
    }];
    
}
- (void)handleWithDetailModel:(CTConfDetailModel *)detailModel {  //
    
    RoomStatusModel *statusModel = detailModel.roomStatus;
    [CTConfCtrlService confMode:statusModel.conferenceMode];
    RoomModel *roomModel = detailModel.room ;
    if ([roomModel.ownerId isEqualToString:[GNDefault objectForKey:CT_USER_ID]]) {

        CT_ConfStatus.isConfOwner = YES;
        CT_ConfStatus.isLock = [roomModel.locked boolValue] ;
    }
}
- (void)setupURI:(NSDictionary *)participant {   //有演讲者  判断在线、离线   是否有点名  点名在线、离线
    
    NSString *lectureURI = participant[@"participantURI"];
//    if ([lectureURI isEqualToString:_lectureURI])  return ;
    
//    [SVProgressHUD showInfoWithStatus:[NSString stringWithFormat:@"设置%@为演讲者",participant[@"name"]]];
    
    _lectureURI = lectureURI ;
    //        _pinURI = _lectureURI ;
    if (![CTHelper isValid:_lectureURI])  return ;
    
    CT_ConfStatus.confMode = CT_CONFMODE_LECTURE ;

    if (!CT_ConfStatus.isPVConf) {
     
        [CHITVideoService muteCamera:NO];
    }

    if ([_selfURI isEqualToString:_lectureURI]) {
        
        [CHITVideoService muteMicrophone:NO] ;
        GNLog(@"我是演讲者") ;
        [self setLectureURIWithLimit:4 showPreview:NO];
    } else {
        
        if ([_selfURI isEqual:_callNameURI] ) {
            
            [CHITVideoService muteMicrophone:NO] ;
        } else {
           
            [CHITVideoService muteMicrophone:YES] ;
        }
        GNLog(@"别人是演讲者") ;
        [self setLectureURIWithLimit:1 showPreview:NO];
    }
}

- (void)cancelLecture {
    
    if (_lectureURI ) {
        
        [self noPinURI];
        _lectureURI = nil;
        _callNameURI = nil;
        CT_ConfStatus.confMode = CT_CONFMODE_GROUP ;

        [[NSNotificationCenter defaultCenter] postNotificationName:CTConfCtrlDidHappenNotification object:nil];
    }
}

- (void)setCalledModel {
    
    if ([CTHelper isValid:_calledModel]) {   // 有点名者
        GNLog(@"----有点名者");
        if (_calledModel.participantURI) {  //  点名者在线、
            
//            [self setCalledURI];
        } else {   // 点名者离线
            GNLog(@"----点名者离线");
            
            if (_attrModel.participantURI) {
                GNLog(@"----点名者离线00");
                
                if ([_selfURI isEqualToString:_attrModel.participantURI]) {    //我是演讲者
                    GNLog(@"----点名者离线11");
                    
                    [self noCallNameURI:@"被点名者离线"];
                }
            }
        }
    } else {   // 没有点名者
        
        GNLog(@"----没有点名者");
        if ([_selfURI isEqualToString:_attrModel.participantURI]) {   //我是演讲者
            GNLog(@"----没有点名者 000");
            
            [self noCallNameURI:@"取消点名"];
        }
        if ([_selfURI isEqualToString:_callNameURI]){  // 我是被点名者
            
            [self cancelCallName];
        }
    }
}
- (void)setCalledURI:(NSDictionary *)participant {   //点名URI有效
    
//    GNLog(@"点名URI有效");
//    if (_attrModel.participantURI) {
//        GNLog(@"点名URI有效00");
//
//        if ([_selfURI isEqualToString:_attrModel.participantURI]) {    //我是演讲者
//            GNLog(@"点名URI有效11");
//
//            if (![_callNameURI isEqualToString:_calledModel.participantURI]) {
//                GNLog(@"点名URI有效 22");
//
//                [SVProgressHUD showInfoWithStatus:[NSString stringWithFormat:@"点名%@",_calledModel.displayName]] ;
//                [self cancelLastPinURI];
//
//                [CTConfCtrlService pinWithURI:_calledModel.participantURI limit:1 mode:YES preview:NO];
//
//                _callNameURI = _calledModel.participantURI ;
//                _pinURI = _callNameURI ;
//            }
//        } else {
//
//            if ([_selfURI isEqualToString:_calledModel.participantURI]) {   //我是被点名者
//                if (![_callNameURI isEqualToString:_calledModel.participantURI]) {
//
//                    [SVProgressHUD showInfoWithStatus:@"您已被点名"] ;
//                    _callNameURI = _calledModel.participantURI ;
//                    [[NSNotificationCenter defaultCenter] postNotificationName:CTConfCtrlDidHappenNotification object:nil];
//                }
//            } else {
//
//                [self cancelCallName];
//            }
//        }
//    }
    
    
    NSString *callNameURI = participant[@"participantURI"];
    GNLog(@"_callNameURI is %@",callNameURI) ;

    if (![CTHelper isValid:callNameURI]) return ;
//  我是演讲者
    if ([_selfURI isEqualToString:_lectureURI]) {
//       自己被点名
        if([_selfURI isEqualToString:callNameURI]) {
            
            return ;
        }
    }
    _callNameURI = callNameURI ;

    
    if ([_selfURI isEqualToString:_lectureURI]) {
        
//        [SVProgressHUD showInfoWithStatus:[NSString stringWithFormat:@"点名%@",participant[@"name"]]];
        
        [self cancelLastPinURI];
        [CTConfCtrlService pinWithURI:_callNameURI limit:1 mode:YES preview:NO];
        _pinURI = _callNameURI ;

    }

    
    if ([_selfURI isEqualToString:_callNameURI]) {
        GNLog(@"_selfURI 等于:_callNameURI") ;
        [CHITVideoService muteMicrophone:NO];
    } else {
        
        GNLog(@"_selfURI 不等于:_callNameURI") ;

        if (![_selfURI isEqualToString:_lectureURI]) {
            
            [CHITVideoService muteMicrophone:YES];

        }
    }
    
    
}


- (void)setLectureURIWithLimit:(int)limit showPreview:(BOOL )show  {  //其他人 设置演讲者
    
    
    if (_lectureURI && ![_lectureURI isEqualToString:_pinURI]){
        
        [self cancelLastPinURI];
        _pinURI = _lectureURI ;
        
        GNLog(@"设置演讲者%d,%d",limit,show) ;
        if(limit == 1){
            
            [CTConfCtrlService pinWithURI:_lectureURI limit:limit mode:YES preview:show];
        } else {
            [CTConfCtrlService pinWithURI:_lectureURI limit:limit mode:NO preview:show];
        }
        
        [[NSNotificationCenter defaultCenter] postNotificationName:CTConfCtrlDidHappenNotification object:nil];
    }
    
    
    
    
//    if (![_lectureURI isEqualToString:_attrModel.participantURI]) {
    
//        [SVProgressHUD showInfoWithStatus:[NSString stringWithFormat:@"设置%@为演讲者",_attrModel.displayName]] ;

//        _callNameURI = nil;
    
//        [self cancelLastPinURI];
//
//        _lectureURI = _attrModel.participantURI;
//        _pinURI = _lectureURI ;
//
//        [CTConfCtrlService pinWithURI:_lectureURI limit:limit mode:YES preview:show];
//
//        [[NSNotificationCenter defaultCenter] postNotificationName:CTConfCtrlDidHappenNotification object:nil];
//    }
    
    
    
}

- (void)cancelCallName {
    
    if (_callNameURI) {
        
//        [SVProgressHUD showInfoWithStatus:@"您已被取消点名"] ;
        _callNameURI = nil;
        
        [[NSNotificationCenter defaultCenter] postNotificationName:CTConfCtrlDidHappenNotification object:nil];
        
    }
}

- (void)noCallNameURI:(NSString *)description {
    
    if (_callNameURI) {
        
//        [SVProgressHUD showInfoWithStatus:description] ;
        [self noPinURI];
        
        if (_lectureURI) {

            [CTConfCtrlService pinWithURI:_lectureURI limit:4 mode:YES preview:YES];
            _pinURI = _lectureURI;
        }
        _callNameURI = nil;
    }
}

- (void)noPinURI {
    
    [CHITVideoService showPreview:YES];
    [CHITVideoService setParticipantsLimit:4] ;
    
    GNLog(@"noPinURI") ;
    [self cancelLastPinURI];
    _pinURI = nil;
}
// 取消上一个演讲者
- (void) cancelLastPinURI {
    
    if (_pinURI) {
        
        GNLog(@"cancelLastPinURI") ;
        [CHITVideoService pinParticipant:_pinURI pin:NO];
        _pinURI = nil;
    }
}

+ (BOOL)isLecture {
    
    CTConfCtrlService *s = [self sharedInstance];
    return [s.selfURI isEqualToString:s.lectureURI];
}
+ (BOOL)isCalledName {
    
    CTConfCtrlService *s = [self sharedInstance];
    return [s.selfURI isEqualToString:s.callNameURI];
}

@end
