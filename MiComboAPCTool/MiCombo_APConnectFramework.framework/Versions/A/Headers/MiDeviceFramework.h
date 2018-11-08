//
//  MiDeviceFramework.h
//  MiDeviceFramework
//
//  Created by zhangyinze on 16/8/26.
//  Copyright © 2016年 zhangyinze. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
//! Project version number for MiDeviceFramework.
FOUNDATION_EXPORT double MiDeviceFrameworkVersionNumber;

//! Project version string for MiDeviceFramework.
FOUNDATION_EXPORT const unsigned char MiDeviceFrameworkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <MiDeviceFramework/PublicHeader.h>

//操作小米设备的接口,包括快连,远程接口调用
#import <MiDeviceFramework/MHDevice.h>
#import <MiDeviceFramework/MHDevices.h>
#import <MiDeviceFramework/MHDataDeviceTimer.h>
#import <MiDeviceFramework/MHCrontabTime.h>
#import <MiDeviceFramework/MHDeviceManager.h>
#import <MiDeviceFramework/MHDeviceSmartConfig.h>

//帐号系统相关.
#import <MiDeviceFramework/MHNetworkEngine.h>
#import <MiDeviceFramework/MHBaseRequest.h>
#import <MiDeviceFramework/MHError.h>
#import <MiDeviceFramework/MHAccountConfig.h>
#import <MiDeviceFramework/MHAccount.h>
#import <MiDeviceFramework/MHAccountProfile.h>
#import <MiDeviceFramework/MHRequestSerializer.h>
#import <MiDeviceFramework/MHPassport.h>
#import <MiDeviceFramework/MHConstants.h>
