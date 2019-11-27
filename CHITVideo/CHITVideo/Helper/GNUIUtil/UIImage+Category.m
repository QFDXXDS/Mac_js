//
//  UIImage+Category.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/6/27.
//  Copyright © 2018年 changhongit. All rights reserved.
//

//#import "UIImage+Category.h"
//
//@implementation UIImage (Category)
//
//
//+ (UIImage *)bundleWithImage:(NSString *)name {
//    
//    NSBundle *bundle = [CTHelper bundle];
//    
//    return [UIImage imageNamed:[@"CHitVideo.bundle/" stringByAppendingString:name] inBundle:bundle compatibleWithTraitCollection:nil] ;
//}
// + (UIImage *)scaleImage:(UIImage *)image toScale:(float)scaleSize
//
// {
//    UIGraphicsBeginImageContext(CGSizeMake(image.size.width * scaleSize, image.size.height * scaleSize));
//    [image drawInRect:CGRectMake(0, 0, image.size.width * scaleSize, image.size.height * scaleSize)];
//    UIImage *scaledImage = UIGraphicsGetImageFromCurrentImageContext();
//                            UIGraphicsEndImageContext();
//    return scaledImage;
//
//}
// + (UIImage *)reSizeImage:(UIImage *)image toSize:(CGSize)reSize
//
// {
//     UIGraphicsBeginImageContext(CGSizeMake(reSize.width, reSize.height));
//     [image drawInRect:CGRectMake(0, 0, reSize.width, reSize.height)];
//     UIImage *reSizeImage = UIGraphicsGetImageFromCurrentImageContext();
//     UIGraphicsEndImageContext();
//    
//     return reSizeImage;
//}
//
//@end
