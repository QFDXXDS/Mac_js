/**
{file:
	{name: AppSettings.m}
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
#import "AppSettings.h"

@implementation AppSettings

@synthesize host, token, displayName, resourceId, enableDebug, cameraPrivacy, microphonePrivacy, speakerPrivacy, experimentalOptions, hideConfig, autoJoin, allowReconnect, vidyoCloudJoin, portal, roomKey, roomPin;

// - CAUTION: The application delegate class also has a method that checks the
//   names/keys of all supported settings and that lists their default values.
//   Manually compare that method with the one below, to avoid mismatches/bugs.
//
-(void)extract {
    NSUserDefaults *standardDefaults = [NSUserDefaults standardUserDefaults];

    // Extract the host
    NSString *value = [standardDefaults stringForKey:@"host"];
    host = value ? value : @"prod.vidyo.io";

    // Extract the token
    value = [standardDefaults stringForKey:@"token"];
    token = value ? value : @"";

    // Extract the display name
    value = [standardDefaults stringForKey:@"displayName"];
    displayName = value ? value : @"DemoUser";

    // Extract the resource-ID string ("conference" or "room")
    value = [standardDefaults stringForKey:@"resourceId"];
    resourceId = value ? value : @"DemoRoom";

    // Determine whether the configuration should be hidden based on the command line option
    if ( [standardDefaults integerForKey:@"hideConfig"] ) {
        hideConfig = ( [standardDefaults integerForKey:@"hideConfig"] == 1 );
    } else {
        hideConfig = NO; // default value
    }
    // Determine whether auto-join is enabled based on the command line option
    if ( [standardDefaults integerForKey:@"autoJoin"] ) {
        autoJoin = ( [standardDefaults integerForKey:@"autoJoin"] == 1 );
    } else {
        autoJoin = NO; // default value
    }
    // Determine whether allow reconnection after a successful disconnect has occurred based on the command line option
    if ( [standardDefaults integerForKey:@"allowReconnect"] ) {
        allowReconnect = ( [standardDefaults integerForKey:@"allowReconnect"] == 1 );
    } else {
        allowReconnect = YES; // default value
    }
    // Determine whether enableDebug is enabled based on the command line option
    if ( [standardDefaults integerForKey:@"enableDebug"] ) {
        enableDebug = ( [standardDefaults integerForKey:@"enableDebug"] == 1 );
    } else {
        enableDebug = NO; // default value
    }
    // Determine whether cameraPrivacy is enabled based on the command line option
    if ( [standardDefaults integerForKey:@"cameraPrivacy"] ) {
        cameraPrivacy = ( [standardDefaults integerForKey:@"cameraPrivacy"] == 1 );
    } else {
        cameraPrivacy = NO; // default value
    }
    // Determine whether microphonePrivacy is enabled based on the command line option
    if ( [standardDefaults integerForKey:@"microphonePrivacy"] ) {
        microphonePrivacy = ( [standardDefaults integerForKey:@"microphonePrivacy"] == 1 );
    } else {
        microphonePrivacy = NO; // default value
    }
    // Determine whether speakerPrivacy is enabled based on the command line option
    if ( [standardDefaults integerForKey:@"speakerPrivacy"] ) {
        speakerPrivacy = ( [standardDefaults integerForKey:@"speakerPrivacy"] == 1 );
    } else {
        speakerPrivacy = NO; // default value
    }
    // Pass in any experimental options
    value = [standardDefaults stringForKey:@"experimentalOptions"];
    experimentalOptions = value ? value : @"";

    ///////////////////////////////////////////////////////////////////////////////////////
    // Note: the following parameters are used to connect to VidyoCloud systems, not Vidyo.io.

    // Extract the urlHost, portal and roomKey
    vidyoCloudJoin = [[standardDefaults stringForKey:@"urlHost"] isEqualToString:@"join"];
    if (vidyoCloudJoin) {
        value = [standardDefaults stringForKey:@"portal"];
        portal = value ? value : @"";
        value = [standardDefaults stringForKey:@"roomKey"];
        roomKey = value ? value : @"";
        value = [standardDefaults stringForKey:@"roomPin"];
        roomPin = value ? value : @"";
        // Do not display the Vidyo.io form in VidyoCloud mode.
        hideConfig = YES;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
}

-(BOOL)toggleDebug {
    enableDebug = !enableDebug;
    return enableDebug;
}

-(BOOL) toggleCameraPrivacy {
    cameraPrivacy = !cameraPrivacy;
    return cameraPrivacy;
}

-(BOOL) toggleMicrophonePrivacy {
    microphonePrivacy = !microphonePrivacy;
    return microphonePrivacy;
}

-(BOOL) toggleSpeakerPrivacy {
    speakerPrivacy = !speakerPrivacy;
    return speakerPrivacy;
}

@end
