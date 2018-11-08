//
//  MHDeviceBindWithBindkeyResponse.h
//  MiNetworkFramework
//
//  Created by huchundong on 2018/3/7.
//  Copyright © 2018年 zhangyinze. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MHDeviceBindWithBindkeyResponse : NSObject
@property(nonatomic, strong)NSString*   did;
@property(nonatomic, assign)NSInteger   code;
@property(nonatomic, assign)NSInteger   ret;
@end
