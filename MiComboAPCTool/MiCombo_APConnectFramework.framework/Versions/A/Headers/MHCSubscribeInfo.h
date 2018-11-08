//
//  MHCSubscribeInfo.h
//  MiNetworkFramework
//
//  Created by huchundong on 2017/10/18.
//  Copyright © 2017年 zhangyinze. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifdef HY_MI_PUSH
#import "MHDeviceProfile.h"

typedef void(^MHCSubCompletionBlock) (BOOL suc, NSString *subID, NSString *errInfo);
typedef void(^MHCReceiveSubInfoBlock) (NSArray *deviceInfo, NSString *identifier);
typedef void(^MHCPushSocketStatusBlock) ();
typedef void(^MHCSubEndBlock) (float expire);

typedef void(^MHCSubscribeFailureBlock) ();
typedef void(^MHCSubFailCallBack) (NSError* err);
typedef void(^MHCSubSuccessCallBack)(MHCSubscriptionPropertyResponse* obj);
typedef void(^MHCSubPropertiesChangeCallBack)(NSMutableArray<MHCSubcriptionPushProperty*>* obj);

@interface MHCSubCallbackObj : NSObject
@property (nonatomic, copy) MHCSubEndBlock subExpireCallback;
@property (nonatomic, copy) MHCSubFailCallBack subFailureCallback;  //注册属性失败的callback
@property (nonatomic, copy) MHCSubSuccessCallBack subSuccessCallBack; //注册属性成功的callback
@property (nonatomic, copy) MHCSubPropertiesChangeCallBack  propertiesChangeCallBack; //当属性发生改变的时候的回调
@end


@interface MHCSubscribeObj : NSObject
@property (nonatomic, copy) NSString *subId; //订阅id，用户自定义，如果重复，就是覆盖之前的block。
@property (nonatomic, strong) NSMutableArray<NSString *> *props;   //订阅属性列表
@end
#endif
