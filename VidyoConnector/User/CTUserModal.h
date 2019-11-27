//
//  UserModal.h
//  VidyoSample
//
//  Created by Xianxiangdaishu on 2017/9/28.
//  Copyright © 2017年 com.changhongit. VidyoSample. All rights reserved.
//

#import <JSONModel/JSONModel.h>
//#import "OrgModel.h"
//#import "CTTenantModel.h"

@protocol CTUserModal <NSObject>


@end

@interface CTUserModal : JSONModel

//@property (nonatomic,copy)NSString<Optional> *avatar;
//@property (nonatomic,copy)NSString<Optional> *loginName;
//@property (nonatomic,copy)NSString<Optional> *mail;
//@property (nonatomic,copy)NSString<Optional> *mobile;
@property (nonatomic,copy)NSString<Optional> *name;
//@property (nonatomic,copy)NSString<Optional> *officeTel;
//@property (nonatomic,copy)NSString<Optional> *order;
//
//@property (nonatomic,copy)NSString<Optional> *positionName;
//@property (nonatomic,copy)NSString<Optional> *role;
//@property (nonatomic,copy)NSString<Optional> *status;
@property (nonatomic,copy)NSString<Optional> *token;
//@property (nonatomic,copy)NSString<Optional> *userid;
//
//@property (nonatomic,copy)CTTenantModel <Optional>*tenant;
//
//@property (nonatomic, copy)NSArray<Optional,OrgModel> * organization;


@property (nonatomic,copy)NSString<Optional> *userId;
@property (nonatomic,copy)NSString<Optional> *email;

@property (nonatomic,copy)NSString<Optional> *password;
@property (nonatomic,copy)NSString<Optional> *departmentId;
@property (nonatomic,copy)NSString<Optional> *firstName;
@property (nonatomic,copy)NSString<Optional> *lastName;

@property (nonatomic,copy)NSString<Optional> *officePhone;

@property (nonatomic,copy)NSString<Optional> *mobile;
@property (nonatomic,copy)NSArray<Optional> *virtualRooms;
//
//"userId": "1007",
//"email": "yzhao@chit.com",
//"password": null,
//"departmentId": null,
//
//"firstName": "延军",
//"lastName": "赵",
//"officePhone": "",
//"mobile": "",
//"virtualRooms": null


@end

