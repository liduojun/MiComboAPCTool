//
//  MHPushManager.h
//  MiHome
//
//  Created by wayne on 14/11/13.
//  Copyright (c) 2014年 小米移动软件. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "MHPushHandlerBase.h"
#ifdef HY_MI_PUSH
#import "MHDeviceProfile.h"
#import "MHCSubscribeInfo.h"

FOUNDATION_EXTERN NSString* const kMHCRequestDomain;


@interface MHCPushManager : NSObject

@property(nonatomic, strong)NSString* authorization;
+ (instancetype)sharedInstance;

/**
 *  @brief 注册PushHandler
 *
 *  @param pushHandler 用来处理具体类型的push消息
 */
//- (void)registerPushHandler:(MHPushHandlerBase *)pushHandler;

/**
 *  @brief 注册MiPush
 *
 *  @discussion 在application:didFinishLaunchingWithOptions:中调用
 */
- (void)registerMiPush;


/**
 客户端注销push
 */
- (void)unregister;

/**
 *  @breif 绑定DeviceToken
 *
 *  @param deviceToken 苹果服务器下发的设备令牌
 *
 *  @discussion 在application:didRegisterForRemoteNotificationsWithDeviceToken:中调用
 */
- (void)bindDeviceToken:(NSData *)deviceToken;

/**
 *  @brief 将设备与账号绑定
 *
 *  @discussion 在账号登陆成功后或切换账号成功后与设备绑定
 */
- (void)bindDevice;

/**
 *  @brief 将设备与账号解绑
 *
 *  @param success 解绑成功
 *  @param failure 解绑失败
 *
 *  @discussion 账户注销或删除或切换账号前需要将设备解绑，将不在该设备上收到该账户的push
 */
- (void)unbindDeviceSuccess:(void(^)())success
                    failure:(void(^)())failure;

/**
 *  @brief 收到push时调用此函数传递给PushManager处理
 *
 *  @param userInfo application:didReceiveRemoteNotification:的参数userInfo
 *                  application:didFinishLaunchingWithOptions:的参数launchOption中
 *                  UIApplicationLaunchOptionsRemoteNotificationKey对应的对象
 *  @param inForeground 收到push消息时app是否在前台
 *
 *  @discussion 在函数application:didReceiveRemoteNotification:和
 *              函数application:didFinishLaunchingWithOptions:中调用
 */
- (void)didReceivePush:(NSDictionary *)userInfo inForeground:(BOOL)inForeground;

//处理push消息，消息的接口是字典类型
- (void)handlePushMessageDict:(NSDictionary *)paramsDict type:(NSString *)type;

/**
 *  @brief 处理缓存的push
 *
 *  @discussion 根据收到push的时机，可能存在push未被处理的情况，可在适当时机调用该函数处理缓存push
 */
- (void)checkAndhandleCachedPush;

/**
 *  @brief 清除app通知badge
 *
 *  @discussion 当app从桌面启动时或者切换到前台时，调用该方法清除app通知badge
 */
- (void)clearAppBadgeNumber;

/**
 *  @brief 清除App通知Badge和事件列表
 *
 *  @discussion 当push消息被处理时，或者push内容被用户消耗后，调用该方法清除app未读通知数和事件列表
 */
- (void)clearAppBadgeNumberAndNotifications;

/**
 *  push 长链相同消息去重
 *
 *  @param userInfo push 消息
 */
- (void)distinctToPushInfo:(NSDictionary *)userInfo;

// 获取MiPush系统的注册id
- (NSString *)regId;

- (void)testPushMessage:(NSString *)pushMsg;

/**
 *  @brief 标记App进入活动态的时间
 *
 *  @discussion 当App被kill后重新启动或者从后台进入前台的时候把进入前台的时间纪录下来
 *
 *  @param date App进入前台的时间
 */
- (void)markApplicationWakeupTime:(NSDate *)date;

- (void)getDeliveredNotifications:(void (^)(NSInteger))notificationCount;

/**
 * 订阅对于的属性，MHCSubscribeObj.subId 需要保留，是作为取消这个属性回调的接口。
 * @param  obj包含两个属性，一个是subId，是用于作为这个属性订阅用的，不能为空
         obj的props 表示要订阅的属性。
 * @param callBackObj 包含注册属性成功，失败的回调，也包括属性失败的回调
 */
- (void)subscribe:(MHCSubscribeObj*) obj  withCallBack:(MHCSubCallbackObj*) callBackObj;

/**
 * @param properties里面包含所有属性。用于取消对应的属性订阅，这个包括所有的MHCSubCallbackObj中的属性。
 *        比如
            MHCSubscribeObj* objA = [MHCSubscribeObj new];
            objA.subId = @"A";
            objA.props = @[APid,BPid].mutableCopy;
 
            [self subscribe:objA withCallBack:[callBackObj new]];
 
            MHCSubscribeObj* objB = [MHCSubscribeObj new];
            objB.subId = @"B";
            objB.props = @[APid,CPid].mutableCopy;
 
            [self subscribe:objB withCallBack:[callBackObj new]];
 
            如果使用 [self unsubscribeProperties:@[APid] success: fail];
            会取消所有objA，objB中的回调。
            如果是使用[self unsubscribe:@"B" success:fail 的方式，只是吧objB的属性订阅取消
 */
- (void)unsubscribeProperties:(NSArray<NSString*>*) properties success:( void(^)(MHCSubscriptionPropertyResponse* obj)) successBlock fail:(void (^)(NSError* err) ) errBlock;

- (void)unsubscribe:(NSString*)subId success:(void (^)(MHCSubscriptionPropertyResponse *))successBlock fail:(void (^)(NSError *))errBlock;
@end
#endif
