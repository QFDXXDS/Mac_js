//
//  Header.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/1/10.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#ifndef CTHeader_h
#define CTHeader_h

//#define CT_SCREEN_W [[UIScreen mainScreen] bounds].size.width
//#define CT_SCREEN_H [[UIScreen mainScreen] bounds].size.height

#define CT_WEAKSELF    __weak   typeof(self) wSelf = self
#define CT_STRONGSELF  __strong typeof(self) sSelf = wSelf

#define CT_WINDOW [[UIApplication sharedApplication].delegate window]

#define CT_DISPLAYNAME           @"CT_DISPLAYNAME"
#define CT_GLOBAL_CONFERENCEID   @"CT_GLOBAL_CONFERENCEID"
#define CT_CONFERENCEID   @"CT_CONFERENCEID"
#define CT_PARTICIPANTID   @"CT_PARTICIPANTID"


#define CT_USER_ID      @"CT_USER_ID"
#define CT_HTTP_BASEURL     @"CT_HTTP_BASEURL"
#define CT_BASE_DOMAIN  @"CT_BASE_DOMAIN"


#define CT_TOKEN        @"CT_TOKEN"
#define CT_USERID        @"CT_USERID"


#define CT_PARTICIPANTTOKEN        @"participantToken"

#define CT_WS_BASEURL   @"CT_WS_BASEURL"
#define CT_UCCSURL      @"uccsURL"

#define CT_CONFMODE_LECTURE   @"lecture"
#define CT_CONFMODE_GROUP     @"group"

#define CT_ANONYMOUS_PORT     @"11006"

#define CT_CONF_MUTE          @"CT_CONF_MUTE"

#define CT_JISHI_BUNDLE_ID    @"com.vidyo.VidyoConnector"

#define CT_CONF_JSON          @"CT_CONF_JSON"

#define CT_WS_VALUE          @"value"
#define CT_WS_TRANSTD        @"transId"
#define CT_WS_RETURNVALUE    @"returnValue"


#define CT_BACKGROUNDMODE    @"CT_BACKGROUNDMODE"
#define CT_QUANLITYMODE      @"CT_QUANLITYMODE"
#define CT_PROXYMODE         @"CT_PROXYMODE"


#define CT_SOCKET_LINK_SUCCESS    @"CT_SOCKET_LINK_SUCCESS"
#define CT_SOCKET_LINK_LOST       @"CT_SOCKET_LINK_LOST"


#ifdef DEBUG
#define GNLog(...)  NSLog(__VA_ARGS__)

#else
#define GNLog(...) 

#endif

#define CT_ConfStatus  [CTConfStatus shareInstance]


#endif /* Header_h */
