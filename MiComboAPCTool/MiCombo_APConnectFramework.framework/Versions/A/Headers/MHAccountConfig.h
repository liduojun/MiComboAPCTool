//
//  MHAccountConfig.h
//  MiHomeSDK
//
//  Created by wangdongsheng on 16/7/6.
//  Copyright © 2016年 xiaomi. All rights reserved.
//

#import <Foundation/Foundation.h>

//用于配置MHAccount，非login方法登陆后需要手动配置

@interface MHAccountConfig : NSObject

@property (nonatomic, copy) NSString *accessToken;

@property (nonatomic, copy) NSString *encryptKey;
@property (nonatomic, copy) NSString *encryptAlgorithm;

@property (nonatomic,strong) NSDate *expirationDate;

//未实现，子类自己去解析吧，给上述属性赋值
-(instancetype)initWithDictionary:(NSDictionary *)configDic;

@end
