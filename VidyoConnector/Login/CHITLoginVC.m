//
//  CHITLoginVC.m
//  VidyoConnector
//
//  Created by Xianxiangdaishu on 2019/6/17.
//  Copyright © 2019 Vidyo. All rights reserved.
//

#import "CHITLoginVC.h"
#import "CTUserManager.h"
#import "VidyoConnectorAppDelegate.h"


@interface CHITLoginVC ()
@property (weak) IBOutlet NSTextField *accountTF;
@property (weak) IBOutlet NSTextField *passwordTF;

@end

@implementation CHITLoginVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
    
//    self.view.wantsLayer = YES ;
    self.view.layer.backgroundColor = [NSColor whiteColor].CGColor;

}

- (IBAction)onLogin:(NSButton *)sender {
    
    [self rememberUerInfo];

    if (self.accountTF.stringValue.length == 0 || self.passwordTF.stringValue.length == 0) {

        [[CommonUtils shareInstance] alertMessage:@"账号和密码不能为空！"] ;
        return;
    }
    
    [CHITService domain:[VidyoUserDefaults getDefault:PORTAL_DOMAIN]];

    [CTUserManager loginSuccess:^(id results) {
        
        
      [self doLogin];
      [[self.view window] orderOut:nil] ;

    } fail:^(NSError *error) {
        
        [CHITService WSClose];
    }];

}
- (void)rememberUerInfo {
    
    [VidyoUserDefaults setUserDefault:@"userName"
                                value:self.accountTF.stringValue];
    
    [VidyoUserDefaults setUserDefault:@"userPassword"
                                value:self.accountTF.stringValue];
    
}



- (void)doLogin{
    
//    [VidyoUserDefaults setUserDefault:WS_LOGIN value:@(1)];
//    AppDelegate ;
//    [appdelegate toLogin] ;
    
//    NSString *path = [[NSBundle mainBundle] pathForResource:@"CHITVideoBundle" ofType:@"bundle"] ;
//    NSBundle *bundle = [NSBundle bundleWithPath:path];
//    NSWindowController *wc = [[NSStoryboard storyboardWithName:@"Main" bundle:bundle]instantiateControllerWithIdentifier:@"WindowController"] ;
    
    
    
    [VidyoUserDefaults setUserDefault:WS_LOGIN value:@(1)];
    

    VidyoConnectorAppDelegate *delegate = [[NSApplication sharedApplication] delegate] ;
    [delegate windowChanged];
    
    
    
    
    
}



@end
