//
//  IDRDataManager.h
//  YFMapKit
//
//  Created by Sincere on 16/1/20.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDRRegion;
@class IDRFloor;
@class IDRUnit;
@class IDRPath;
@class IDRPosition;
@class IDRPassUnit;
@class IDRPassData;
@class IDRRegionData;
@class IDRAllRegionsTimestamp;

@interface IDRDataManager : NSObject

+ (instancetype)sharedInstance;

/*
 * 获取Region下的总体数据
 */
- (void)loadAllDataWithRegion:(IDRRegion *)region success:(void(^)(IDRRegionData *regionData))success failure:(void(^)())failure;

/**
 *  获取离线定位数据
 *
 */
- (void)loadLocateBaseData:(IDRRegion *)region success:(void(^)(NSDictionary *data))block failure:(void(^)())failure;

/*
 * 获取Map数据
 */
- (void)loadMapWithRegion:(IDRRegion *)region floor:(IDRFloor *)floor success:(void(^)(NSString * vbf))block;

/**
 *  获取所有region
 *
 *  @param success 处理所有正确regions
 *  @param failure 对错误进行处理
 */
- (void)loadTotalRegions:(void(^)(NSArray *regions))success failure:(void(^)())failure;

@end
