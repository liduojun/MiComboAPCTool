//
//  MHXiaoMiBleServiceInfo.h
//  MiHome
//
//  Created by marteswang on 15/11/25.
//  Copyright © 2015年 小米移动软件. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kMiServiceUUID  @"fe95"

@interface MHXiaoMiBleServiceInfo : NSObject

@property (nonatomic, strong) NSData *data;

@property (nonatomic, strong) NSData *frameControl;         // 控制位
@property (nonatomic, assign) NSInteger productId;          // 产品ID，每类产品唯一
@property (nonatomic, assign) NSInteger frameCounter;       // 序列号
@property (nonatomic, copy) NSString *macAddress;           // mac地址（可选）
@property (nonatomic, assign) NSInteger capability;         // 设备能力（可选）
@property (nonatomic, strong) NSData *event;                // 触发的事件（可选）
@property (nonatomic, strong) NSData *manufactureData;      // 厂商自定义事件（可选）
@property (nonatomic, strong) NSData *manufactureTitleData; // 厂商自定义副标题数据（可选）

// frame control 解析
@property (nonatomic, assign) BOOL factoryNew;              // 设备绑定状态
@property (nonatomic, assign) BOOL Connecting;              // 设备是否正在连接
@property (nonatomic, assign) BOOL isCentral;               // central状态
@property (nonatomic, assign) BOOL isEncrypted;             // 该包加密状态
@property (nonatomic, assign) BOOL macInclude;              // 是否包含mac地址
@property (nonatomic, assign) BOOL capabilityInclude;       // 是否包含capability
@property (nonatomic, assign) BOOL eventInclude;            // 是否包含event
@property (nonatomic, assign) BOOL manuDataInclude;         // 是否包含manufactureData
@property (nonatomic, assign) BOOL manuTitleInclude;        // 是否包含manufactureTitleData
@property (nonatomic, assign) BOOL bindingCfm;              // 是否是绑定确认包
@property (nonatomic, assign) NSUInteger frameControlReserved; // 保留字
@property (nonatomic, assign) NSUInteger version;           // 版本号

// capability 解析
@property (nonatomic, assign) BOOL connectable;             // 是否有建立连接的能力
@property (nonatomic, assign) BOOL beCentral;               // 设备有否做central网关的能力
@property (nonatomic, assign) BOOL encryptAbility;          // 设备是否有加密的能力
@property (nonatomic, assign) NSUInteger bondAbility;        // 绑定: 0-不使用，1-MIOT前，2-MIOT后，3-保留
@property (nonatomic, assign) NSUInteger capabilityReserved;   // 保留字

- (void)parseData:(NSData *)serviceData;
@end
