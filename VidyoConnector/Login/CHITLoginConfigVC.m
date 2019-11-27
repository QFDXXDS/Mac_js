//
//  CHITLoginConfigVC.m
//  VidyoConnector
//
//  Created by Xianxiangdaishu on 2019/6/19.
//  Copyright © 2019 Vidyo. All rights reserved.
//

#import "CHITLoginConfigVC.h"

@interface CHITLoginConfigVC ()

@property (weak) IBOutlet NSTextField *addressTF;

@property (weak) IBOutlet NSTextField *portTF;

@end

@implementation CHITLoginConfigVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
}


- (IBAction)onSave:(NSButton *)sender {
    
    if ((_addressTF.stringValue.length == 0 ) || (_portTF.stringValue.length == 0)) {
        
        [[CommonUtils shareInstance] alertMessage:@"地址和端口不能为空！"] ;
        return ;
    }
    
    [VidyoUserDefaults setDefault:PORTAL_DOMAIN value:@"cossdev.byshang.cn"];
    [self dismissController:nil];
}


@end
