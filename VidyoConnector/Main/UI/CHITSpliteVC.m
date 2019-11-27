//
//  CHITSpliteVC.m
//  VidyoConnector
//
//  Created by Xianxiangdaishu on 2019/6/20.
//  Copyright © 2019 Vidyo. All rights reserved.
//

#import "CHITSpliteVC.h"
#import "CHITSpliteLeftVC.h"
#import "CHITSpliteMiddleVC.h"

@interface CHITSpliteVC ()<NSSplitViewDelegate>

@property (nonatomic,strong)CHITSpliteLeftVC *leftVC ;
@property (nonatomic,strong)CHITSpliteMiddleVC *middleVC ;

@end

@implementation CHITSpliteVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(loginSuccess) name:CHITDidLoginSuccessNotification object:nil];

    _leftVC = self.splitViewItems[0].viewController ;
    _middleVC = self.splitViewItems[1].viewController ;

}

- (void)loginSuccess {
    
    [_leftVC updateView];
    [_middleVC updateView];
}
@end
