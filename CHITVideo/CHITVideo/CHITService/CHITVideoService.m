//
//  CHITVideoService.m
//  CHitVideo
//
//  Created by user on 2018/9/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "CHITVideoService.h"
//#import "VidyoClient.h"
//#import "VidyoClientSample.h"
#import "ChitVideoNotification.h"
#import "ChitImageHelper.h"

#import "VidyoViewController.h"

//如果版本为只提供初级版本则改为1，需要提供高级版本的功能则改为0
#define SDK_VERSION_MODE 0
#define SDK_ALERT  GNLog(@"此功能在高级版本中开放")
#define LOG_NAME "ChitVideoLog"

#define FILE_PATH [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]


static  VCConnector     *vc = nil;
static  CHITLogger *logger = nil;

@interface CHITVideoService()
{
    
}

@property (nonatomic,assign)BOOL isInitialBool;

@end

@implementation CHITVideoService
#pragma mark + 创建一个单例
static CHITVideoService *_shareVideo = nil;
+ (id)instance{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _shareVideo = [[CHITVideoService alloc] init];
        logger = [[CHITLogger alloc] init];

    });
    return _shareVideo;
}
+ (BOOL)initialize:(BOOL)log view:(NSViewController *)controller{
    
      [self instance] ;
//    if (!_shareVideo.isInitialBool) {
//        _shareVideo.isInitialBool = YES;
//
//        [[NSUserDefaults standardUserDefaults] setBool:log forKey:@"isSaveLog"];
//        [[NSUserDefaults standardUserDefaults] synchronize];
//        VidyoClientLogParams logParams = {0};
//
//        NSFileManager* fm=[NSFileManager defaultManager];
//        NSString *documentsDirectory = FILE_PATH;
//        documentsDirectory = [documentsDirectory stringByAppendingString:@"/ChitVideo"];
//        if(![fm fileExistsAtPath:documentsDirectory]){
//            [fm createDirectoryAtPath:documentsDirectory withIntermediateDirectories:YES attributes:nil error:nil];
//        }
//        if (log) {
//            VidyoClientConsoleLogConfigure(VIDYO_CLIENT_CONSOLE_LOG_CONFIGURATION_RESERVED);
//            const char *pathToLogDir = [documentsDirectory cStringUsingEncoding:NSUTF8StringEncoding];
//            logParams.logBaseFileName = LOG_NAME;
//            logParams.pathToLogDir = pathToLogDir;
//            logParams.logLevelsAndCategories = "FATAL ERROR WARNING INFO@App INFO@AppEvents";
//        }
//
//        if (VidyoClientInitialize(GuiOnOutEvent, (__bridge VidyoVoidPtr)(self), &logParams) == VIDYO_FALSE) {
//            GNLog(@"VidyoClientInit() returned failure!");
//            return NO;
//        }
//    }
//
//
//    BOOL start = [self startWithxPos:0 yPos:0 width:view.frame.size.width height:view.frame.size.height view:view];
//    if (!start) {
//        return NO;
//    }
    
    VidyoViewController *vvc = (VidyoViewController *)controller ;
    NSLog(@"&view is %@", vvc.mainView);
    NSLog(@"&view frame is %@", NSStringFromRect(vvc.mainView.frame));

    NSView *view = vvc.mainView ;
    vc = [[VCConnector alloc] init:&view
                         ViewStyle:VCConnectorViewStyleDefault
                RemoteParticipants:15
                     LogFileFilter:"info@VidyoClient info@VidyoConnector warning"
                       LogFileName:""
                          UserData:0];

   
    
    [vvc refreshUI];
    if ( vc ) {

        if ( ![vc registerLocalCameraEventListener:controller] ) {
            [logger Log:@"LocalCameraEventListener registration failed."];
        }
        
        // Register for local microphone events
        if ( ![vc registerLocalMicrophoneEventListener:controller] ) {
            [logger Log:@"LocalMicrophoneEventListener registration failed."];
        }

        // Register for local speaker (audio output) events
        if ( ![vc registerLocalSpeakerEventListener:controller] ) {
            [logger Log:@"LocalSpeakerEventListener registration failed."];
        }

        // Register for local monitor share events
        if ( ![vc registerLocalMonitorEventListener:controller] ) {
            [logger Log:@"LocalMonitorEventListener registration failed."];
        }

        // Register for local window share events
        if ( ![vc registerLocalWindowShareEventListener:controller] ) {
            [logger Log:@"LocalWindowShareEventListener registration failed."];
        }

        // Register for participant events
        if ( ![vc registerParticipantEventListener:controller] ) {
            [logger Log:@"ParticipantEventListener registration failed."];
        }

        // Register for remote camera events
        if ( ![vc registerRemoteCameraEventListener:controller] ) {
            [logger Log:@"RemoteCameraEventListener registration failed."];
        }

        // Register for network interface events
        if ( ![vc registerNetworkInterfaceEventListener:controller] ) {
            [logger Log:@"NetworkInterfaceListener registration failed."];
        }

        // Register for message (chat) events
        if ( ![vc registerMessageEventListener:controller] ) {
            [logger Log:@"MessageEventListener registration failed."];
        }

        // Register for log events; the filter argument specifies the log level that
        // is printed to console as well as what is called back in onLog.
//        if ( ![vc registerLogEventListener:self Filter:"info@VidyoClient info@VidyoConnector warning"] ) {
//            [logger Log:@"LogEventListener registration failed."];
//        }
    } else {
        // Log error and disable toolbar buttons and menu items to prevent further VidyoConnector calls
        [logger Log:@"ERROR: VidyoConnector construction failed ..."];
//        [toolbarStatusText  setStringValue:@"VidyoConnector Failed"];
//        [controlsStatusText setStringValue:@"VidyoConnector Failed"];
//        [controlsStatusText setTextColor:[NSColor redColor]];
//        [cameraPrivacyButton      setEnabled:NO];
//        [microphonePrivacyButton  setEnabled:NO];
//        [speakerPrivacyButton     setEnabled:NO];
//        [toggleConnectButton      setEnabled:NO];
//        [connectMenuItem          setEnabled:NO];
//        [disconnectMenuItem       setEnabled:NO];
//        [debugMenuItem            setEnabled:NO];
//        [showSharePreviewMenuItem setEnabled:NO];
    }
    [logger Log:[NSString stringWithFormat:@"VidyoViewController::viewDidAppear: VidyoConnector Constructed => %s",
                 (vc != nil) ? "success" : "failed"]];


    return YES;
}
- (void)onLog:(VCLogRecord*)logRecord {
    [logger LogClientLib:logRecord.message];
}

