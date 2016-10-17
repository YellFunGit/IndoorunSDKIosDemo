//
//  AutoRegionLocator.h
//  YFTools
//
//  Created by ky on 16/4/28.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class IDRPrelocateManager;

@class IDRPosition;

@protocol IDRPrelocateManagerDelegate <NSObject>

/**
 *  定位预判（室内室外）
 *
 *  @param sender self
 *  @param data   预定位成功服务器返回的数据
 */
- (void)prelocate:(IDRPrelocateManager*)sender didGetNearRegionData:(NSDictionary*)data;

@end

@interface IDRPrelocateManager : NSObject

@property (nonatomic, weak) id<IDRPrelocateManagerDelegate> delegate;

- (void)loadNearRegions:(CLLocationCoordinate2D)userLocation inRegions:(NSArray*)regions;

@end
