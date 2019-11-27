//
//  CurrentCalledModel.h
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2018/1/18.
//  Copyright © 2018年 com.changhongit. VidyoSample. All rights reserved.
//



@interface CurrentCalledModel : NSObject

@property (nonatomic,copy)NSString *internalID;  //备点名的coss系统ID
@property (nonatomic,copy)NSString *displayName;  //被点名的显示名
@property (nonatomic,copy)NSString *userTerminalType;  //被点名的终端类型

@property (nonatomic,copy)NSString *participantID;  //被点名的participantID

@property (nonatomic,copy)NSString *participantURI;  //被点名的participantURI



@end
