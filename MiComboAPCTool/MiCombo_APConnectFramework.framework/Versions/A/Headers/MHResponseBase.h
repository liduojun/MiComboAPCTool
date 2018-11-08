//
//  MHResponseBase.h
//  MiHome
//
//  Created by Woody on 14/10/30.
//  Copyright (c) 2014年 小米移动软件. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MHRequestBase;
@interface MHResponseBase : NSObject
@property (nonatomic, retain) MHRequestBase* request;
@end
