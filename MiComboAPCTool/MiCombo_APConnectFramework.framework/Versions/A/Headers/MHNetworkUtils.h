//
//  MHNetworkUtils.h
//  QuickCnntDemo
//
//  Created by Woody on 14-9-24.
//  Copyright (c) 2014年 Woody. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/CaptiveNetwork.h>

@interface MHNetworkUtils : NSObject

+ (MHNetworkUtils* )shareInstance;

+ (NSDictionary*)fetchSSIDInfo;
+ (NSString*)fetchSSID;
+ (NSString*)fetchBSSID;

+ (NSString*)whatismyipdotcom;
+ (NSString*)localWiFiIPAddress;
+ (NSString*)localWiFiBroadcastIPAddress;

/**
 *  @brief 获取ap模式下的设备ip
 */
+ (NSString *)getDeviceIP;

- (void)openSystemSettingPage;

#ifdef APP_DEVELOPMENT
+ (BOOL)LocalDevFlag; //本地DEV标志位
+ (void)setLocalDevFlag:(BOOL)flag; //设置本地DEV标志位
#endif

+ (NSString *)macStringFromData:(NSData *)data;
+ (NSData *)macDataFromString:(NSString *)macString;
+ (NSString *)systemLanguage;

@end