#pragma mark + start
+ (BOOL)startWithxPos:(int)xPos yPos:(int)yPos width:(int)width height:(int)height view:(NSView *)view{
    
//    VidyoRect videoRect = (VidyoRect){(VidyoInt)xPos,(VidyoInt)yPos,(VidyoUint)width,(VidyoUint)height};
//    VidyoBool ret;
//    VidyoClientLogParams logParams = {0};
//    VidyoClientProfileParams profileParams = {0};
//    // startup VidyoClient library
//    ret = VidyoClientStart(GuiOnOutEvent, (__bridge VidyoVoidPtr)(self), &logParams, (__bridge VidyoWindowId)view, &videoRect, NULL, &profileParams, VIDYO_FALSE);
//    if (!ret) {
//        [[NSNotificationCenter defaultCenter] postNotificationName:@"WEVIDEO_LOGIC_START_FAILED" object:@"VidyoClientStart() returned failure!"];
//        return NO;
//    } else {
//        GNLog(@"VidyoClientStart() returned success!");
//    }
//
//    [self bootstrap];
    return YES;
}

#pragma mark - 加入会议结果回调
- (void)onSuccess{
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"CHITVIDEO_CONFERENCE_ACTIVE" object:nil];
    
    GNLog(@"加入会议 onSuccess") ;
}
- (void)onFailure:(VCConnectorFailReason)reason{
    
    [self releasevidyoSDK];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"CHITVIDEO_JOIN_FAILED" object:@{@"error":@(reason)}];
    GNLog(@"加入会议 onFailure") ;
    
}
- (void)onDisconnected:(VCConnectorDisconnectReason)reason{
    
    [self releasevidyoSDK];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"CHITVIDEO_CONFERENCE_CLEARED" object:nil];
    GNLog(@"加入会议 onDisconnected") ;
    
}
- (void)releasevidyoSDK {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        
        //        [self.cameraArray removeAllObjects];
        //        [self.remoteWindowShareArray removeAllObjects];
        //        [self.windowShareUids removeAllObjects];
        //
        //
        //        [self.connector selectLocalCamera:nil];
        //        [self.connector selectLocalMicrophone:nil];
        //        [self.connector selectLocalSpeaker:nil];
        //
        //         [self.connector setMode:VCConnectorModeBackground];
        //
        //        _lastSelectedCamera = nil;
        //        _localMicrophone = nil;
        //
        //       if(self.connector){
        //
        //
        //            [self.connector hideView:&_localView];
        //            [self.costomVC hideView];
        //
        //            [self.connector selectLocalWindowShare:nil];
        //            [self.connector selectAudioContentShare:nil];
        //            [self.connector selectLocalMonitor:nil];
        //
        //            [self.connector assignViewToLocalCamera:&_localView LocalCamera:nil DisplayCropped:YES AllowZoom:YES];
        //
        //
        //            [self.connector unregisterLocalCameraEventListener];
        //            [self.connector unregisterLocalMicrophoneEventListener];
        //            [self.connector unregisterLocalSpeakerEventListener];
        //
        //            [self.connector unregisterRemoteCameraEventListener];
        //            [self.connector unregisterRemoteMicrophoneEventListener];
        //
        //            [self.connector unregisterParticipantEventListener];
        //            [self.connector unregisterRemoteWindowShareEventListener];
        //            [self.connector unregisterNetworkInterfaceEventListener];
        //
        //
        //            [self.connector disable];
        //            self.connector = nil;
        //
        ////            [VCConnectorPkg uninitialize];
        //        }
        //
        //        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        //
        //            [_costomVC dismissViewControllerAnimated:YES completion:nil];
        //            _costomVC = nil;
        //
        //        });
        //
        //        [self receiveMeetingMuteAudioMessageWithId:nil muteUserId:nil muteState:YES];
        
//        DDLogVerbose(@"APP..........................................[self.cameraArray removeAllObjects];" ) ;
        
        
        
        
        if(vc){
            
//            DDLogVerbose(@"APP..........................................[self.connector hideView:&_localView];" ) ;
            
            
            [[NSNotificationCenter defaultCenter] postNotificationName:@"vidyoSDKDisconnectHideActiveView" object:self];
            [[NSNotificationCenter defaultCenter] postNotificationName:@"vidyoSDKDisconnectHideSmallView" object:self];
            
            //        [self.connector setCameraPrivacy:YES];
            //        [self.connector setMicrophonePrivacy:YES];
            //        [self.connector setSpeakerPrivacy:YES];
            
//            DDLogVerbose(@"APP.......................................... [self.connector setMode:VCConnectorModeBackground];" ) ;
            
            [vc setMode:VCConnectorModeBackground];
//            DDLogVerbose(@"APP..........................................[self.connector selectLocalCamera:nil];" ) ;
            
            [vc selectLocalCamera:nil];
//            DDLogVerbose(@"APP..........................................[self.connector selectLocalMicrophone:nil];" ) ;
            
            [vc selectLocalMicrophone:nil];
//            DDLogVerbose(@"APP..........................................[self.connector selectLocalSpeaker:nil];" ) ;
            
            [vc selectLocalSpeaker:nil];
//            DDLogVerbose(@"APP.......................................... [self.connector unregisterLocalCameraEventListener];" ) ;
            
            [vc unregisterLocalCameraEventListener];
//            DDLogVerbose(@"APP.......................................... [self.connector unregisterLocalMicrophoneEventListener];" ) ;
            
            [vc unregisterLocalMicrophoneEventListener];
//            DDLogVerbose(@"APP..........................................[self.connector unregisterLocalSpeakerEventListener];" ) ;
            
            [vc unregisterLocalSpeakerEventListener];
//            DDLogVerbose(@"APP..........................................[self.connector unregisterRemoteCameraEventListener];" ) ;
            
            [vc unregisterRemoteCameraEventListener];
//            DDLogVerbose(@"APP..........................................[self.connector unregisterRemoteMicrophoneEventListener];" ) ;
            
            [vc unregisterRemoteMicrophoneEventListener];
//            DDLogVerbose(@"APP..........................................[self.connector unregisterParticipantEventListener];" ) ;
            
            [vc unregisterParticipantEventListener];
//            DDLogVerbose(@"APP..........................................[self.connector unregisterRemoteWindowShareEventListener];" ) ;
            
            [vc unregisterRemoteWindowShareEventListener];
//            DDLogVerbose(@"APP..........................................[self.connector unregisterNetworkInterfaceEventListener];" ) ;
            
            [vc unregisterNetworkInterfaceEventListener];
//            DDLogVerbose(@"APP..........................................[self.connector unregisterLogEventListener];" ) ;
            
            [vc unregisterLogEventListener];
//            DDLogVerbose(@"APP..........................................[self.connector disable];" ) ;
            
            [vc disable];
//            DDLogVerbose(@"APP..........................................self.connector = nil;" ) ;
            
            vc = nil;
            
            //            [VCConnectorPkg uninitialize];
        }
        //        _viewCameraStore = [NSMutableDictionary dictionary];
        
    });
    
    
    GNLog(@" [self releasevidyoSDK]") ;
    
    
}

