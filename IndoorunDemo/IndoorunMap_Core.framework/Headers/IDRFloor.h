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
@property (nonatomic, retain) NSArray *unitList;
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
@property (nonatomic, retain) NSNumber *modifyTime;
/**
 *  采集线集合
 */
@property (nonatomic, retain) NSArray *collectLineList;
/**
 *  unit最后编辑时间
 */
@property (nonatomic, retain) NSNumber *unitModifyTime;
/**
 *  采集数据更新时间
 */
@property (nonatomic, retain) NSNumber *collectModifyTime;
/**
 *  地图更新时间
 */
@property (nonatomic, retain) NSNumber *mapModifyTime;
/**
 *  楼层路线数据
 */
@property (nonatomic, retain) IDRPath *path;

- (BOOL)equalFloor:(IDRFloor*)floor;

- (NSArray*)getUnitsWithUnitType:(NSInteger)typeId;

- (IDRUnit*)getNearUnitWIthCurreentPosition:(IDRPosition*)p targets:(NSArray*)targets;

- (IDRUnit*)getNearCarUnitWithCurreentPosition:(IDRPosition*)p targets:(NSArray*)targets;

- (IDRPosition*)getNearPositionWithCurrentPosition:(IDRPosition*)p targets:(NSArray*)targets;

@end
