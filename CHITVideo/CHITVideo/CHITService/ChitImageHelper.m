/*
 * The MIT License
 *
 * Copyright (c) 2011 Paul Solt, PaulSolt@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

//#import "ChitImageHelper.h"
//
//
//@implementation ChitImageHelper
//
///*
//+ (unsigned char *) convertUIImageToBitmapARGB8:(UIImage *) image {
//    
//    CGImageRef imageRef = image.CGImage;
//    
//    // Create a bitmap context to draw the uiimage into
//    CGContextRef context = [self newBitmapARGB8ContextFromImage:imageRef];  //createARGBBitmapContextFromImage
////    CGContextRef context = [self createARGBBitmapContextFromImage:imageRef];
//    if(!context) {
//        return NULL;
//    }
//    
//    size_t width = CGImageGetWidth(imageRef);
//    size_t height = CGImageGetHeight(imageRef);
//    
//    CGRect rect = CGRectMake(0, 0, width, height);
//    
//    // Draw image into the context to get the raw image data
//    CGContextDrawImage(context, rect, imageRef);
//    
//    // Get a pointer to the data    
//    unsigned char *bitmapData = (unsigned char *)CGBitmapContextGetData(context);
//    
////    // Copy the data and release the memory (return memory allocated with new)
////    size_t bytesPerRow = CGBitmapContextGetBytesPerRow(context);
////    size_t bufferLength = bytesPerRow * height;
////    
////    unsigned char *newBitmap = NULL;
////    
////    if(bitmapData) {
////        newBitmap = (unsigned char *)malloc(sizeof(unsigned char) * bytesPerRow * height);
////        
////        if(newBitmap) {    // Copy the data
////            for(int i = 0; i < bufferLength; ++i) {
////                newBitmap[i] = bitmapData[i];
////            }
////        }
////        
////        free(bitmapData);
////        
////    } else {
////        GNLog(@"Error getting bitmap pixel data\n");
////    }
////    
//    CGContextRelease(context);
//    
////    return newBitmap;    
//    return bitmapData;
//}
//*/
//
//
//+ (CGContextRef) newBitmapARGB8ContextFromImage:(CGImageRef)image pixelSize:(CGSize)size;
//{
//    CGContextRef context = NULL;
//    CGColorSpaceRef colorSpace = CGImageGetColorSpace(image);
////    uint32_t *bitmapData;
//    
//    size_t bitsPerPixel = CGImageGetBitsPerPixel(image);
//    size_t bitsPerComponent = CGImageGetBitsPerComponent(image);
//    size_t bytesPerPixel = bitsPerPixel / bitsPerComponent;
//    
////    size_t width = CGImageGetWidth(image);
////    size_t height = CGImageGetHeight(image);
//    
//    size_t bytesPerRow = size.width * bytesPerPixel;
////    size_t bufferLength = bytesPerRow * height;
//    
////    colorSpace = CGColorSpaceCreateDeviceRGB();
//
////    if(!colorSpace) {
////        GNLog(@"Error allocating color space RGB\n");
////        return NULL;
////    }
//    
//    // Allocate memory for image data
////    bitmapData = (uint32_t *)malloc(bufferLength);
//    
////    if(!bitmapData) {
////        GNLog(@"Error allocating memory for bitmap\n");
////        CGColorSpaceRelease(colorSpace);
////        return NULL;
////    }
//    
//    //Create bitmap context
//    context = CGBitmapContextCreate(NULL,
//                                    size.width,
//                                    size.height,
//                                    bitsPerComponent, 
//                                    bytesPerRow, 
//                                    colorSpace, 
//                                    kCGImageAlphaPremultipliedLast);
//    
//    if (!context) {
//        return NULL;
//    }
//    
//    return context;    
//}
//
//
//+ (UIImage *) convertBitmapARGB8ToUIImage:(unsigned char *) buffer 
//                                withWidth:(int) width
//                               withHeight:(int) height 
//{
//
//    size_t bufferLength = width * height * 4;
//    
//    
////    for (unsigned int i = 0; i < bufferLength; i+=4) 
////    {
////        unsigned int temp = buffer[i];
////        buffer[i] = buffer[i+2];                 //r -> b
////        buffer[i+2] = temp;             //b -> r
////    }
//    
//
//    CGDataProviderRef provider = CGDataProviderCreateWithData(NULL, buffer, bufferLength, NULL);
//    size_t bitsPerComponent = 8;
//    size_t bitsPerPixel = 32;
//    size_t bytesPerRow = 4 * width;
//    
//    CGColorSpaceRef colorSpaceRef = CGColorSpaceCreateDeviceRGB();
//    if(colorSpaceRef == NULL) {
//        GNLog(@"Error allocating color space");
//        CGDataProviderRelease(provider);
//        return nil;
//    }
////    CGBitmapInfo bitmapInfo =  kCGBitmapByteOrderDefault | kCGImageAlphaPremultipliedLast; //
//    CGBitmapInfo bitmapInfo = kCGBitmapByteOrder32Host | kCGImageAlphaNoneSkipFirst;
//    CGColorRenderingIntent renderingIntent = kCGRenderingIntentDefault;
//    
//    CGImageRef iref = CGImageCreate(width,height,bitsPerComponent,bitsPerPixel,bytesPerRow,colorSpaceRef,bitmapInfo,provider,NULL,YES,renderingIntent);
//        
//    uint32_t* pixels = (uint32_t*)malloc(bufferLength);
//    
//    if(pixels == NULL) {
//        GNLog(@"Error: Memory not allocated for bitmap");
//        CGDataProviderRelease(provider);
//        CGColorSpaceRelease(colorSpaceRef);
//        CGImageRelease(iref);        
//        return nil;
//    }
//    CGContextRef context = CGBitmapContextCreate(pixels, width,height,bitsPerComponent,bytesPerRow,colorSpaceRef,bitmapInfo);
//    
//    if(context == NULL) {
//        GNLog(@"Error context not created");
//        free(pixels);
//        pixels = nil;
//    }
//    
//    UIImage *image = nil;
//    if(context) {
//        
//        CGContextDrawImage(context, CGRectMake(0.0f, 0.0f, width, height), iref);
//                CGImageRef imageRef = CGBitmapContextCreateImage(context);
//        
//        // Support both iPad 3.2 and iPhone 4 Retina displays with the correct scale
//        if([UIImage respondsToSelector:@selector(imageWithCGImage:scale:orientation:)]) {
//            float scale = [[UIScreen mainScreen] scale];
//            image = [UIImage imageWithCGImage:imageRef scale:scale orientation:UIImageOrientationUp];
//        } else {
//            image = [UIImage imageWithCGImage:imageRef];
//        }
//        
//        CGImageRelease(imageRef);    
//        CGContextRelease(context);    
//    }
//    
//    CGColorSpaceRelease(colorSpaceRef);
//    CGImageRelease(iref);
//    CGDataProviderRelease(provider);
//    
//    if(pixels) {
//        free(pixels);
//    }    
//    //UIImageWriteToSavedPhotosAlbum(image, self, @selector(image:didFinishSavingWithError:contextInfo:), nil);
//    return image;
//}
//
//- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo
//{    
//    
//    UIAlertView *alert;
//    
//    
//    if (error)
//        alert = [[UIAlertView alloc] initWithTitle:@"Error" 
//                                           message:@"Unable to save image to Photo Album." 
//                                          delegate:self cancelButtonTitle:@"Ok" 
//                                 otherButtonTitles:nil];
//    else 
//        alert = [[UIAlertView alloc] initWithTitle:@"Success" 
//                                           message:@"Image saved to Photo Album." 
//                                          delegate:self cancelButtonTitle:@"Ok" 
//                                 otherButtonTitles:nil];
//    [alert show];
//}
//+ (UIImage *)fixOrientation:(UIImage *)image
//{
//    if (image.imageOrientation == UIImageOrientationUp)
//        return image;
//    
//    CGAffineTransform transform = CGAffineTransformIdentity;
//    
//    switch (image.imageOrientation) {
//        case UIImageOrientationDown:
//        case UIImageOrientationDownMirrored:
//            transform = CGAffineTransformTranslate(transform, image.size.width, image.size.height);
//            transform = CGAffineTransformRotate(transform, M_PI);
//            break;
//            
//        case UIImageOrientationLeft:
//        case UIImageOrientationLeftMirrored:
//            transform = CGAffineTransformTranslate(transform, image.size.width, 0);
//            transform = CGAffineTransformRotate(transform, M_PI_2);
//            break;
//            
//        case UIImageOrientationRight:
//        case UIImageOrientationRightMirrored:
//            transform = CGAffineTransformTranslate(transform, 0, image.size.height);
//            transform = CGAffineTransformRotate(transform, -M_PI_2);
//            break;
//        default:
//            break;
//    }
//    
//    switch (image.imageOrientation) {
//        case UIImageOrientationUpMirrored:
//        case UIImageOrientationDownMirrored:
//            transform = CGAffineTransformTranslate(transform, image.size.width, 0);
//            transform = CGAffineTransformScale(transform, -1, 1);
//            break;
//            
//        case UIImageOrientationLeftMirrored:
//        case UIImageOrientationRightMirrored:
//            transform = CGAffineTransformTranslate(transform, image.size.height, 0);
//            transform = CGAffineTransformScale(transform, -1, 1);
//            break;
//        default:
//            break;
//    }
//    
//    CGContextRef ctx = CGBitmapContextCreate(NULL, image.size.width, image.size.height,
//                                             CGImageGetBitsPerComponent(image.CGImage), 0,
//                                             CGImageGetColorSpace(image.CGImage),
//                                             CGImageGetBitmapInfo(image.CGImage));
//    CGContextConcatCTM(ctx, transform);
//    switch (image.imageOrientation) {
//        case UIImageOrientationLeft:
//        case UIImageOrientationLeftMirrored:
//        case UIImageOrientationRight:
//        case UIImageOrientationRightMirrored:
//            CGContextDrawImage(ctx, CGRectMake(0,0,image.size.height,image.size.width), image.CGImage);
//            break;
//        default:
//            CGContextDrawImage(ctx, CGRectMake(0,0,image.size.width,image.size.height), image.CGImage);
//            break;
//    }
//    CGImageRef cgimg = CGBitmapContextCreateImage(ctx);
//    UIImage *img = [UIImage imageWithCGImage:cgimg];
//    CGContextRelease(ctx);
//    CGImageRelease(cgimg);
//    return img;
//}
//
//+ (UIImage *)scaletoScale:(float)scaleSize image:(UIImage *)image
//{
//    UIGraphicsBeginImageContext(CGSizeMake(image.size.width * scaleSize, image.size.height * scaleSize));
//    [image drawInRect:CGRectMake(0, 0, image.size.width * scaleSize, image.size.height * scaleSize)];
//    UIImage *scaledImage = UIGraphicsGetImageFromCurrentImageContext();
//    UIGraphicsEndImageContext();
//    return scaledImage;
//}
//-------------------------------------------------------------------//
/*
CGContextRef CreateARGBBitmapContext (CGImageRef inImage)
{
    CGContextRef    context = NULL;
    CGColorSpaceRef colorSpace;
    void *          bitmapData;
    int             bitmapByteCount;
    int             bitmapBytesPerRow;
    
    // Get image width, height. We'll use the entire image.
    size_t pixelsWide = CGImageGetWidth(inImage);
    size_t pixelsHigh = CGImageGetHeight(inImage);
    
    // Declare the number of bytes per row. Each pixel in the bitmap in this
    // example is represented by 4 bytes; 8 bits each of red, green, blue, and
    // alpha.
    bitmapBytesPerRow   = (pixelsWide * 4);
    bitmapByteCount     = (bitmapBytesPerRow * pixelsHigh);
    
    // Use the generic RGB color space.
    colorSpace = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
    if (colorSpace == NULL)
    {
        fprintf(stderr, "Error allocating color space\n");
        return NULL;
    }
    
    // Allocate memory for image data. This is the destination in memory
    // where any drawing to the bitmap context will be rendered.
    bitmapData = malloc( bitmapByteCount );
    if (bitmapData == NULL) 
    {
        fprintf (stderr, "Memory not allocated!");
        CGColorSpaceRelease( colorSpace );
        return NULL;
    }
    
    context = CGBitmapContextCreate (bitmapData,
                                     pixelsWide,
                                     pixelsHigh,
                                     8,      // bits per component
                                     bitmapBytesPerRow,
                                     colorSpace,
                                     kCGImageAlphaPremultipliedFirst);
    if (context == NULL)
    {
        free (bitmapData);
        fprintf (stderr, "Context not created!");
    }
    
    // Make sure and release colorspace before returning
    CGColorSpaceRelease( colorSpace );
    
    return context;
}
 
 //    GNLog(@"\npixels when 32bit = %@ \n",pixels);
 //    *pixels = *pixels >> 8;
 //    GNLog(@"\npixels after shift  = %@ \n",pixels);
 //        buffer[i] = 0;
 //        buffer[i+1] = 0;
 //        buffer[i+2] = 255;
 //    for (uint32_t y = 0; y < height; y++) 
 //    {
 //        for (uint32_t x = 0; x < width; x++)
 //        {
 //            uint8_t* rgbaValues = (uint8_t*)&pixels[y * (uint32_t)width + x];
 //            
 //            //alpha = 0, red = 1, green = 2, blue = 3.
 //            
 //            rgbaValues[0] = rgbaValues[0];
 //            rgbaValues[1] = rgbaValues[0];
 //            rgbaValues[2] = rgbaValues[0];
 //            rgbaValues[3] = rgbaValues[0];
 //        }
 //    }

*/