+ (void)bootstrap
{
//    VidyoClientRequestConfiguration conf = {0};
//    VidyoUint error;
//    if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration))) != VIDYO_CLIENT_ERROR_OK) {
//        GNLog(@"Failed to request configuration with error %u", error);
//    } else {
//        [[UIApplication sharedApplication] setStatusBarOrientation:UIInterfaceOrientationPortrait];
//
//        // Default configuration
//        conf.enableShowConfParticipantName = VIDYO_TRUE;
//        conf.enableHideCameraOnJoin = VIDYO_FALSE;
//        conf.enableBackgrounding = VIDYO_TRUE;
//
//        // Disable autologin
//        conf.userID[0] = '\0';
//        conf.portalAddress[0] = '\0';
//        conf.serverAddress[0] = '\0';
//        conf.password[0] = '\0';
//        conf.selfViewLoopbackPolicy = 2;
//        if (VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration)) != VIDYO_CLIENT_ERROR_OK) {
//            GNLog(@"Failed to set configuration");
//        }
//    }
}
+ (BOOL)logLevel:(NSString *)log{
//    VidyoClientRequestSetLogLevelsAndCategories logLevels = {0};
//    strlcpy(logLevels.levelsAndCategories, [log UTF8String], sizeof(logLevels.levelsAndCategories));
//    return VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_LOG_LEVELS_AND_CATEGORIES, &logLevels, sizeof(VidyoClientRequestSetLogLevelsAndCategories));
    
    return YES;
}
#pragma mark + 参加会议
+ (int)joinConference:(NSString *)portalURL
              roomKey:(NSString *)roomKey
             userName:(NSString *)displayName
           andRoomPIN:(NSString *)pin
            muteVideo:(BOOL)muteVideo
       muteMicrophone:(BOOL)muteMicrophone
          muteSpeaker:(BOOL)muteSpeaker{
    
//    VidyoClientInEventRoomLink roomLinkEvent = {0};
//    roomLinkEvent.muteCamera = muteVideo;
//    roomLinkEvent.muteMicrophone = muteMicrophone;
//    roomLinkEvent.muteSpeaker = muteSpeaker;
//    roomLinkEvent.clientType = VIDYO_CLIENT_CLIENTTYPE_I;
//    if(portalURL.length == 0){
//        return 6;
//    }else if (roomKey.length == 0){
//        return 7;
//    }else if (displayName.length == 0){
//        return 8;
//    }
//    if ([self getCallState] != VIDYO_CLIENT_CALL_STATE_IDLE) {
//        GNLog(@"VIDYO CLIENT CALL STATE IS %d",[self getCallState]);
//        return [self getCallState];
//    }
//    strncpy(roomLinkEvent.portalUri, [portalURL UTF8String], URI_LEN);
//    strncpy(roomLinkEvent.roomKey, [roomKey UTF8String], ROOMKEY_SIZE);
//    strncpy(roomLinkEvent.displayName, [displayName UTF8String], USERID_SIZE);
//    if (pin) {
//        strncpy(roomLinkEvent.pin, [pin UTF8String], PIN_SIZE);
//    }
//    if (VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_ROOM_LINK, &roomLinkEvent, sizeof(VidyoClientInEventRoomLink)) == VIDYO_FALSE) {
//        return 9;
//    }
    
    NSLog(@"加入会议");
    [self instance] ;
    [vc connectToRoomAsGuest:[portalURL UTF8String]
                        DisplayName:[[displayName stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] UTF8String]
                            RoomKey:[roomKey UTF8String]
                            RoomPin:[pin UTF8String]
                  ConnectorIConnect:_shareVideo];

    return 0;
}
#pragma mark + 取消会议
+ (void)cancelConference {
    
//    if ([self getCallState] != VIDYO_CLIENT_CALL_STATE_IN_CONFERENCE) {
//
//        GNLog(@"执行--VIDYO_CLIENT_IN_EVENT_CANCEL") ;
//        VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_CANCEL, NULL, 0);
//    }
    
//    [self leaveConference];
}

#pragma mark + 视频挂断
+ (BOOL)leaveConference{
    
//    VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_LEAVE, NULL, 0);
    
    return YES;
}

+ (int)getCallState{
    
//    VidyoClientRequestCallState request = {0};
//
//    VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CALL_STATE, &request, sizeof(VidyoClientRequestCallState));
    
//    return request.callState;
    
    return 1;
}
#pragma mark + 视频通话的保持/取消保持
+ (BOOL)holdVideoCallWithMute:(BOOL)mute{
    //    if (_isCanOpenTheCameraOrMicrophone == YES) {
//    VidyoClientInEventMute muteEvent = {0};
//    muteEvent.willMute = mute;
//    VidyoBool video = VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_MUTE_VIDEO, &muteEvent, sizeof(VidyoClientInEventMute));
//    VidyoBool audioIn = VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_MUTE_AUDIO_IN, &muteEvent, sizeof(VidyoClientInEventMute));
//    VidyoBool audioOut = VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_MUTE_AUDIO_OUT, &muteEvent, sizeof(VidyoClientInEventMute));
//    if (video && audioIn && audioOut) {
//        return YES;
//    }
    //        else{
    return NO;
    //        }
    //    }else{
    //        return NO;
    //    }
}

#pragma mark + 摄像机切换
+ (BOOL)switchCamera:(int)camera{
    //    if (_isCanOpenTheCameraOrMicrophone == YES) {
//    VidyoClientRequestConfiguration requestConfig = {0};
//    if (VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &requestConfig, sizeof(VidyoClientRequestConfiguration)) != VIDYO_CLIENT_ERROR_OK) {
//        return NO;
//    }else{
//        if (camera == 0){
//            requestConfig.currentCamera = 0;
//        }else if (camera == 1){
//            requestConfig.currentCamera = 1;
//        }
//        if (VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_CONFIGURATION, &requestConfig, sizeof(VidyoClientRequestConfiguration)) != VIDYO_CLIENT_ERROR_OK) {
//            return NO;
//        }
//        else{
//            return YES;
//        }
//    }
    return YES;
    //    }
    //    else{
    //        return NO;
    //    }
}
#pragma mark + 会前设置
+ (void)conferenceMuteCamera:(BOOL)camera muteMicrophone:(BOOL)microphone muteSpeaker:(BOOL)speaker{
//    VidyoClientRequestConfiguration conf = { 0 };
//    VidyoUint error;
//    if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration))) != VIDYO_CLIENT_ERROR_OK) {
//        GNLog(@"Failed to request configuration with error %u", error);
//    }else{
//        conf.enableShowConfParticipantName = 1;
//        //        conf.videoPreferences =
//        conf.enableMuteMicrophoneOnJoin = microphone;
//        conf.enableHideCameraOnJoin = camera;
//        conf.enableMuteSpeakerOnJoin = speaker;
//        if (VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_CONFIGURATION,
//                                   &conf,
//                                   sizeof(VidyoClientRequestConfiguration))
//            != VIDYO_CLIENT_ERROR_OK) {
//            GNLog(@"Failed to set conferenceMuteCamera:muteMicrophone:muteSpeaker");
//        }
//    }
}
#pragma mark + 关闭/打开摄像头
+ (BOOL)muteCamera:(BOOL)mute{
    //    if (_isCanOpenTheCameraOrMicrophone == YES) {
//    VidyoClientInEventMute muteEvent = {0};
//    muteEvent.willMute = mute;
//    return VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_MUTE_VIDEO, &muteEvent, sizeof(VidyoClientInEventMute));
    //    }else{
    //        return NO;
    //    }
    return YES ;
}

