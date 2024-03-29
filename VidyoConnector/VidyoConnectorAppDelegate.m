/**
{file:
	{name: VidyoConnectorAppDelegate.m}
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
#import "VidyoConnectorAppDelegate.h"
#import "CHITMainWC.h"


@interface VidyoConnectorAppDelegate()

@property (nonatomic,strong)NSStatusItem *item;
@property (nonatomic,strong)NSPopover * popover;


@end

@implementation VidyoConnectorAppDelegate


- (NSStatusItem *)item {
    
    if (!_item) {
        
        _item = [[NSStatusBar systemStatusBar] statusItemWithLength:NSVariableStatusItemLength] ;
        [_item.button setImage:[NSImage imageNamed:@"statusBarLove"]] ;
        _item.target = self ;
        _item.button.action = @selector(showMyPopover:) ;
    }
    return _item ;
}
- (NSPopover *)popover {
    
    if (!_popover) {
        _popover = [[NSPopover alloc]init] ;
        _popover.behavior = NSPopoverBehaviorTransient ;
        _popover.appearance = [NSAppearance appearanceNamed:NSAppearanceNameVibrantLight];
        
        NSViewController *vc = [[NSStoryboard storyboardWithName:@"Main" bundle:nil]instantiateControllerWithIdentifier:@"CHITLoginConfigVC"] ;
        _popover.contentViewController = vc ;
    }
    return _popover ;
}
- (void)showMyPopover:(NSStatusBarButton *) sender {
    
    [_popover showRelativeToRect:sender.bounds ofView:sender preferredEdge:NSRectEdgeMaxY];
}


/* This application implements a custom URL (scheme) handler.
    Refer to Xcode Help -> "OS X 10.11.4 Documentation" -> "Cocoa Scripting Guide" -> "Installing an Apple Event Handler" at...
    <xcdoc://?url=developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_handle_AEs/SAppsHandleAEs.html#>.
    See the subsections about the "Get URL Handler".
 */
