//
//  MiioRpc.h
//  Miio
//
//  Created by guolin on 15/3/4.
//  Copyright (c) 2015年 xiaomi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MiioConstants.h"

@interface MiioRpc : NSObject

/**
 *  绑定权限模式，上层直接发送命令
 *
 *  @param ip       设备IP
 *  @param body     额外数据
 *  @param deviceID 设备ID
 *  @param token    token
 *  @param stamp    时间戳
 */
- (void)startRPCWithIP:(NSString*)ip deviceId:(long)deviceId body:(NSString *)body token:(NSString*)token stamp:(int)stamp finish:(MiioFinishBlock)finishBlock;

/**
 *  绑定权限模式，与miio协商stamp
 *
 *  @param ip       设备IP
 *  @param body     额外数据
 *  @param deviceID 设备ID
 *  @param token    token
 */
- (void)startRPCWithIP:(NSString*)ip deviceId:(long)deviceId body:(NSString *)body token:(NSString*)token finish:(MiioFinishBlock)finishBlock;
/**
 *  访客模式，与miio协商stamp&token
 *
 *  @param ip       设备IP
 *  @param body     额外数据
 */
- (void)startRPCWithIP:(NSString*)ip deviceId:(long)deviceId body:(NSString *)body finish:(MiioFinishBlock)finishBlock;

/**
 *  与设备协商得到token
 *
 *  @param ip 设备IP
 */
- (void)startGetTokenWithIP:(NSString* )ip finish:(MiioFinishBlock)finishBlock;

@end
