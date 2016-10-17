//
//  IDRCacheManager.h
//  YFMapKit
//
//  Created by Sincere on 16/1/20.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IDRRegion.h"
#import "IDRFloor.h"
#import "IDRUnit.h"
#import "IDRPath.h"
#import "IDRPosition.h"

@interface IDRCacheManager : NSObject

+ (instancetype)sharedInstance;

/**
 *  检测文件夹是否存在
 *
 *  @param path 文件夹路径
 *
 *  @return 存在返回YES，否则返回NO
 */
- (BOOL)checkFolderWithFolderPath:(NSString*)path;

- (BOOL)createFolderWithFolderPath:(NSString *)path;

/**
 *  创建区域缓存文件夹
 *  文件夹名为aRegion.name_aRegion.id
 *  @param aRegion
 */
- (void)createRegionFolderWith:(IDRRegion*)aRegion;

/**
 *  在区域文件夹下创建楼层缓存文件夹
 *  文件夹名为aFloor.name_aFloor.id
 *  @param aRegion
 *  @param aFloor
 */
- (void)createFloorFolderWith:(IDRRegion*)aRegion
                        floor:(IDRFloor*)aFloor;

/**
 *  在楼层文件夹下创建地图缓存文件夹
 *  文件夹名为Map
 *  @param aRegion
 *  @param aFloor
 */
- (void)createMapFolderWith:(IDRRegion*)aRegion
                      floor:(IDRFloor*)aFloor;

/**
 *  在楼层文件夹下创建单元缓存文件夹
 *  文件夹名为Unit
 *  @param aRegion
 *  @param aFloor
 */
- (void)createUnitFolderWith:(IDRRegion*)aRegion
                      floor:(IDRFloor*)aFloor;

/**
 *  在楼层文件夹下创建区域unit缓存文件夹
 *
 *  @param aRegion
 *  @param aFloor
 */
- (void)createQuyuFolderWith:(IDRRegion*)aRegion
                       floor:(IDRFloor *)aFloor;

/**
 *  在楼层文件夹下创建路径缓存文件夹
 *  文件夹名为Path
 *  @param aRegion
 *  @param aFloor
 */
- (void)createPathFolderWith:(IDRRegion*)aRegion
                      floor:(IDRFloor*)aFloor;

/**
 *  缓存所有的region信息
 *  文件夹名为Path
 *  @param allregions
 */
- (void)saveAllRegions:(NSArray *)allregions;

/**
 *  加载缓存的regions信息
 *  @return 之前缓存的数据
 */
- (NSArray*)loadAllRegions;

@end

FOUNDATION_EXPORT NSString *YFCachePath(IDRRegion *region,IDRFloor *floor);
