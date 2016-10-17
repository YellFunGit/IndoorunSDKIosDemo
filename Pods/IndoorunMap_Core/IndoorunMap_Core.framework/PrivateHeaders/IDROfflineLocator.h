//
//  IDROfflineLocator
//  YFMapKit
//
//  Created by ky on 16/4/12.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class IDRPosition;
@class IDRRegion;

@interface IDROfflineLocator :NSObject

@property (nonatomic, copy) IDRRegion *region;

- (IDRPosition*)getLocatePos:(NSArray*)beacons offsetX:(CGFloat)x offsetY:(CGFloat)y floor:(NSString*)floorId;

- (NSString*)getCorrectFloor:(NSArray*)beacons floorId:(NSString*)floorId;

- (IDRPosition*)getOfflineLocation:(NSArray*)beacons floorId:(NSString*)maybeFloor;

- (void)loadRegionData:(IDRRegion*)region;

- (IDRPosition*)getOfflineLocation:(NSArray*)beacons floorId:(NSString*)maybeFloor;

@end
