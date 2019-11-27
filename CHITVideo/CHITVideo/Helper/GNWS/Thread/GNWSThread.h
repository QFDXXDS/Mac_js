//
//  GNWSThread.h
//  CHITVideo  
//
//  Created by Xianxiangdaishu on 2018/11/22.
//  Copyright © 2018 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface GNWSThread : NSThread

@property (nonatomic,strong)NSTimer *heartTimer;   //心跳timer

@property (nonatomic,strong)NSTimer *connectTimer;   //检测连接timer

@property (nonatomic,strong)NSTimer *responseTimer;   //响应超时检查

@end

