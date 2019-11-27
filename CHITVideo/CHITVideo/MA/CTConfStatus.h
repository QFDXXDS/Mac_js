//
//  CTConfStatus.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/2/8.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTConfDetailModel.h"

@interface CTConfStatus : NSObject

@property (nonatomic,assign)BOOL didInterSDKBool;   // 是否进入SDK标识

@property (nonatomic,assign)BOOL didInterConfBool;   // 是否进入会议标识

@property (nonatomic,assign)BOOL isConfOwner;   // 是否是自己的会议室、会议

@property (nonatomic,assign)BOOL isLock;   // 是会议室是否被锁

@property (nonatomic,assign)BOOL isLogin;   // 用户是否已登录

@property (nonatomic,assign)BOOL isUploadURIBool;   // 用户上传URI

@property (nonatomic,assign)BOOL isCreateConf;   // 是否是我创建的会议

@property (nonatomic,assign)BOOL isPVConf;   // 是否是我创建的会议

@property (nonatomic,copy)NSString *whiteBoardSessionURL;   // 白板地址



@property (nonatomic,strong)CTConfDetailModel *detailModel;

@property (nonatomic,copy)NSString *confMode;

+ (instancetype)shareInstance ;


@end
