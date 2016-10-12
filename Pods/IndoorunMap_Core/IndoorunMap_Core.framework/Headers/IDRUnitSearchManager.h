//
//  IDRUnitSearchManager.h
//  YFMapKitDemo
//
//  Created by Sincere on 15/12/10.
//  Copyright © 2015年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDRPosition.h"
#import "IDRUnit.h"

@interface IDRUnitSearchManager : NSObject

+ (instancetype)sharedUnitSearchManager;
@property (nonatomic,copy) NSArray * currentUnitsData;

/**
 *  关键字查找unit
 *
 *  @param unitName 关键字
 *
 *  @return [{IDRPosition:obj,IDRUnit:obj},...,nil];
 */
- (NSArray *)getUnitsWithKeyword:(NSString *)unitName;

/**
 *  获取当前units的所有类型
 *
 *  @return 元素为NSNumber类型的UnitTypeId数组
 */
- (NSArray *)getAllUnitsType;

/**
 *  获取某一类型的所有Units
 *
 *  @param typeId 要获取的Units类型
 *
 *  @return 符合条件的Units数组
 */
- (NSArray *)getUnitsWithUnitTypeId:(NSNumber *)typeId;

/**
 *  根据position来获取对应的unit
 *
 *  @param position
 *
 *  @return 最近的unit
 */
- (IDRUnit *)getUnitWithPosition:(IDRPosition *)position;

/**
 *  根据unit获取position
 *
 *  @param p
 *
 *  @return
 */
- (IDRPosition *)getUnitPositionWithPosition:(IDRPosition *)p;

@end
