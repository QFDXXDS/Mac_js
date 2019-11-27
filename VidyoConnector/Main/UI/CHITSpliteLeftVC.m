//
//  CHITSpliteLeftVC.m
//  VidyoConnector
//
//  Created by Xianxiangdaishu on 2019/7/2.
//  Copyright © 2019 Vidyo. All rights reserved.
//

#import "CHITSpliteLeftVC.h"

@interface CHITSpliteLeftVC ()

@property (weak) IBOutlet NSTextField *nameLabel;

@end

@implementation CHITSpliteLeftVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
    

    
}
- (void)updateView {
    
    _nameLabel.stringValue = [CTUserManager name] ;

}

@end
