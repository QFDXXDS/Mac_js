//
//  CHITBasicService.h
//  CHitVideo
//
//  Created by user on 2018/9/4.
//  Copyright © 2018年 changhongit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CHITBasicService : NSObject
/**
 service请求的ip地址或者域名地址
 
 @param address 请求地址
 */
+ (void)serviceAddress:(NSString *)address;
//MARK: 联系人相关服务
/**
 模糊查询联系人呢
 
 @param searchStr 输入字符
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)searchConatctWithStr:(NSString *)searchStr
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail;
/**
 修改联系人信息
 
 @param avatar 头像
 @param mail 邮箱
 @param mobile 电话
 @param name 姓名
 @param officeTel 办公电话
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)reviseConatctWithAvatar:(NSString *)avatar
                           mail:(NSString *)mail
                         mobile:(NSString *)mobile
                           name:(NSString *)name
                      officeTel:(NSString *)officeTel
                         userid:(NSString *)userid
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail ;
/**
 用户id查询
 
 @param userid 用户Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)searchConatctWithUserid:(NSString *)userid
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail ;


/**
 查询机构
 
 @param org   机构Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)searchOrgWithOrg:(NSString *)org
//                tenantid:(NSString *)tenantid
                 success:(GNSuccessBlock)success
                    fail:(GNFailBlock)fail ;

/**
 新增个人联系人
 
 @param usersid 用户Id数组
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)addContactArray:(NSArray *)usersid
                success:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail ;
/**
 删除个人联系人
 
 @param usersid 用户Id数组
 @param success 成功回调
 @param fail 失败回调
 */

+ (void)delContactArray:(NSArray *)usersid
                success:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail ;

/**
 查询个人联系人
 
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)searchContactSuccess:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail ;



//MARK: 会议相关服务
/**
 获取正在进行的会议列表
 
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)confListWithUserId:(NSString *)userId
                   success:(GNSuccessBlock)success
                      fail:(GNFailBlock)fail ;



/**
 获取历史会议列表
 
 @param page 当前页
 @param size 长度
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)conferenceHistoryListPage:(NSInteger)page
                         pageSize:(NSInteger)size
                           userId:(NSString *)userId

                          success:(GNSuccessBlock)success
                             fail:(GNFailBlock)fail;

/**
 获取模版列表
 
 @param page 当前页
 @param size 长度
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)templateListWithPage:(NSInteger)page
                    pageSize:(NSInteger)size
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail;


/**
 删除会议模板
 
 @param Id 模板Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)delTemplateWithId:(NSString *)Id
                  success:(GNSuccessBlock)success
                     fail:(GNFailBlock)fail;
/**
 查看会议详情
 
 @param conferenceid 会议Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)conferenceDetailWithId:(NSString *)conferenceid
                       success:(GNSuccessBlock)success
                          fail:(GNFailBlock)fail;

/**
 查看历史会议详情
 
 @param conferenceid 会议Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)conferenceHistoryWithId:(NSString *)conferenceid
                        success:(GNSuccessBlock)success
                           fail:(GNFailBlock)fail ;

/**
 创建／更新模板
 
 @param templateId 模板Id  （不传id则为创建模板，否则即为更新模板）
 @param title 模板标题
 @param userIdArr 模板标题
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)createTemplateWithId:(NSString *)templateId
                       title:(NSString *)title
                   userIdArr:(NSArray *)userIdArr
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail;


/**
 删除会议模板
 
 @param templateId 模板Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)removeTemplateWithId:(NSString *)templateId
                     success:(GNSuccessBlock)success
                        fail:(GNFailBlock)fail;



/**
 创建会议
 
 @param title 会议标题
 @param userIdArr 参会人员id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)createConferenceWithTitle:(NSString *)title
                        userIdArr:(NSArray *)userIdArr
                          success:(GNSuccessBlock)success
                             fail:(GNFailBlock)fail;

/**
 修改密码
 MARK: 用户相关
 @param oldPWD 旧密码
 @param newPWD 新密码
 @param userid 用户Id
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)revisePWDWithOldPWD:(NSString *)oldPWD
                     newPWD:(NSString *)newPWD
                     userid:(NSString *)userid
                    success:(GNSuccessBlock)success
                       fail:(GNFailBlock)fail ;

/**
 用户登出
 
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)loginOutSuccess:(GNSuccessBlock)success
                   fail:(GNFailBlock)fail ;

//MARK: 登录相关
/**
 发起登录
 
 @param loginName 账户名
 @param password 密码
 @param tenant 租户名
 @param success 成功回调
 @param fail 失败回调
 */
+ (void)loginWithLoginName:(NSString *)loginName
                  password:(NSString *)password
                    tenant:(NSString *)tenant
                   success:(GNSuccessBlock)success
                      fail:(GNFailBlock)fail ;


+ (void)domain:(NSString *)domain ;

+ (void)AdmissionRequestSuccess:(GNSuccessBlock)success fail:(GNFailBlock)fail ;

+ (void)getUserListPageNum:(NSInteger)pageNum pageSize:(NSInteger)pageSize success:(GNSuccessBlock)success fail:(GNFailBlock)fail ;

@end
