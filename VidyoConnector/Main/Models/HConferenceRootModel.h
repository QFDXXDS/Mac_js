//
//  HConferenceRootModel.h
//  VidyoSample
//
//  Created by user on 17/4/23.
//  Copyright © 2017年 com.changhongit. VidyoSample. All rights reserved.
//

#import <JSONModel/JSONModel.h>
#import "HConferenceModel.h"
@interface HConferenceRootModel : JSONModel

@property (nonatomic,strong)NSArray<HConferenceModel,Optional> * conferenceList;

@property (nonatomic,strong)NSArray<HConferenceModel,Optional> * content;

@property (nonatomic,strong)NSArray<HConferenceModel,Optional> * conferences;



@end