#pragma mark + 关闭/打开麦克风
+ (BOOL)muteMicrophone:(BOOL)mute{
    //    if (_isCanOpenTheCameraOrMicrophone == YES) {
//    VidyoClientInEventMute muteEvent = {0};
//    muteEvent.willMute = mute;
//    return VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_MUTE_AUDIO_IN, &muteEvent, sizeof(VidyoClientInEventMute));
    //    }else{
    //        return NO;
    //    }
    return YES ;
}

#pragma mark + 关闭/打开听筒
+ (BOOL)muteSpeaker:(BOOL)mute{
//    VidyoClientInEventMute muteEvent = {0};
//    muteEvent.willMute = mute;
//    return VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_MUTE_AUDIO_OUT, &muteEvent, sizeof(VidyoClientInEventMute));
    
    return YES ;
}

#pragma mark + 文字聊天
+ (BOOL)sendGroupChatMsg:(NSString *)message{
//    VidyoClientInEventGroupChat chatEvent = {0};
//    strncpy(chatEvent.message, [message UTF8String], MAX_CHAT_MESSAGE_LEN);
//    if (VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_GROUP_CHAT, &chatEvent, sizeof(VidyoClientInEventGroupChat)) != VIDYO_TRUE) {
//        return NO;
//    } else {
//        return YES;
//    }
    
    return YES ;
}
#pragma mark + 获取CPU状态
+ (void)getParticipantNetStatus{
//    VidyoClientRequestBandwidthInfo netStatus = {0};
//    VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_BANDWIDTH_INFO, &netStatus, sizeof(netStatus));
//    GNLog(@"上行+++++%u",netStatus.ActualSendBwVideo);
//    GNLog(@"下行+++++%u",netStatus.ActualRecvBwVideo);
    
    //    VidyoClientParticipantStatistics statistics ={0};
    //    VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_PARTICIPANT_STATISTICS_AT, &statistics, sizeof(VidyoClientParticipantStatistics));
    //    GNLog(@"Width+++++%u",statistics.videoResolution.width);
    //    GNLog(@"Height+++++%u",statistics.videoResolution.height);
    //    GNLog(@"DecodedFrame+++++%u",statistics.videoDecodedFrameRate);
    return;
}
#pragma mark + 获取摄像头的状态
+ (NSDictionary *)getCameraStatus{
//    VidyoClientRequestGetMuted getVideoStatus = {0};
//    VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_MUTED_VIDEO, &getVideoStatus, sizeof(getVideoStatus));
//
//    VidyoClientRequestGetMuted getServerVideoStatus = {0};
//    VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_MUTED_SERVER_VIDEO, &getServerVideoStatus, sizeof(getServerVideoStatus));
//
//    if (getVideoStatus.isMuted) {
//        return @{@"type":@(0),@"mute":@(getVideoStatus.isMuted)};
//    }else if (getServerVideoStatus.isMuted){
//        return @{@"type":@(1),@"mute":@(getServerVideoStatus.isMuted)};
//    }
    return nil;
}
#pragma mark + 获取麦克风的状态
+ (NSDictionary *)getMicrophoneStatus{
//    VidyoClientRequestGetMuted getAudioInStatus = {0};
//    VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_MUTED_AUDIO_IN, &getAudioInStatus, sizeof(getAudioInStatus));
//
//    VidyoClientRequestGetMuted getServerAudioInStatus = {0};
//    VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_MUTED_SERVER_AUDIO_IN, &getServerAudioInStatus, sizeof(getServerAudioInStatus));
//
//    if (getAudioInStatus.isMuted) {
//        return @{@"type":@(0),@"mute":@(getAudioInStatus.isMuted)};
//    }else if (getServerAudioInStatus.isMuted){
//        return @{@"type":@(1),@"mute":@(getServerAudioInStatus.isMuted)};
//    }
    return nil;
}
#pragma mark + 获取扬声器的状态
+ (NSDictionary *)getSpeakerStatus{
//    VidyoClientRequestGetMuted getSpeakerStatus = {0};
//    VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_MUTED_AUDIO_OUT, &getSpeakerStatus, sizeof(getSpeakerStatus));
//    if (getSpeakerStatus.isMuted) {
//        return @{@"type":@(0),@"mute":@(getSpeakerStatus.isMuted)};
//    }
    return nil;
}
// 是否显示参会者的名字
+ (BOOL)showParticipantName:(int)isShow{
//    VidyoClientRequestConfiguration conf = {0};
//    VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration));
//    conf.enableShowConfParticipantName = isShow;
//    if (VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration)) != VIDYO_CLIENT_ERROR_OK) {
//        return NO;
//    }
    return YES;
}
#pragma mark + applicationWillTerminate
+ (BOOL)stopVideo{
    
//    GNLog(@"stopVideo") ;
//    if (VidyoClientStop() != VIDYO_TRUE) {
//        GNLog(@"VidyoClientStop() returned error");
//        return NO;
//    }
//    videoStop();
    return YES;
}

+ (void)uninitialize{
    GNLog(@"ChitVideoClientUninitialize()");
//    VidyoClientUninitialize();
}

#pragma mark + applicationDidBecomeActive
+ (void)didBecomeActive{
//    VidyoUint error;
//    VidyoClientRequestSetBackground request = {0};
//    request.willBackground = VIDYO_FALSE;
//    if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_BACKGROUND, &request, sizeof(request))) != VIDYO_CLIENT_ERROR_OK) {
//        GNLog(@"problem going to foreground %d", error);
//    }
}

