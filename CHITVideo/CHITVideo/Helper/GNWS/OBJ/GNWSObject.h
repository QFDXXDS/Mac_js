//
//  GNWSObject.h
//  GN-OC
//
//  Created by Xianxiangdaishu on 2018/1/15.
//  Copyright © 2018年 XXDS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SocketRocket.h"

typedef  NS_ENUM(NSUInteger) {
    
    HeartCheckEvent,
    ReconnectEvent,
}SocketEvent;

@interface GNWSObject : NSObject

@property (nonatomic,copy)void (^socketEventBlock)(SocketEvent event,BOOL excut);
@property (nonatomic,assign)BOOL isConnect;    //连接状态

- (void)WSConnectWithURLString:(NSString *)URLString ;

- (void)WSSendString:(NSString *)string ;

- (void)close ;

@end
