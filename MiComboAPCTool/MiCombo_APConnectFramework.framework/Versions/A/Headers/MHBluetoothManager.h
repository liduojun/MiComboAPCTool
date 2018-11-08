//
//  MHBluetoothManager.h
//  MiBluetoothFramework
//
//  Created by yinze zhang on 2016/9/22.
//  Copyright © 2016年 yinze zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "MHBluetoothDevice.h"
typedef NS_ENUM(NSUInteger,BluetoothErrorType){
    BluetoothUnkonwn,
    BluetoothServiceUUIDInvalid,
    BluetoothCharacteristicUUIDInvalid,
};


typedef void(^connectResult)(BOOL b,NSError*);
typedef void(^characteristicOprationResult)(CBCharacteristic* characteristic ,NSError* error);

NS_ASSUME_NONNULL_BEGIN
@interface MHBluetoothManager : NSObject

@property(nonatomic, strong, readonly)MHBluetoothDevice* bluetoothDevice;



-(instancetype)initWithBluetoothDevice:(MHBluetoothDevice*)bluetoothDevice;



/**
 蓝牙是否连接
 
 @return YES,已经连接; NO,没有连接.
 */
-(BOOL)isConnected;

-(void)disConnect;

-(void)removeCallbacks;

- (void)unRegisterBlueTooth;
/**
 物理连接蓝牙设备,bluetooth层面上的连接

 @options 连接需要参数 参见 Peripheral Connection Options
 @param result 连接的结果
 */
-(void)connectWithOptions:(nullable NSDictionary<NSString *,id> *)options result:(connectResult)result;



/**
 搜索所有的服务
 @param serviceUUIDs  serviceUUIDs
 @param result discover的结果
 */
-(void)discoverServicesWithServices:(nullable NSArray<NSString*>*)serviceUUIDs result:(void(^)(NSArray<CBService*>* services,NSError* _Nullable error))result;



/**
 在某个service中搜索

 @param serviceUUID serviceUUID
 */
-(void)discoverCharacteristicInServiceUUID:(NSString*)serviceUUID result:(void(^)(CBService* _Nullable service,NSError* _Nullable error))result;


/**
 向设备写入数据

 @param data               数据
 @param characteristicUUID 设备的characteristic id
 @param serviceUUID        service id
 @param type               see also 	CBCharacteristicWriteWithResponse ,
                                        CBCharacteristicWriteWithoutResponse,
 @param result             写操作的结果
 */
-(void)writeData:(NSData*)data
toCharacteristicUUID:(NSString*)characteristicUUID
   inServiceUUID:(NSString*)serviceUUID
            type:(CBCharacteristicWriteType)type
     resultBlock:(characteristicOprationResult)result;



/**
 从设备读取数据

 @param characteristicUUID characteristicUUID
 @param serviceUUID serviceUUID
 @param result result
 */
-(void)readValueOfCharacteristicUUID:(NSString*)characteristicUUID
                       inServiceUUID:(NSString*)serviceUUID
                         resultBlock:(characteristicOprationResult)result;



/**
 设置是否打开notify 通知

 @param needNotify         YES,打开. NO,关闭
 @param characteristicUUID uuid
 @param serviceUUID        serviceid
 @param notifyState        打开后的notify后的回调
 @param notifyData         打开notify通知后,有数据传来时的回调
 */
-(void)setNotify:(BOOL)needNotify
characteristicUUID:(NSString*)characteristicUUID
   inServiceUUID:(NSString*)serviceUUID
     notifyStateBlock:(characteristicOprationResult)notifyState
 notifyDataBlock:(_Nullable characteristicOprationResult)notifyData;


+ (void)registerCentralManagerDelegate:(id<CBCentralManagerDelegate>)delegate;

+ (void)unRegisterCentralManagerDelegate:(id)delegate;

@end


NS_ASSUME_NONNULL_END
