/**
{file:
	{name: VidyoConnectorAppDelegate.h}
	{description: .}
	{copyright:
		(c) 2017-2018 Vidyo, Inc.,
		433 Hackensack Avenue, 7th Floor,
		Hackensack, NJ  07601.

		All rights reserved.

		The information contained herein is proprietary to Vidyo, Inc.
		and shall not be reproduced, copied (in whole or in part), adapted,
		modified, disseminated, transmitted, transcribed, stored in a retrieval
		system, or translated into any language in any form by any means
		without the express written consent of Vidyo, Inc.
		                  ***** CONFIDENTIAL *****
	}
}
*/
#ifndef VIDYOCONNECTORAPPDELEGATE_H_INCLUDED
#define VIDYOCONNECTORAPPDELEGATE_H_INCLUDED

#import <Cocoa/Cocoa.h>

@interface VidyoConnectorAppDelegate : NSObject <NSApplicationDelegate>

@property(nonatomic,strong) NSWindow *window1;

@property (nonatomic,strong)NSWindowController *mainWindowVC ;

- (void)windowChanged ;

@end




#endif // VIDYOCONNECTORAPPDELEGATE_H_INCLUDED
