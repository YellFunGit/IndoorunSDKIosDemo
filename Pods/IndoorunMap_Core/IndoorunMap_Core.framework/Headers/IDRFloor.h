//
//  IDRFloor.h
//  YellfunMapKit
//
//  Created by Sincere on 15/7/30.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IDRRegion.h"
#import "IDRUnit.h"
#import "IDRMapKitConfig.h"

@class IDRPath;
/**
 *  楼层数据
 */
@interface IDRFloor : NSObject

/**
 *  id
 */
@property (nonatomic, copy) NSString *Id;
/**
 *  regionId
 */
@property (nonatomic, copy) NSString *regionId;
/**
 *  名称
 */
@property (nonatomic, copy) NSString *title;
/**
 *  unit集合
 */
@property (nonatomic, strong) NSArray *unitList;
/**
 *  地图URL
 */
@property (nonatomic, copy) NSString *mapUrl;
/**
 *  记录时间
 */
@property (nonatomic, copy) NSNumber *recordTime;
/**
 *  最后更新时间
 */
@property (nonatomic, strong) NSNumber *modifyTime;
/**
 *  采集线集合
 */
@property (nonatomic, strong) NSArray *collectLineList;
/**
 *  unit最后编辑时间
 */
@property (nonatomic, strong) NSNumber *unitModifyTime;
/**
 *  采集数据更新时间
 */
@property (nonatomic, strong) NSNumber *collectModifyTime;
/**
 *  地图更新时间
 */
@property (nonatomic, strong) NSNumber *mapModifyTime;
/**
 *  楼层路线数据
 */
@property (nonatomic, strong) IDRPath *path;

/**
 两个floor是否是同一floor

 @param floor 传入的

 @return 是否同一floor
 */
- (BOOL)equalFloor:(IDRFloor*)floor;

/**
 获取某一类型的一组unit

 @param typeId 类型id

 @return 返回的数组
 */
- (NSArray*)getUnitsWithUnitType:(UnitType)typeId;

/**
 获取离输入的位置最近的unit

 @param p       位置
 @param targets 终点集合

 @return 终点Unit（路线终点）
 */
- (IDRUnit*)getNearUnitWIthCurreentPosition:(IDRPosition*)p targets:(NSArray*)targets;

@end
