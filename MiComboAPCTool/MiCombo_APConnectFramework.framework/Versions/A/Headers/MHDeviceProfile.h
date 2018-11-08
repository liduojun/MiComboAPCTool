//
//  MHDeviceProfile.h
//  MiNetworkFramework
//
//  Created by CoolKernel on 05/07/2017.
//  Copyright © 2017 zhangyinze. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MHDevPropertyValue : NSObject
@property (nonatomic, strong) id value;
@property (nonatomic, copy) NSString *des;
@property (nonatomic, copy) NSString *pid;
@property (nonatomic, assign) NSInteger status;
@property (nonatomic, copy) NSString *message;
@end


@interface MHDevProperty : NSObject
@property (nonatomic, assign) NSInteger iid;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *des;
@property (nonatomic, copy) NSString *format;
@property (nonatomic, strong) NSArray *access;
@property (nonatomic, strong) NSArray *valueRange;
@property (nonatomic, copy) NSString *unit;
@property (nonatomic, strong) NSArray <MHDevPropertyValue *> *valueList; 

@end

@interface MHDevPropertyResponseValue : NSObject
@property (nonatomic, strong) NSString* pid;
@property (nonatomic, assign) NSInteger status;
@end

@interface MHDevPropertyResponse : NSObject
@property (nonatomic, strong) NSString* oid;
@property (nonatomic, strong) NSArray<MHDevPropertyResponseValue*>* properties;
@end

@interface MHDevAction : NSObject
@property (nonatomic, assign) NSInteger iid;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *des;
@property (nonatomic, copy) NSArray *inParam;
@property (nonatomic, copy) NSArray *outParam;

@end

@interface MHDevServiceResponse : NSObject
@property (nonatomic, strong) NSString* oid;
@property (nonatomic, strong) NSArray* outParam;
@end

@interface MHDevService : NSObject
@property (nonatomic, assign) NSInteger iid;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *des;
@property (nonatomic, strong) NSArray <MHDevProperty *> *properties;
@property (nonatomic, strong) NSArray <MHDevAction *> *actions;
@end

//iid: 1,
//type: "urn:miot-spec:action:resume:00000407",
//description: "Resume",
//in: [ ],
//out: [ ]



@interface MHDeviceProfile : NSObject
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *des;
@property (nonatomic, strong) NSArray <MHDevService *> *services;

@end

@interface MHMiotDevice : NSObject
@property (nonatomic, copy) NSString *pdid;
@property (nonatomic, copy) NSString *did;
@property (nonatomic, assign) BOOL online;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *category;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *rid;


@end

@interface MHCSubscriptionPropertyValue : NSObject
@property (nonatomic, copy) NSString* message;
@property (nonatomic, copy) NSString* pid;
@property (nonatomic, assign) NSInteger status;
@end

@interface MHCSubscriptionPropertyResponse :NSObject
@property (nonatomic, assign)NSInteger expired;
@property (nonatomic, strong)NSArray<MHCSubscriptionPropertyValue*>* properties;
@end

@interface MHCSubcriptionPushAps : NSObject
@property (nonatomic, strong) NSString* alert;
@property (nonatomic, assign) NSInteger contentAvailable;
@end

@interface MHCSubcriptionPushProperty : NSObject
@property (nonatomic, strong) NSString* pid;
@property (nonatomic, strong) NSString* value;

- (NSString*)getDeviceDid;
@end

@interface MHCSubcriptionPushPayload : NSObject
@property (nonatomic, strong) NSString* identifier;
@property (nonatomic, strong) NSString* topic;
@property (nonatomic, strong) NSString* oid;
@property (nonatomic, strong) NSArray<MHCSubcriptionPushProperty*>* properties;
@property (nonatomic, assign) NSInteger contentAvailable;
@end
/**
 *  长连接返回的结果
 */
@interface MHCSubcriptionPushResponse : NSObject
@property (nonatomic, strong)NSString* pushId;
@property (nonatomic, strong)MHCSubcriptionPushAps* aps;
@property (nonatomic, strong)MHCSubcriptionPushPayload* payload;
@end

