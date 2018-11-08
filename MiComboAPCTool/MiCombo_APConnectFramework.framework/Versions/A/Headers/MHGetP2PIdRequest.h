//
//  MHGetP2PIdRequest.h
//  MiSmartHomeDemoDebug
//
//  Created by huchundong on 2018/4/19.
//  Copyright © 2018年 yinze zhang. All rights reserved.
//

#import "MHBaseRequest.h"

@interface MHGetP2PIdRequest : MHBaseRequest
@property(nonatomic, copy) NSString* did;
@property(nonatomic, copy) NSString* pincode;
//米家摄像机加密的key
@property(nonatomic, copy) NSString* toSignAppData;
@end
