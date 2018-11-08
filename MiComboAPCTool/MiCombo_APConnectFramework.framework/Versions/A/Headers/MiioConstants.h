//
//  MiioConstants.h
//  Miio
//
//  Created by guolin on 15/3/10.
//  Copyright (c) 2015年 xiaomi. All rights reserved.
//

#import "MHUdpResponseBase.h"

typedef enum : NSInteger {
    ConnectErrorSuccess = 0,
    ConnectErrorMsgTooLong = -1,
    ConnectErrorUAPConfigRouterFail = -2,
    ConnectErrorUAPDeviceStateError = -3,
    ConnectErrorCanceledByUser = -4,
}ConnectErrorCode;

/**
 *  快连结束回调
 *
 *  @param errCode 快连错误码
 */
typedef void(^MiioCompleteBlock)(ConnectErrorCode errCode);
typedef void(^MiioUapCompleteBlock)(ConnectErrorCode errCode, NSString* did, NSString* token);

typedef enum : NSInteger {
    UdpErrorOk = 0,
    UdpErrorPermissionDenied = -1,
    UdpErrorDeviceOffline = -2,
    UdpErrorTimeout = -3,
    UdpErrorInvalidRequest = -6,
    UdpErrorUnknown = -9,
    UdpErrorNoMethod = -10,
    UdpErrorRepeatedRequest = -11,
    UdpErrorFrequentRequest = -12,
}UdpErrorCode;

/**
 *  rpc完成回调
 *
 *  @param response rpc返回的数据
 *  @param errCode  udp错误码
 */
typedef void(^MiioFinishBlock)(MHUdpResponseBase* response, UdpErrorCode errCode);


