//
//  MHUdpResponseBase.h
//  MiHome
//
//  Created by Woody on 14/10/30.
//  Copyright (c) 2014年 小米移动软件. All rights reserved.
//

#import "MHResponseBase.h"

@class MHUdpRequestBase;
@class MIIOMsg;
@interface MHUdpResponseBase : MHResponseBase
@property (nonatomic, assign) NSInteger code;
// martes:[warning][woody]这么干行不行啊。。。
// wayne:目前没有引用，先注释掉
//@property (nonatomic, retain) MHUdpRequestBase* request;
@property (nonatomic, retain) MIIOMsg* miioMsg;
@property (nonatomic, retain) NSDictionary* safeMessage;//miioMsg中的message转化而来，采用MHSafeDictionary
@end
