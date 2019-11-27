//
//  GNWSReq.h
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/2/2.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GNWSReq : NSObject <GNWSProtocol>

@property (nonatomic,copy)NSString *opt;

@property (nonatomic,copy)NSString *name;


@end

//@interface GNWSHeartReq : GNWSReq
//
//
//@property (nonatomic,copy)NSString *status;
//
//@property (nonatomic,copy)NSString *id;
//
//@end


@interface CHITKeepAliveRequest : GNWSReq



@end
