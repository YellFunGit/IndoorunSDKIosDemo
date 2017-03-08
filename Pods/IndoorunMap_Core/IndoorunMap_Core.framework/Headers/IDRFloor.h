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
#import "IDRLine.h"

/**
 *  楼层数据
 */
@interface IDRFloor : NSObject

- (id)initWithJson:(NSDictionary*)jsonData;

@property (nonatomic, copy) NSString *Id; //floorId

@property (nonatomic, copy) NSString *regionId;//regionId

@property (nonatomic, copy) NSString *title;//名称

@property (nonatomic) NSInteger floorIndex;//楼层index

@property (nonatomic) NSInteger width;//地图宽

@property (nonatomic) NSInteger height;//地图长

@property (nonatomic, copy) NSArray<IDRLine*> *lines;//路径列表

@property (nonatomic, copy) NSArray<IDRUnit*> *unitList;//unit列表

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
 获取公共设施unit
 
 @return unit数组
 */
- (NSArray*)getFaciUnits;

/**
 获取所有公共设施类型
 
 @return unit类型数组
 */
- (NSArray*)getTotalFaciTypes;

@end
