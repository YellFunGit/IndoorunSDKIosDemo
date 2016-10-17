//
//  YFBeaconManager.h
//  YFMapKit
//
//  Created by Sincere on 16/1/20.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class CLHeading;

/*
 * 在开启定位前，检测周围是否有蓝牙
 */

/*
 * 当定位中出现无法获取蓝牙时开启的检测工具
 * 如果再次获取蓝牙，切换回动态定位状态
 */

@protocol IDRBaseLocationServerDelegate <NSObject>

@required
/**
 *  返回ibeacon的数据
 *
 *  @param beacons beacon的数据
 */
- (void)didGetRangeBeacons:(NSArray*)beacons;

@optional

/**
 *  更新deviece heading
 *
 */
- (void)didGetDeviceHeading:(CLHeading*)heading;

@end

@interface IDRBaseLocationServer : NSObject

+ (instancetype)sharedInstance;

- (void)setBeaconUUID:(NSArray*)uuidStrings;

/*
 *  开始获取蓝牙信息
 */

- (void)startUpdateBeacons;

- (void)startUpdateHeading;

/*
 *  停止获取蓝牙信息
 */
- (void)stopUpdateBeacons;

- (void)stopUpdateHeading;

@property(nonatomic, weak) id<IDRBaseLocationServerDelegate> delegate;

@property (nonatomic, assign, readonly) BOOL isLocationAvailable;

@end
