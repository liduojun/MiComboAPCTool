//
//  MHComboConnectManager.h
//  MiBluetoothFramework
//
//  Created by yinze zhang on 2016/11/22.
//  Copyright © 2016年 yinze zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,kComboConnectErrorType){
    comboConnectDeviceError         = 1,
    comboConnectRegisterError       = 2,
    comboConnectError               = 3,
    comboConnectPasswordError       = 4,
    comboConnectBledisconnectError  = 5,
    comboConnectBleWifiError        = 6,
};

typedef NS_ENUM(NSInteger,kComboConnectCountry) {
    comboConnectCountryChina,
    commboConnectCountrySingapore,
    commboConnectCountryUSA,
    commboConnectCountryEurope,
    commboConnectCountryRussia,
};

@interface MHComboConnectManager : NSObject

@property(nonatomic, copy) NSString* uid;
@property(nonatomic, copy) NSString* ssid;
@property(nonatomic, copy) NSString* password;
@property(nonatomic, assign) kComboConnectCountry country;

-(void)comboConnect:(MHBluetoothDevice*)bluetoothDevice success:(void(^)())successBlock failure:(void(^)(NSError* error))failureBlock;

@end
