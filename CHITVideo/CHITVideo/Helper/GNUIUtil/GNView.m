//
//  GNView.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/6/1.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import "GNView.h"

@implementation GNView
{
    NSView *view ;
}
/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/
- (instancetype)initWithCoder:(NSCoder *)aDecoder{
    if (self = [super initWithCoder:aDecoder]) {
        [self initial];
    }
    return self;
}
- (instancetype)initWithFrame:(CGRect)frame{
    if (self = [super initWithFrame: frame]) {
        [self initial];
    }
    return self;
}
//通过xib构建View调用该方法
- (void)initial{
    
//    view = [[[CTHelper bundle] loadNibNamed:NSStringFromClass([self class]) owner:self options:nil] firstObject];
//    view.frame = self.bounds;
//    [self addSubview:view];
//    [self createView];
}
- (void)createView {
    
    
}

@end
