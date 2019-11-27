//
//  CTConfDetailModel.h
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2018/1/8.
//  Copyright © 2018年 com.changhongit. VidyoSample. All rights reserved.
//

#import "RoomModel.h"
#import "RoomStatusModel.h"


@interface CTConfDetailModel : NSObject

@property (nonatomic,strong)RoomModel  * room;

@property (nonatomic,strong)RoomStatusModel * roomStatus;


@end
