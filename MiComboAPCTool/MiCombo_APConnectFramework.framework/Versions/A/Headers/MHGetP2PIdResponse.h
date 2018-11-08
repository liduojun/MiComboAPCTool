//
//  NSGetP2PResponse.h
//  MiSmartHomeDemoDebug
//
//  Created by huchundong on 2018/4/19.
//  Copyright © 2018年 yinze zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MHGetP2PIdResponse : NSObject
@property(nonatomic, strong)NSString*   p2pId;
@property(nonatomic, strong)NSString*   password;
//米家摄像机加密的key
@property(nonatomic, strong)NSString*   remoteKey;
@property(nonatomic, strong)NSString*   remoteSing;
@end