#pragma mark + applicationWillResignActive
+ (void)willResignActive{
//    VidyoUint error;
//    VidyoClientRequestSetBackground request = {0};
//    request.willBackground = VIDYO_TRUE;
//    if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_BACKGROUND, &request, sizeof(request))) != VIDYO_CLIENT_ERROR_OK) {
//        GNLog(@"problem going to background %d", error);
//    }
}
#pragma mark + 运行程序可以在后台运行
+ (BOOL)enableBackground:(BOOL)enable{
    
//    VidyoClientRequestConfiguration conf = { 0 };
//    VidyoUint error;
//    if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration))) != VIDYO_CLIENT_ERROR_OK) {
//        return NO;
//    }
//    else {
//
//        conf.enableBackgrounding = enable;
//        if (VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_CONFIGURATION,
//                                   &conf,
//                                   sizeof(VidyoClientRequestConfiguration))
//            != VIDYO_CLIENT_ERROR_OK) {
//            return NO;
//        }
//    }
    return YES;
}
#pragma mark + 禁掉原生的工具栏
+ (BOOL)enableMenuBar:(BOOL)enable{
//    VidyoClientInEventEnable enableEvent;
//    enableEvent.willEnable = enable;
//    return VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_ENABLE_BUTTON_BAR, &enableEvent, sizeof(VidyoClientInEventEnable));
    
    return YES ;
}
+ (BOOL)enableRedBorder:(BOOL)enable{
//    GNLog(@"SET HIDDEN VIDYO BORDER");
//    VidyoClientRequestSetBorder requestBorder = {0};
//    requestBorder.showBorder = enable;
//    VidyoUint ret = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_PARTICIPANT_BORDER, &requestBorder, sizeof(requestBorder));
//    if (ret != VIDYO_CLIENT_ERROR_OK ) {
//        GNLog(@"Hidden border fail, errorCode:%d",ret);
//    }
//    return ret;
    return YES ;
}
#pragma mark + 是否显示本地视频
+ (BOOL)showPreview:(BOOL)ishow{
    
//    GNLog(@"showPreview %d", ishow) ;
//
//    VidyoClientInEventPreview previewEvent = {0};
//    if (ishow) {
//        // 显示本地视频，PIP模式无效果
//        previewEvent.previewMode = VIDYO_CLIENT_PREVIEW_MODE_DOCK;
//    }else{
//        // 不显示本地视频
//        previewEvent.previewMode = VIDYO_CLIENT_PREVIEW_MODE_NONE;
//    }
//    previewEvent.primaryDisplay = VIDYO_FALSE ;
//    return VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_PREVIEW, &previewEvent, sizeof(VidyoClientInEventPreview));
    
    return YES ;
}
+ (BOOL)showSelfViewLoopback:(BOOL)ishow{
//    VidyoClientRequestConfiguration conf = { 0 };
//    VidyoUint error;
//    if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration))) != VIDYO_CLIENT_ERROR_OK) {
//        return NO;
//    }
//    else {
//        if (ishow) {
//            conf.selfViewLoopbackPolicy = 2;
//        }else{
//            conf.selfViewLoopbackPolicy = 1;
//        }
//        if (VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_CONFIGURATION,
//                                   &conf,
//                                   sizeof(VidyoClientRequestConfiguration))
//            != VIDYO_CLIENT_ERROR_OK) {
//            return NO;
//        }
//    }
    return YES;
}
#pragma mark + 调整视频窗口的大小和位置
+ (BOOL)resizeWithxPos:(int)xPos yPos:(int)yPos width:(int)width andHeight:(int)height{
    
//    VidyoClientInEventResize resizeEvent = {0};
//    // 视频界面的高度
//    resizeEvent.height = height;
//    // 视频界面的宽度
//    resizeEvent.width = width;
//    // 视频界面的x坐标
//    resizeEvent.x = xPos;
//    // 视频界面的y坐标
//    resizeEvent.y = yPos;
//    if (VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_RESIZE, &resizeEvent, sizeof(VidyoClientInEventResize)) != VIDYO_TRUE) {
//        return NO;
//    }else{
//        return YES;
//    }
    return YES ;
}

