//
//  YFLocationManager.h
//  YFMapKit
//
//  Created by Sincere on 16/1/20.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDRPosition;
@class IDRRegion;
@class IDRRegionEx;
@class IDRUserLocation;
@class IDRFenceHandler;
@class IDRFence;
@class IDRFloor;
@class IDRMapView;

typedef NS_ENUM(NSInteger, LocateStartResult) {
    
    LocateStart_success,//定位开启成功
    LocateStart_bluetoothDisable,//蓝牙异常
    LocateStart_locationAvailable,//定位服务异常
    LocateStart_networkDisable,//网络异常
    LocateStart_regionDisable,//场景不支持定位
};

/*
 * 定位所需的蓝牙数据由本类进行获取
 */

@protocol IDRLocationServerDelegate;

@interface IDRLocationServer : NSObject

@property (nonatomic, assign, readonly, getter = isServerStarted) BOOL serverStarted;//服务是否开启

@property (nonatomic, retain, readonly) IDRUserLocation *userLocation;//定位结果

@property (nonatomic, assign) BOOL useWalkFilter;//人行惯导

@property (nonatomic, assign) BOOL useCarFilter;//车行惯导

@property (nonatomic, assign) NSInteger beaconCount;//最近一次蓝牙数量

@property (nonatomic, strong) IDRFenceHandler *areaHandler;//围栏管理

@property (nonatomic, weak) id<IDRLocationServerDelegate> delegate;

/*
 *  开始定位
 */
- (LocateStartResult)startServer:(IDRMapView*)map;

- (LocateStartResult)startServer:(IDRMapView*)map withUUID:(NSString*)uuid;

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

//围栏
@interface IDRLocationServer (FenceAPI)

/**
 添加围栏
 
 @param area 围栏
 */
- (void)addFence:(IDRFence*)area;

/**
 移除围栏
 
 @param area 围栏
 */
- (void)removeFence:(IDRFence*)area;

@end
