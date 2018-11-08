//
//  MHBluetoothHelper.h
//  MiBluetoothFramework
//
//  Created by yinze zhang on 2016/11/2.
//  Copyright © 2016年 yinze zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
@interface MHBluetoothHelper : NSObject

+(NSString*)hexStringFromData:(NSData*)data;

+(BOOL)compareCBUUID:(CBUUID*)theUUID other:(NSString*)otherUUID;

@end