- (void)handleGetURLEvent:(NSAppleEventDescriptor *)event withReplyEvent:(NSAppleEventDescriptor *)replyEvent {
    // Extract the URL from the Apple event and handle it here.
    NSURL *url = [NSURL URLWithString:[[event paramDescriptorForKeyword:keyDirectObject] stringValue]];

    
    // Prepare to store the parsed query in a temporary/interim dictionary.
    // - Initialize it with all preferences/settings that this app supports/allows,
    //   along with their default values, regardless of what the URL might provide.
    NSMutableDictionary *pairs = [NSMutableDictionary dictionaryWithDictionary:
                                  @{
                                        @"host" : @"prod.vidyo.io",

                                        @"token" : @"",
                                        @"displayName" : @"DemoUser",
                                        @"resourceId" : @"DemoRoom",
                                        @"hideConfig" : @0,
                                        @"autoJoin" : @0,
                                        @"allowReconnect" : @1,
                                        @"enableDebug" : @0,
                                        @"cameraPrivacy" : @0,
                                        @"microphonePrivacy" : @0,
                                        @"speakerPrivacy" : @0,
                                        @"experimentalOptions" : @"",
                                        @"urlHost" : @"", // Used for VidyoCloud systems, not Vidyo.io
                                        @"portal" : @"",  // Used for VidyoCloud systems, not Vidyo.io
                                        @"roomKey" : @"", // Used for VidyoCloud systems, not Vidyo.io
                                        @"roomPin" : @""  // Used for VidyoCloud systems, not Vidyo.io
                                    }];

    // Parse the query string from the URL.
    // - Split the query into an array of field-value pairs, like name-value pairs.
    // - Traverse that array, parse each field-value pair, and store valid results.
    NSString *query = [url query];
    NSLog(@"URL query string is '%@'.", query);
    NSArray *queryPairs = [query componentsSeparatedByString:@"&"];
    for (NSString *queryPair in queryPairs) {
        NSArray *halves = [queryPair componentsSeparatedByString:@"="];
        if ([halves count] != 2) {
            // Error: Field-value pair is invalid, likely incomplete. Skip it.
            NSLog(@"URL query: Ignored invalid field-value pair '%@'.", queryPair);
            continue;
        }
        // Create a candidate key-value pair from the parsed field-value pair.
        NSString *key = [[halves objectAtIndex:0] stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        NSString *value = [[halves objectAtIndex:1] stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        NSLog(@"URL query: Checking key-value pair '%@'='%@'....", key, value);

        // Prepare to apply the candidate key-value pair to the interim dictionary.
        if (nil == [pairs valueForKey:key]) {
            // Error: The candidate key doesn't match any existing keys among the defaults.
            // ...Therefore, the candidate key is irrelevant, and so is its associated value.
            NSLog(@"URL query: Ignored unknown field/key '%@' with value '%@'.", key, value);
            continue;
        }
        // Apply the candidate key-value pair to the interim dictionary.
        // - CAUTION: The value can be INVALID, because it has not been checked.
        [pairs setValue:value forKey:key];
        NSLog(@"URL query: Parsed key-value pair '%@'='%@'.", key, value);
    }

    // Populate the "urlHost" if the host exists in the URL.
    // Note: this is used for VidyoCloud systems, not Vidyo.io.
    if ([url host]) {
        [pairs setValue:[url host] forKey:@"urlHost"];
    }

    NSLog(@"URL query: Final %lu key-value pairs %@.", (unsigned long)[pairs count], [pairs description]);

    // Apply the candidate key-value pairs to the shared preferences database.
    // - Apply them to the temporary, high-precedence "arguments domain".
    //   -- Because any settings/preferences from a custom URL should not persist.
    //   -- Because URL-based settings and command-line arguments seem mutually exclusive.
    [[NSUserDefaults standardUserDefaults] removeVolatileDomainForName:NSArgumentDomain];
    [[NSUserDefaults standardUserDefaults] setVolatileDomain:pairs forName:NSArgumentDomain];
    NSLog(@"URL query: Applied final key-value pairs to shared preferences.");

    // Notify the VidyoViewController of the URL event
    [[NSNotificationCenter defaultCenter] postNotificationName:@"handleGetURLEvent" object:nil];
}

-(NSWindow *)window1{
    
    if (!_window1) {
        
//        NSUInteger style = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable ;
//
//        _window1 = [[NSWindow alloc]initWithContentRect:CGRectMake(0, 0, 200, 300) styleMask:style backing:NSBackingStoreBuffered defer:YES];
        
        NSString *path = [[NSBundle mainBundle] pathForResource:@"CHITVideoBundle" ofType:@"bundle"] ;
        NSBundle *bundle = [NSBundle bundleWithPath:path];
        NSWindowController *wc = [[NSStoryboard storyboardWithName:@"Main" bundle:bundle]instantiateControllerWithIdentifier:@"WindowController"] ;

        _window1 = wc.window ;
    }
    
    return _window1;
    
}


- (void)applicationWillFinishLaunching:(NSNotification *)aNotification {
    // Install an Apple event handler to work with URL events.
    NSAppleEventManager *appleEventManager = [NSAppleEventManager sharedAppleEventManager];
    [appleEventManager setEventHandler:self
                           andSelector:@selector(handleGetURLEvent:withReplyEvent:)
                         forEventClass:kInternetEventClass
                            andEventID:kAEGetURL];
    
    [self windowChanged];
    [CHITService initialize:YES view:nil];
    
//    [self item] ;
//    [self popover];

}

//- (void)applicationDidFinishLaunching:(NSNotification *)notification {
//
//m
////    [self.window1 center];
////    [self.window1 orderFront:nil] ;
//
//
//}

//  所有窗口关闭了回调该方法
- (void)applicationWillTerminate:(NSNotification *)notification {
    // Uninstall any Apple event handler intended for URL events.
    NSAppleEventManager *appleEventManager = [NSAppleEventManager sharedAppleEventManager];
    [appleEventManager removeEventHandlerForEventClass:kInternetEventClass
                                            andEventID:kAEGetURL];
    
    
}

// Terminate the application after the window is closed
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    return NO;
}

- (BOOL)applicationShouldHandleReopen:(NSApplication *)sender hasVisibleWindows:(BOOL)flag {
    
    NSLog(@"hasVisibleWindows:%d",flag);
    [NSApp activateIgnoringOtherApps:NO];//取消其他程序的响应
    [self.mainWindowVC.window makeKeyAndOrderFront:self];//主窗口显示自己方法一
    //[_mainWindow orderFront:nil];           //主窗口显示自己方法二
  
    return YES ;
}

- (void)windowChanged {
    
    id login = [VidyoUserDefaults getUserDefault:WS_LOGIN];
    
    if  (!login){
        
        
        [_mainWindowVC.window orderOut:nil];
        
        NSWindowController *wc = [[NSStoryboard storyboardWithName:@"Main" bundle:nil]instantiateControllerWithIdentifier:@"CHITMainWC"] ;
        _mainWindowVC = wc ;
        [_mainWindowVC.window orderFront:nil];
    
        
    } else {
        
        if(![CTUserManager isLogin]) [CTUserManager loginSuccess:nil fail:nil];
        
        NSWindowController *wc = [[NSStoryboard storyboardWithName:@"Main" bundle:nil]instantiateControllerWithIdentifier:@"NSSpliteWC"] ;
        _mainWindowVC = wc ;
        [_mainWindowVC.window orderFront:nil];
    }
}
@end
