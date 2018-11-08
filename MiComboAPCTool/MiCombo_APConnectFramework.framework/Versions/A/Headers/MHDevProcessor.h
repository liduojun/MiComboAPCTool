//
//  MHDevProcessor.h
//  MiNetworkFramework
//
//  Created by CoolKernel on 05/07/2017.
//  Copyright © 2017 zhangyinze. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MHDeviceProfile.h"
typedef enum MHDevProcessorErrorType{
    kMHCSubscriptionPropertiesNotProperty = -1000, //没有订阅的属性
    kMHCSubscriptionRegIdIsNull = -1001,    //push没有成功
    kMHCSubscriptionauthorizationIsNull = -1002,   //没有传app scret key。
    kMHCSubscriptionSubIdIsNull = -1003,   //属性订阅的subId 为空
    kMHCSubscriptionPropetiesIsNull = -1004, //订阅的属性为空
}MHDevProcessorErrorType;
@class MHGetDevProfileRequest;
@interface MHDevProcessor : NSObject

+ (instancetype)shared;

- (void)pullDeviceProfileWithType:(NSString *)type
                       completion:(void (^)(MHDeviceProfile *, NSError *))completion;


- (void)getDeviceList:(void (^)(NSArray <MHMiotDevice *> *, NSError *))completion;


- (void)getDeviceProperties:(NSArray <NSString *> *)pids
                 completion:(void (^)(NSArray <MHDevPropertyValue *> *, NSError *error))completion;

- (void)setDeviceProperties:(NSArray <MHDevPropertyValue *> *)properties
                 completion:(void (^)(MHDevPropertyResponse* response, NSError *error))completion;

- (void)setDeviceAction:(NSString*)aid inParam:(NSArray*)inParam completion:(void (^)(MHDevServiceResponse* response, NSError *error))completion;

- (void)unbindDevice:(NSString*)did success:( void(^)(id obj)) successBlock fail:(void (^)(NSError* err) ) errBlock;


- (void)subscribeProbeperties:(NSArray*) properties withAuthorization:(NSString*)authorization identifier:(NSString*)identifier success:( void(^)(MHCSubscriptionPropertyResponse*  obj)) successBlock fail:(void (^)(NSError* err) ) errBlock;

- (void)unsubscribeProbeperties:(NSArray*) properties  success:( void(^)(MHCSubscriptionPropertyResponse*  obj)) successBlock fail:(void (^)(NSError* err) ) errBlock;
 

- (void)subscriptionEvent:(NSArray*) properties withAuthorization:(NSString*)authorization identifier:(NSString*)identifier success:( void(^)(id obj)) successBlock fail:(void (^)(NSError* err) ) errBlock;
@end