//#pragma mark + 调整视频横竖屏
//+ (BOOL)setDeviceOrientation:(UIDeviceOrientation)duration;{
//
//    UIInterfaceOrientation orientation=[[UIApplication sharedApplication] statusBarOrientation];
//
//    VidyoClientInEventSetOrientation ori = {0};
//
//    if(UIInterfaceOrientationIsPortrait(orientation)){
//        ori.control = VIDYO_CLIENT_ORIENTATION_CONTROL_BOTH;
//    }else{
//        ori.control = VIDYO_CLIENT_ORIENTATION_CONTROL_CAPTURE;
//    }
//
//    if (duration == UIDeviceOrientationPortrait) {
//        // 竖屏状态（home键在下面）
//        ori.orientation = VIDYO_CLIENT_ORIENTATION_UP;
//
//    }else if (duration == UIDeviceOrientationPortraitUpsideDown){
//        // 竖屏状态（home键在上面）
//
//        ori.orientation = VIDYO_CLIENT_ORIENTATION_DOWN;
//
//    }else if (duration == UIDeviceOrientationLandscapeRight){
//        // 横屏状态（home键在左边）
//
//        ori.orientation = VIDYO_CLIENT_ORIENTATION_LEFT;
//
//    }else if (duration == UIDeviceOrientationLandscapeLeft){
//        // 横屏状态（home键在右边）
//
//        ori.orientation = VIDYO_CLIENT_ORIENTATION_RIGHT;
//
//    }else{
//        // 屏幕朝上或朝下
//        return YES;
//    }
//    return VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_SET_ORIENTATION, &ori, sizeof(VidyoClientInEventSetOrientation));
//}
//+ (BOOL)setInterfaceOrientation:(UIInterfaceOrientation)duration{
//
//    VidyoClientInEventSetOrientation ori = {0};
//
//    //    if(UIInterfaceOrientationIsPortrait(duration)){
//    //        ori.control = VIDYO_CLIENT_ORIENTATION_CONTROL_BOTH;
//    //    }else{
//    ori.control = VIDYO_CLIENT_ORIENTATION_CONTROL_CAPTURE;
//    //    }
//    if (duration == UIInterfaceOrientationPortrait) {
//        // 竖屏状态（home键在下面）
//
//        ori.orientation = VIDYO_CLIENT_ORIENTATION_UP;
//
//    }else if (duration == UIInterfaceOrientationPortraitUpsideDown){
//        // 竖屏状态（home键在上面）
//
//        ori.orientation = VIDYO_CLIENT_ORIENTATION_DOWN;
//
//    }else if (duration == UIInterfaceOrientationLandscapeRight){
//        // 横屏状态（home键在左边）
//
//        ori.orientation = VIDYO_CLIENT_ORIENTATION_RIGHT;
//
//    }else if (duration == UIInterfaceOrientationLandscapeLeft){
//        // 横屏状态（home键在右边）
//
//        ori.orientation = VIDYO_CLIENT_ORIENTATION_LEFT;
//
//    }
//    return VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_SET_ORIENTATION, &ori, sizeof(VidyoClientInEventSetOrientation));
//}
+ (NSDictionary *)getVideoDockCount{
//    VidyoClientRequestParticipants participants = {0};
//    VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_PARTICIPANTS, &participants, sizeof(participants));
//
//    VidyoClientRequestGetDockCounts request;
//    VidyoUint ret = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_DOCK_COUNTS,&request,sizeof(request));
//    NSDictionary * dic;
//    if (ret != VIDYO_CLIENT_ERROR_OK) {
//        dic = @{@"applications":@(0),
//                @"participants":@(0),
//                @"participantsCount":@(0)};
//        return dic;
//    }
//    dic = @{@"applications":@(request.numApplicationsDocked),
//            @"participants":@(request.numParticipantsDocked),
//            @"participantsCount":@(participants.numberParticipants)};
//    return dic;
    
    return nil ;
}
/* Make a participant to always present in the layout. */
+(void)pinParticipant:(NSString*)participantURI pin:(BOOL)pin
{
        
//    VidyoClientInEventSetParticipantVideoMode participantModeEvent = {0};
//
//    if (!participantURI) {
//        GNLog(@"Failed to send VIDYO_CLIENT_IN_EVENT_SET_PARTICIPANT_VIDEO_MODE for participantURI=%@", participantURI);
//        return;
//    }
//
//    strlcpy(participantModeEvent.uri, [participantURI UTF8String],  sizeof(participantModeEvent.uri));
//    participantModeEvent.actionType    = VIDYO_CLIENT_ACTION_TYPE_PIN;
//    /* PINHIGH is to use big picture, PINLOW otherwise */
//    if (pin) {
//        participantModeEvent.videoMode = VIDYO_CLIENT_VIDEO_MODE_PINHIGH;
//    } else {
//        participantModeEvent.videoMode = VIDYO_CLIENT_VIDEO_MODE_DOCK;
//    }
//
//    if (VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_SET_PARTICIPANT_VIDEO_MODE, &participantModeEvent, sizeof(VidyoClientInEventSetParticipantVideoMode)) != VIDYO_TRUE) {
//        GNLog(@"Failed to send VIDYO_CLIENT_IN_EVENT_SET_PARTICIPANT_VIDEO_MODE for participantURI=%@", participantURI);
//        return;
//    }
}
+ (NSArray *)getParticipants{
//    VidyoClientRequestParticipants participants = {0};
//    VidyoUint ret = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_PARTICIPANTS, &participants, sizeof(participants));
//    if (ret == VIDYO_CLIENT_ERROR_OK) {
//        NSMutableArray * perArr = [NSMutableArray array];
//        for (int i = 0; i < participants.numberParticipants; i++) {
//            NSMutableDictionary * dic = [NSMutableDictionary dictionary];
//            NSString * name = [NSString stringWithUTF8String:participants.name[i]];
//            NSString * url = [NSString stringWithUTF8String:participants.URI[i]];
//            [dic setObject:name forKey:@"name"];
//            [dic setObject:url forKey:@"participantUri"];
//            [perArr addObject:dic];
//        }
//        return perArr;
//    }
    return nil;
    
}
+ (NSDictionary *)getMyConferenceInfo{
//    VidyoClientRequestParticipants participants = {0};
//    VidyoUint ret = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_PARTICIPANTS, &participants, sizeof(participants));
//    if (ret == VIDYO_CLIENT_ERROR_OK) {
//        NSMutableArray * urlArr = [NSMutableArray array];
//        for (int j = 0; j < sizeof(participants.URI); j++) {
//            NSString * url = [NSString stringWithUTF8String:participants.URI[j]];
//            if (url.length == 0) {
//                break;
//            }
//            [urlArr addObject:url];
//        }
//        VidyoClientRequestGetPid partictpant = {0};
//        VidyoUint ret1 = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_PID, &partictpant, sizeof(partictpant));
//        if (ret1 == VIDYO_CLIENT_ERROR_OK) {
//            for (int i = 0; i < urlArr.count; i++) {
//                NSString * p = urlArr[i];
//                NSString * containP = [NSString stringWithUTF8String:partictpant.PID];
//                if ([p containsString:containP]) {
//                    VidyoClientRequestParticipantDetailsAt detail = {0};
//                    detail.index = i;
//                    VidyoUint ret2 = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_PARTICIPANT_DETAILS_AT, &detail, sizeof(detail));
//                    if (ret2 == VIDYO_CLIENT_ERROR_OK) {
//                        NSString * particUri = [NSString stringWithUTF8String:detail.details.uri];
//                        NSString * particId = [NSString stringWithUTF8String:detail.details.participantID];
//                        NSDictionary * dic = @{@"participantUri":particUri,@"participantID":particId};
//                        return dic;
//                    }else{
//                        GNLog(@"Failed to send VIDYO_CLIENT_REQUEST_GET_PARTICIPANT_DETAILS_AT,errorCode = %d",ret);
//                    }
//                }
//            }
//        }else{
//            GNLog(@"Failed to send VIDYO_CLIENT_REQUEST_GET_PID,errorCode = %d",ret);
//        }
//    }else{
//        GNLog(@"Failed to send VIDYO_CLIENT_REQUEST_GET_PARTICIPANTS, errorCode = %d",ret);
//    }
    return nil;
}
#pragma mark + 获取共享屏幕数量
+ (id)getShareApplicationInfo{
//    VidyoClientRequestWindowShares request = {0};
//    request.requestType = LIST_SHARING_WINDOWS;
//    VidyoUint ret = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_WINDOW_SHARES,&request,sizeof(request));
//    if (ret != VIDYO_CLIENT_ERROR_OK) {
//        return nil;
//    }
//    NSMutableArray * urlArr = [NSMutableArray array];
//    NSMutableArray * nameArr = [NSMutableArray array];
//    for (int j = 1; j < sizeof(request.shareList.remoteAppUri); j++) {
//        NSString * url = [NSString stringWithUTF8String:request.shareList.remoteAppUri[j]];
//        if (url.length == 0) {
//            break;
//        }
//        [urlArr addObject:url];
//    }
//    for (int i = 1; i < sizeof(request.shareList.remoteAppName); i++) {
//        NSString * name = [NSString stringWithUTF8String:request.shareList.remoteAppName[i]];
//        if (name.length == 0) {
//            break;
//        }
//        [nameArr addObject:name];
//    }
//    NSDictionary *dic = @{@"currApp":@(request.shareList.currApp),
//                          @"newApp":@(request.shareList.newApp),
//                          @"numApp":@(request.shareList.numApp),
//                          @"remoteAppName":nameArr,
//                          @"remoteAppUri":urlArr
//                          };
//    return dic;
    
    return nil ;
}
+ (BOOL)setDisplayName:(NSString *)displayname uri:(NSString *)uri{
//    if (!displayname || !uri) {
//        GNLog(@"Failed to send setDisplayName:displayname or uri can't be null");
//        return NO;
//    }
//    VidyoClientInEventSetDisplayName event = {0};
//    strlcpy(event.displayName, [displayname UTF8String], sizeof(event.displayName));
//    strlcpy(event.uri, [uri UTF8String], sizeof(event.uri));
//    return VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_SET_DISPLAY_NAME,&event,sizeof(event));
    
    return YES ;
}
+ (BOOL)setSelfDisplayName:(NSString *)displayname{
//    if (!displayname) {
//        GNLog(@"Failed to send setDisplayName:displayname can't be null");
//        return NO;
//    }
//    VidyoClientRequestSetLabel setNameEvent = {0};
//    setNameEvent.labelID = VIDYO_CLIENT_LABEL_SELF_VIEW;
//    strlcpy(setNameEvent.labelText, [displayname UTF8String], sizeof(setNameEvent.labelText));
//    VidyoUint ret = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_LABEL,
//                                           &setNameEvent,
//                                           sizeof(VidyoClientRequestSetLabel));
//    if (ret != VIDYO_CLIENT_ERROR_OK) {
//        GNLog(@"Failed to send setDisplayName,error = %d",ret);
//        return NO;
//    }
    return YES;
}
+ (BOOL)setParticipantsLimit:(int)limit {
    
//    GNLog(@"setParticipantsLimit %d", limit) ;
//    VidyoClientInEventParticipantsLimit event = {0};
//    event.maxNumParticipants = limit;
//    VidyoBool ret = VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_PARTICIPANTS_LIMIT, &event, sizeof(event));
//    if (ret) {
//        return YES;
//    }
    return NO;
}
#pragma mark + 显示/隐藏被关闭的参会人视频
+ (void)toggleVideoDock{
//    VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_TOGGLE_VIDEO_DOCK, NULL, 0);
}
#pragma mark + 显示/隐藏被关闭的共享视频
+ (void)toggleApplicationDock{
//    VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_TOGGLE_APPLICATION_DOCK, NULL, 0);
}
+ (void)showApplicationDock:(BOOL)willShow{
//    if (willShow && ![self isApplicationDockVisible]) {
//        [self toggleApplicationDock];
//    }else if (!willShow && [self isApplicationDockVisible]){
//        [self toggleApplicationDock];
//    }
}
+ (void)showParticipantDock:(BOOL)willShow{
//    if (willShow && ![self isParticipantDockVisible]) {
//        [self toggleVideoDock];
//    }else if (!willShow && [self isParticipantDockVisible]){
//        [self toggleVideoDock];
//    }
}
+ (BOOL)isApplicationDockVisible{
//    VidyoClientRequestGetDockCounts request = {0};
//    VidyoUint ret = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_DOCK_COUNTS, &request, sizeof(request));
//    if (ret != VIDYO_CLIENT_ERROR_OK) {
//        GNLog(@"Failed to send VIDYO_CLIENT_REQUEST_GET_DOCK_COUNTS");
//    }
//    return request.isApplicationDockVisible;
    
    return YES ;
}
+ (BOOL)isParticipantDockVisible{
//    VidyoClientRequestGetDockCounts request = {0};
//    VidyoUint ret = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_DOCK_COUNTS, &request, sizeof(request));
//    if (ret != VIDYO_CLIENT_ERROR_OK) {
//        GNLog(@"Failed to send VIDYO_CLIENT_REQUEST_GET_DOCK_COUNTS");
//    }
//    return request.isParticipantDockVisible;
    
    return YES ;
}
+ (BOOL)bestVideoQuality:(BOOL)best{
//#if SDK_VERSION_MODE
//    SDK_ALERT;
//    return NO;
//#else
//    VidyoClientRequestConfiguration conf = { 0 };
//    VidyoUint error;
//    if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration))) != VIDYO_CLIENT_ERROR_OK) {
//
//        return NO;
//
//    }
//    else {
//        if (best) {
//            conf.videoPreferences = VIDYO_CLIENT_VIDEO_PREFERENCES_ADVANCED_720p30;
//        }else{
//            conf.videoPreferences = VIDYO_CLIENT_VIDEO_PREFERENCES_BEST_QUALITY;
//        }
//        if (VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_CONFIGURATION,
//                                   &conf,
//                                   sizeof(VidyoClientRequestConfiguration))
//            != VIDYO_CLIENT_ERROR_OK) {
//
//            return NO;
//        }
//    }
//    return YES;
//#endif
    
    return YES ;
}
+ (void)enableForceProxy:(BOOL)enable{
    
//#if SDK_VERSION_MODE
//    SDK_ALERT;
//#else
//    VidyoClientRequestConfiguration conf = { 0 };
//    VidyoUint error;
//    if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration))) != VIDYO_CLIENT_ERROR_OK) {
//        GNLog(@"Failed to send enableProxy,error = %d",error);
//    }
//    else {
//        VidyoUint error1;
//        if(enable){
//            conf.enableForceProxy = 1;
//            conf.proxySettings = 0x0001;
//        }else{
//            conf.enableForceProxy = 0;
//            conf.proxySettings = 0x0008 | 0x0016;
//        }
//        if ((error1 = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_CONFIGURATION,
//                                             &conf,
//                                             sizeof(VidyoClientRequestConfiguration)))
//            != VIDYO_CLIENT_ERROR_OK) {
//            GNLog(@"Failed to send enableProxy,error = %d",error1);
//        }
//    }
//#endif
}
+ (void)enableProxy:(NSString *)address port:(NSString *)port{
//    if (address.length == 0 || port.length == 0) {
//        GNLog(@"proxyAddress and proxyPort Can't be empty");
//        return;
//    }
//    VidyoClientRequestConfiguration conf = { 0 };
//    VidyoUint error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration));
//    if (error != VIDYO_CLIENT_ERROR_OK) {
//        GNLog(@"Failed to send enableProxy,error = %d",error);
//        return;
//    }
//    else {
//        VidyoUint error1;
//        int settings = 0x0001 | 0x0008 | 0x0020 | 0x0800;
//        strncpy(conf.webProxyAddress, [address UTF8String], sizeof(conf.webProxyAddress));
//        strncpy(conf.webProxyPort, [port UTF8String], sizeof(conf.webProxyPort));
//        conf.enableForceProxy = 1;
//        conf.proxySettings = settings;
//        error1 = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_CONFIGURATION,
//                                        &conf,
//                                        sizeof(VidyoClientRequestConfiguration));
//        if (error1 != VIDYO_CLIENT_ERROR_OK) {
//            GNLog(@"Failed to send enableProxy,error = %d",error1);
//        }
//    }
}
+ (void)disableProxy{
//    VidyoClientRequestConfiguration conf = { 0 };
//    VidyoUint error;
//    if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration))) != VIDYO_CLIENT_ERROR_OK) {
//        GNLog(@"Failed to send disableProxy,error = %d",error);
//        return;
//    }
//    else {
//        VidyoUint error1;
//        int settings = 0x0008 | 0x0016;
//        conf.enableForceProxy = 0;
//        strncpy(conf.webProxyAddress, [@"\0" UTF8String], sizeof(conf.webProxyAddress));
//        strncpy(conf.webProxyPort, [@"\0" UTF8String], sizeof(conf.webProxyPort));
//        conf.proxySettings = settings;
//        error1 = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_CONFIGURATION,
//                                        &conf,
//                                        sizeof(VidyoClientRequestConfiguration));
//        if (error1 != VIDYO_CLIENT_ERROR_OK) {
//            GNLog(@"Failed to send disableProxy,error = %d",error1);
//        }
//    }
}
//+ (void)startShareImage:(UIImage *)image{
//#if SDK_VERSION_MODE
//    SDK_ALERT;
//#else
//    if  ([[self instance] videoStart] == NO ){
//        GNLog(@"Failed: ChitVideo server is not start");
//        return;
//    }
//    if ([self getCallState] != 4) {
//        GNLog(@"Failed: Conference is not active");
//        return;
//    }
//    if ([[self instance] isShareImage]) {
//        GNLog(@"Failed: The pictures are already being Shared.");
//        return;
//    }
//    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
//        //  取出选中的图片
//        
//        NSData * imageData = UIImageJPEGRepresentation(image,0.5);
//        
//        UIImage * image = [UIImage imageWithData:imageData];
//        
//        UIImage * scaleImage = image;
//        
//        scaleImage = [ChitImageHelper fixOrientation:scaleImage];
//        
//        while (scaleImage.size.height > 2500 || scaleImage.size.width > 2500) {
//            scaleImage = [ChitImageHelper scaletoScale:0.5 image:scaleImage];
//        }
//        
//        [[self instance] shareFixImage:scaleImage];
//        
//    });
//#endif
//}
+ (void)readFromAssets:(NSString *)fontPath{
    
//    VidyoClientInEventSetFontFile fontEvent;
//
//    const char *fontFileC= [fontPath cStringUsingEncoding:NSUTF8StringEncoding];
//
//    strncpy(fontEvent.fontFileName, fontFileC, sizeof(fontEvent.fontFileName));
//
//    (void)VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_SET_FONT_FILE, &fontEvent, sizeof(fontEvent));
    
}
//+ (void)stopShareImage{
//    [[self instance]  setValue:@(NO) forKey:NSStringFromSelector(@selector(isShareImage))];
//    GNLog(@"VIDYO_CLIENT_IN_EVENT_UNSHARE");
//    VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_UNSHARE, NULL, 0);
//}
//- (void)shareFixImage:(UIImage *)image{
//
//    VidyoClientInEventShare share = {0};
//    if (VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_SHARE, &share, sizeof(VidyoClientInEventShare)) == false)
//    {
//        [self  setValue:@(NO) forKey:NSStringFromSelector(@selector(isShareImage))];
//        GNLog(@"Failed to send in event VIDYO_CLIENT_IN_EVENT_SHARE");
//        return;
//    }
//    else
//    {
//        [self  setValue:@(YES) forKey:NSStringFromSelector(@selector(isShareImage))];
//        GNLog(@"Successfully sent in event VIDYO_CLIENT_IN_EVENT_SHARE");
//    }
//
//    dispatch_queue_t myQueue = dispatch_queue_create("SharePhotoThreadQueue", NULL);
//
//    dispatch_async(myQueue, ^{
//
//        VidyoClientInEventVideoFrame* vidyoFrame = [CHITVideoService getFrameFromImage:image];
//
//        GNLog(@"width: %d",vidyoFrame->width);
//
//        GNLog(@"height: %d",vidyoFrame->height);
//
//        GNLog(@"size: %d",vidyoFrame->size);
//
//        GNLog(@"format: %d",vidyoFrame->format);
//
//        while([self isShareImage])
//        {
//
//            if (VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_SEND_FRAME, vidyoFrame, sizeof(VidyoClientInEventVideoFrame) + vidyoFrame->size) == false)
//
//            {
//
//                GNLog(@"Failed to send VIDYO_CLIENT_IN_EVENT_SEND_FRAME");
//
//            }
//
//            else
//
//            {
//
//                GNLog(@"Successfully sent VIDYO_CLIENT_IN_EVENT_SEND_FRAME");
//
//            }
//
//            sleep(3);
//        }
//
//    });
//}
//+ (VidyoClientInEventVideoFrame*) getFrameFromImage: (UIImage *) image
//
//{
//
//    VidyoClientInEventVideoFrame* vidyoFrame = NULL;
//    unsigned char *ARGBdata = NULL;
//    unsigned int frameSize;
//    CGImageRef imageRef = image.CGImage;
//    CGSize pixelSize = image.size;
//    // Create a bitmap context to draw the uiimage into
//    CGContextRef context = [ChitImageHelper newBitmapARGB8ContextFromImage:imageRef pixelSize:pixelSize];
//    frameSize = pixelSize.width*pixelSize.height*4;
//    CGRect rect = CGRectMake(0, 0, pixelSize.width, pixelSize.height);
//    // Draw image into the context to get the raw image data
//    CGContextDrawImage(context, rect, imageRef);
//    // Get a pointer to the data
//    ARGBdata = (unsigned char *)CGBitmapContextGetData(context);
//    if (ARGBdata)
//    {
//        GNLog(@"This is ARGBdata");
//
//        for (unsigned int i = 0; i < frameSize; i+=4)
//        {
//            unsigned int temp1 = ARGBdata[i];
//            unsigned int temp2 = ARGBdata[i+1];
//            unsigned int temp3 = ARGBdata[i+2];
//            unsigned int temp4 = ARGBdata[i+3];
//
//            ARGBdata[i+3] = temp3;
//            ARGBdata[i+2] = temp2;
//            ARGBdata[i+1] = temp1;
//            ARGBdata[i] = temp4;
//
//        }
//        vidyoFrame = (VidyoClientInEventVideoFrame*) malloc(sizeof(VidyoClientInEventVideoFrame)+frameSize);
//
//        memset(vidyoFrame, 0, sizeof(VidyoClientInEventVideoFrame));
//
//        memcpy(vidyoFrame->data, ARGBdata, frameSize);
//
//        vidyoFrame->format = 1111970369; //1111970369; //1095911234; // 875704438;//0x41524742
//
//        vidyoFrame->height = pixelSize.height;
//
//        vidyoFrame->width = pixelSize.width;
//
//        vidyoFrame->size = frameSize;
//    }
//    CGContextRelease(context);
//    return vidyoFrame;
//}

+ (VCConnector *)connector {
    
    return vc ;
}

@end
