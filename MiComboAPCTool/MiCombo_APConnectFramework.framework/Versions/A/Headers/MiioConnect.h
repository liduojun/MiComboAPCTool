//
//  MiioConnect.h
//  Miio
//
//  Created by guolin on 15/3/4.
//  Copyright (c) 2015年 xiaomi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MiioConstants.h"

@interface MiioConnect : NSObject

@property (nonatomic, copy, readonly) NSString *token;


/**
 *  开始、停止快连
 *
 *  @param ssid wifi名称
 *  @param pwd  wifi密码
 *  @param userId  用户ID
 *  @param completeBlock  快连结束回调
 */
- (void)startConnectWithSSID:(NSString *)ssid password:(NSString *)pwd userId:(long)userId countryDomain:(NSString*)cd  completeBlock:(MiioCompleteBlock)completeBlock;
- (void)stopConnect;

/**
 *  开始、停止UAP快连
 *
 *  @param deviceIp: 要连接的设备的IP
 *  @param countryDomain：用户所在的国家区域码，目前只有en,sg,tw
 *  @param 其它: 同上
 */
- (void)startUAPConnectWithDeviceIp:(NSString* )deviceIp SSID:(NSString *)ssid password:(NSString *)pwd userId:(NSString* )userId countryDomain:(NSString*)cd channel:(NSString*)channel  completeBlock:(MiioUapCompleteBlock)completeBlock;
- (void)stopUAPConnect;
// 检查UAP快连状态
- (void)checkUAPDeviceState:(MiioCompleteBlock)completeBlock;
@end
