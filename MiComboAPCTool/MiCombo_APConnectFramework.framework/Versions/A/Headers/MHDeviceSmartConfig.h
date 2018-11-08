//
//  MHDeviceSmartConfig.h
//  MiDeviceFramework
//
//  Created by zhangyinze on 16/8/26.
//  Copyright © 2016年 zhangyinze. All rights reserved.
//

#import <Foundation/Foundation.h>

//此类封装了一个完整意义的强关联的快连模式
//包括以下三个步骤,如果用户可以任意选择以下几个步骤.
//快连分为3个步骤
//1.client <-----> hardware   客户端跟 wifi 模块交流,把 ssid与 password 发给 hardware
//2.client <-----> cloud      客户端 与 服务器拉取新快连接入的设备
//3.client <-----> cloud      客户端 与 服务器拉取这个账户 id 下所有的设备

typedef NS_ENUM(NSInteger,kSmartConfigState){
    eSmartConfigHardware,
    eSmartConfigGetNewDevice,
    eSmartConfigBindDevice,
    eSmartConfigGetFullDevice,
};

typedef NS_ENUM(NSInteger,kSartConfigResult){
    eSmartConfigSucess,
    eSmartConfigFailure
};

@interface MHDeviceSmartConfig : NSObject


/**
 *  开始快连
 *
 *  @param deviceIp      AP 模块的 IP
 *  @param ssid          路由器的 ssid
 *  @param bssid         路由器的 mac 地址
 *  @param password      路由器的 密码
 *  @param userId        用户的小米 id
 *  @param domain        用户所在的国家区域 :eg 中国 cn 新加坡 sg 美国 us 其他others
 *  @param progressBlock 每步快连的状态,用户可以控制进行到哪一步.
 *                       state 表示当前的是哪一步,result 表示这一步的状态, stop 可以由用户控制是否停止以后的步骤
 */
-(void)startAPSmartConfigDeviceIp:(NSString*)deviceIp
                         WithSSID:(NSString*)ssid
                        WithBSSID:(NSString*)bssid
                         password:(NSString*)password
                           userId:(NSString*)userId
                           domain:(NSString*)domain
                    progressBlock:(void(^)(kSmartConfigState state,kSartConfigResult result,BOOL* stop))progressBlock;


-(void)stopAPSmartConfig;

@end
