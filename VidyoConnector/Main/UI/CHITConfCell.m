//
//  CHITConfCell.m
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2018/8/23.
//  Copyright © 2018年 com.changhongit. VidyoSample. All rights reserved.
//

#import "CHITConfCell.h"
#import "NSDate+GNDate.h"

@interface CHITConfCell ()

@property (weak) IBOutlet NSTextField *titleLabel;
@property (weak) IBOutlet NSTextField *participateLabel;
@property (weak) IBOutlet NSTextField *timeLabel;

@end



@implementation CHITConfCell




- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

//- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
//    [super setSelected:selected animated:animated];
//
//    // Configure the view for the selected state
//}

- (void)setConfModel:(HConferenceModel *)confModel {
    
    if (_confModel != confModel) {
        _confModel = confModel ;
        
//        GNLog(@"userNames is %@",_confModel.userNames) ;
        _titleLabel.stringValue = _confModel.subject ? _confModel.subject : _confModel.name ;
        _participateLabel.stringValue = _confModel.userNames ? _confModel.userNames : @"";
//        _timeLabel.stringValue = [NSDate ly_displayTimeWithDate:_confModel.beginTime] ;
    }
}
@end