/*
+ (CGContextRef) createARGBBitmapContextFromImage:(CGImageRef)inImage 
{
    CGContextRef    context = NULL;
    CGColorSpaceRef colorSpace;
    void *          bitmapData;
    int             bitmapByteCount;
    int             bitmapBytesPerRow;
    
    // Get image width, height. We'll use the entire image.
    size_t pixelsWide = CGImageGetWidth(inImage);
    size_t pixelsHigh = CGImageGetHeight(inImage);
    
    // Declare the number of bytes per row. Each pixel in the bitmap in this
    // example is represented by 4 bytes; 8 bits each of red, green, blue, and
    // alpha.
    bitmapBytesPerRow   = (pixelsWide * 4);
    bitmapByteCount     = (bitmapBytesPerRow * pixelsHigh);
    
    // Use the generic RGB color space.
    colorSpace = CGColorSpaceCreateDeviceRGB();
    
    if (colorSpace == NULL)
    {
        fprintf(stderr, "Error allocating color space\n");
        return NULL;
    }
    
    // Allocate memory for image data. This is the destination in memory
    // where any drawing to the bitmap context will be rendered.
    bitmapData = malloc( bitmapByteCount );
    if (bitmapData == NULL) 
    {
        fprintf (stderr, "Memory not allocated!");
        CGColorSpaceRelease( colorSpace );
        return NULL;
    }
    
    // Create the bitmap context. We want pre-multiplied ARGB, 8-bits 
    // per component. Regardless of what the source image format is 
    // (CMYK, Grayscale, and so on) it will be converted over to the format
    // specified here by CGBitmapContextCreate.
    context = CGBitmapContextCreate (bitmapData,
                                     pixelsWide,
                                     pixelsHigh,
                                     8,      // bits per component
                                     bitmapBytesPerRow,
                                     colorSpace,
                                     kCGImageAlphaPremultipliedFirst);
    if (context == NULL)
    {
        free (bitmapData);
        fprintf (stderr, "Context not created!");
    }
    F
    // Make sure and release colorspace before returning
    CGColorSpaceRelease( colorSpace );
    
    return context;
}
 */
//@end
