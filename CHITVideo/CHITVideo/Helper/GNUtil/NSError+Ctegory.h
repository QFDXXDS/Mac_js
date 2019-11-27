//
//  NSError+Ctegory.h
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2018/9/13.
//  Copyright © 2018年 com.changhongit. VidyoSample. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSError (Ctegory)

- (NSError *)wrapperError ;

+ (NSError *)wrapperError:(id )desc ;

@end
