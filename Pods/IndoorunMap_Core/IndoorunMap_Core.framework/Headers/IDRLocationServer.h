//
//  YFLocationManager.h
//  YFMapKit
//
//  Created by Sincere on 16/1/20.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDRPosition;
@class IDRPath;
@class IDRRegion;
@class IDRRegionData;
@class IDRUserLocation;
@protocol IDRLocationServerDelegate;
@class IDRFloor;

typedef NS_ENUM(NSInteger, LocateStartResult) {
    
    LocateStart_bluetoothDisable,//蓝牙异常
    LocateStart_locationAvailable,//定位服务异常
    LocateStart_networkDisable,//网络异常
    LocateStart_regionDisable,//场景不支持定位
    LocateStart_success,//定位开启成功
};

/*
 * 定位所需的蓝牙数据由本类进行获取
 */
@interface IDRLocationServer : NSObject

+ (instancetype)instance;//实例变量

@property (nonatomic, assign, readonly, getter = isServerStarted) BOOL serverStarted;

@property (nonatomic, retain, readonly) IDRUserLocation *userLocation;

//人行惯导
@property (nonatomic, assign) BOOL useWalkFilter;

//车行惯导
@property (nonatomic, assign) BOOL useCarFilter;

@property (nonatomic) IDRPosition *startPos;

@property (nonatomic) NSTimeInterval timeInterval;

/**
 *  delegate
 */
@property (nonatomic, weak) id<IDRLocationServerDelegate> delegate;

/*
 *  开始定位
 */
- (LocateStartResult)startServer:(IDRRegion*)region;

/*
 *  停止定位
 */
- (void)stopServer;

/**
 *  请求定位
 *
 *  @param beacons 指纹数据
 */
- (void)onLocateCall:(NSArray*)beacons;

@end

@protocol IDRLocationServerDelegate <NSObject>

@optional

/**
 *  定位成功，返回正确结果
 *
 *  @param position 定位位置数据
 */
- (void)location:(IDRLocationServer*)locationServer didLocationSuccess:(IDRUserLocation*)userLocation;

/**
 *  定位error
 *
 *  @param regionId 对应的regionid
 */
- (void)location:(IDRLocationServer*)locationServer didLocationFailed:(NSString*)regionId;

/**
 *  车行惯导OK
 *
 *  @param regionId 对应的regionid
 */
- (void)location:(IDRLocationServer*)locationServer carInsValid:(BOOL)valid;

@end
