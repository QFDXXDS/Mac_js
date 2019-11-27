//
//  UIAlertController+Category.m
//  CHitVideo
//
//  Created by Xianxiangdaishu on 2018/5/24.
//  Copyright © 2018年 changhongit. All rights reserved.
//

//#import "UIAlertController+Category.h"
//#import "UIWindow+Category.h"
//
//typedef void (^cancelBlock)(void);
//typedef void (^ensureBlock)(void);
//
//static cancelBlock Cancel = nil;
//static ensureBlock ensure = nil;
//
//@implementation UIAlertController (Category)
//
//
//+ (void)GNAlertMes:(NSString *)mes {
//
//
//}
//+ (void)GNALertTitle:(NSString *)title mes:(NSString *)mes cancel:(void (^)())cancel ensure:(void (^)(NSString *text))ensure {
//
//    UIAlertController *ac = [UIAlertController alertControllerWithTitle:title message:mes preferredStyle:UIAlertControllerStyleAlert];
//    [self GNAlert:ac cancel:cancel ensure:ensure];
//
//}
//
//+ (void)GNAlertTitle:(NSString *)title mes:(NSString *)mes textfild:(void (^)(UITextField * textField))textfild cancel:(void (^)())cancel ensure:(void (^)(NSString *text))ensure {
//
//    UIAlertController *ac = [UIAlertController alertControllerWithTitle:title message:mes preferredStyle:UIAlertControllerStyleAlert];
//    [ac addTextFieldWithConfigurationHandler:textfild];
//
//    [self GNAlert:ac cancel:cancel ensure:ensure];
//}
//+ (void)GNAlert:(UIAlertController *)ac cancel:(void (^)())cancel ensure:(void (^)(NSString *text))ensure{
//
//    [ac addAction:[self title:@"取消" event:cancel]];
//    [ac addAction:[self title:@"确定" event:^{
//
//        if (ac.textFields.count > 0) {
//
//            UITextField *field = ac.textFields[0];
//            ensure(field.text);
//        } else {
//
//            ensure(nil);
//        }
//    }]];
//    [[UIWindow rootVC] presentViewController:ac animated:YES completion:nil];
//}
//+ (UIAlertAction *)title:(NSString *)title event:(void (^)(void))event {
//
//    UIAlertAction *AA = [UIAlertAction actionWithTitle:title style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
//        event();
//    }];
//    return AA ;
//}

//@end
