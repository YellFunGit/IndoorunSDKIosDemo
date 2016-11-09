//
//  IDRDataManager.h
//  YFMapKit
//
//  Created by Sincere on 16/1/20.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDRRegion;
@class IDRRegionData;

@interface IDRDataManager : NSObject

+ (instancetype)sharedInstance;

/**
 *  获取所有region
 *
 *  @param success success block
 *  @param failure failure block
 */
- (void)loadTotalRegions:(void(^)(NSArray *regions))success failure:(void(^)())failure;

/**
 加载region所有数据

 @param region 对应region
 */
- (void)loadRegionAllData:(IDRRegion*)region success:(void(^)(IDRRegionData* regionAllInfo))success failure:(void(^)())failure;

@end
