//
//  CHITMainWC.m
//  VidyoConnector
//
//  Created by Xianxiangdaishu on 2019/6/20.
//  Copyright © 2019 Vidyo. All rights reserved.
//

#import "CHITMainWC.h"

@interface CHITMainWC ()

@end

@implementation CHITMainWC

- (void)windowDidLoad {
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
    
 
    
//    self.window.title = @"聊天";
//    // 隐藏标题
//    self.window.titlebarAppearsTransparent = YES;
//    self.window.titleVisibility = NSWindowTitleHidden;
    //设置类型
//    self.window.styleMask = NSWindowStyleMaskFullSizeContentView|NSWindowStyleMaskTitled|NSWindowStyleMaskResizable|NSWindowStyleMaskMiniaturizable|NSWindowStyleMaskClosable;
    
//    window?.styleMask = [.fullSizeContentView,.titled,.resizable,.miniaturizable,.closable]

    //设置代理
//    self.window.delegate = self;
    //设置点击背景可以拖动窗口
    [self.window setMovableByWindowBackground:YES];
    
    
    NSButton *zoomBtn = [self.window standardWindowButton:NSWindowZoomButton];
    NSButton *minBtn = [self.window standardWindowButton:NSWindowMiniaturizeButton];

    [zoomBtn removeFromSuperview];
}

@end
