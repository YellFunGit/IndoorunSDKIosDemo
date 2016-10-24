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

/**
 *  获取所有region
 *
 *  @param success 处理所有正确regions
 *  @param failure 对错误进行处理
 */
- (void)loadTotalRegions:(void(^)(NSArray *regions))success failure:(void(^)())failure;

/**
 加载region所有数据

 @param region 对应region
 */
- (void)loadRegionAllData:(IDRRegion*)region success:(void(^)(IDRRegionData* regionAllInfo))success failure:(void(^)())failure;

@end
