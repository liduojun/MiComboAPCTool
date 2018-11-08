//
//  MHSafeDictionary.h
//  MiHome
//
//  Created by marteswang on 15/1/30.
//  Copyright (c) 2015年 小米移动软件. All rights reserved.
//
#import <Foundation/Foundation.h>

@interface MHSafeDictionary : NSMutableDictionary

/**
 *	@brief	如果不存在或者类型不符合要求，就返回nil
 *
 *	@param 	key 	key字符串
 *	@param 	objClass 	此值的类，若值不存在或不符合此类则会返回nil，特殊地，如果需要一个NSNumber类型，但是字典里是一个NSString类型，NSString会被尽可能地转换成NSNumber并返回
 *
 *	@return	返回值（一定是个oc对象）
 */
- (id)objectForKey:(id)key class:(Class)objClass;

/**
 *	@brief	把字典转换成safeDictionary
 *
 *	@param 	dictionary 	字典
 */
- (void)setObjectsInDictionary:(NSDictionary *)dictionary;

- (id)toJsonObject;
@end
