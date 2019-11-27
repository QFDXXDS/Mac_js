//
//  GNWSObject.m
//  GN-OC
//
//  Created by Xianxiangdaishu on 2018/1/15.
//  Copyright © 2018年 XXDS. All rights reserved.
//

#import "GNWSObject.h"
#import "GNWSRsp.h"

@interface GNWSObject() <SRWebSocketDelegate>

@property (nonatomic,strong)SRWebSocket * webSocket;

@end

@implementation GNWSObject

- (void)dealloc {
    
    [[NSNotificationCenter defaultCenter]removeObserver:self] ;
}

- (instancetype)init {
    
    if (self = [super init] ) {
        [self setConfig];
    }
    return self ;
}
- (void)setConfig {
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(responseTimeout) name:GNWSResponseTimeoutNotification object:nil];
}
- (void)responseTimeout {
    
    [_webSocket close];
    _socketEventBlock(HeartCheckEvent,NO);
    _socketEventBlock(ReconnectEvent,YES);
    
}
- (BOOL)isConnect {
    
    if (_webSocket.readyState == SR_OPEN) {
        return YES;
    } else {
        return NO ;
    }
}
- (void)WSConnectWithURLString:(NSString *)URLString {

    [self close];
    
    GNLog(@"WSConnectWithURLString %@",URLString);
    _webSocket = [[SRWebSocket alloc] initWithURL:[NSURL URLWithString:URLString]];
    _webSocket.delegate = self;
    [_webSocket open];
}
- (void)WSSendString:(NSString *)string {
    
    
    [_webSocket send:string];

    [[NSNotificationCenter defaultCenter]postNotificationName:GNLocalLogNotification object:string];
}

- (void)close {
    
    [_webSocket close];
    _webSocket.delegate = nil;
    _webSocket = nil;
}

#pragma mark socket代理
- (void)webSocketDidOpen:(SRWebSocket *)webSocket{
    
    GNLog(@"webSocketDidOpen:(SRWebSocket *)webSocket");

    _socketEventBlock(HeartCheckEvent,YES);
    _socketEventBlock(ReconnectEvent,NO);
    
    [[NSNotificationCenter defaultCenter]postNotificationName:GNWSLinkSuccessNotification object:nil];
}
- (void)webSocket:(SRWebSocket *)webSocket didFailWithError:(NSError *)error{
    
    _socketEventBlock(HeartCheckEvent,NO);
    _socketEventBlock(ReconnectEvent,YES);
}
// 主动关闭不会调用该代理
- (void)webSocket:(SRWebSocket *)webSocket didCloseWithCode:(NSInteger)code reason:(NSString *)reason wasClean:(BOOL)wasClean{
    
    _socketEventBlock(HeartCheckEvent,NO);
    _socketEventBlock(ReconnectEvent,YES);
    
}

- (void)webSocket:(SRWebSocket *)webSocket didReceiveMessage:(id)message{
    
    [GNWSRsp WSReciveMessage:message];
    [[NSNotificationCenter defaultCenter]postNotificationName:GNLocalLogNotification object:message];

}

@end
