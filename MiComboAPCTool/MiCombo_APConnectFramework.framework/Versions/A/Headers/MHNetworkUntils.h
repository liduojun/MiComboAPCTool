//
//  MHNetworkUntils.h
//  MiSmartHomeDemo
//
//  Created by zhangyinze on 16/8/30.
//  Copyright © 2016年 zhangyinze. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MHNetworkUntils : NSObject

+(NSString*)getDeviceIp:(BOOL)preferIPv4;

+ (NSString*)fetchBSSID;
@end
