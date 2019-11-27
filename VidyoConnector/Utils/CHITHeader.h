//
//  CHITHeader.h
//  VidyoConnector
//
//  Created by Xianxiangdaishu on 2019/6/17.
//  Copyright © 2019 Vidyo. All rights reserved.
//

#ifndef CHITHeader_h
#define CHITHeader_h

#define Screen_W [[UIScreen mainScreen] bounds].size.width
#define Screen_H [[UIScreen mainScreen] bounds].size.height

#define WeakSelf __weak typeof(self) wSelf = self
#define StroSelf __strong typeof (self) sSelf = wSelf

#define AppDelegate CHITAppDelegate * appdelegate = (CHITAppDelegate *)[UIApplication sharedApplication].delegate

#define Base_Url [NSString stringWithFormat:@"%@/index.php",[VidyoUserDefaults getPortalfaultAtIndex:@(0)]]

#define WS_LOGIN @"WS_LOGIN"

#define CT_CURRENT_LANGUAGE @"CT_CURRENT_LANGUAGE"
#define CT_APPLE_LANGUAGE @"AppleLanguages"

#define CT_CONF_LINK  @"byshang.cn/#/roomDirect"


#define PORTAL_DOMAIN @"PORTAL_DOMAIN"


#ifdef DEBUG
#define GNLog(...)  NSLog(__VA_ARGS__)

#else
#define GNLog(...)

#endif

#endif /* CHITHeader_h */
