//
//  IDRCoreManager.h
//  YFMapKit
//
//  Created by Sincere on 16/1/18.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>

#import "IDRRegion.h"
#import "IDRFloor.h"
#import "IDRUnit.h"
#import "IDRPath.h"
#import "IDRPosition.h"

@class IDRLocationServer;
@class IDRNavigationServer;
@class IDRWalkDetectorServer;

typedef float(^CalcDistance)(CLLocationCoordinate2D pos1, CLLocationCoordinate2D pos2);

@class IDRCoreManager;

@protocol IDRCoreManagerDelegate <NSObject>

@required
/**
 *  启动服务代理
 *
 *  @param sender  instance
 *  @param success 成功或者失败, 成功时regions有值
 */
- (void)idrCoreManager:(IDRCoreManager*)sender didServerStartSuccess:(BOOL)success regions:(NSArray*)regions;

@end

/*
 * IDRCoreManager
 * 获取授权状态，加载本地数据
 */
@interface IDRCoreManager : NSObject

/*
 * 获取对象
 */
+ (instancetype)sharedInstance;

/**
 *  启动服务
 *
 *  @param appId
 *  @param appkey
 */
- (void)initWith:(NSString*)appId appkey:(NSString*)appkey;

/**
 *  启动服务(deprecated, please use initWith::)
 *  @param account  账号
 *  @param password 密码
 */
- (void)initServer:(NSString*)account password:(NSString*)password;

/**
 *  进入region
 *
 *  @param region 需要进入的region
 */
- (void)enterRegion:(IDRRegion*)region;

/**
 *  离开region
 */
- (void)leaveRegion;

/**
 *  获取定位服务
 */
+ (IDRLocationServer*)locationServer;

/**
 *  获取导航服务
 */
+ (IDRNavigationServer*)navigationServer;

/**
 *  静止切步行检测
 *
 */
+ (IDRWalkDetectorServer*)walkDetectorServer;

- (IDRRegion*)retriveRegion:(NSString*)regionId;

/**
 *  获取最近的Region
 *
 *  @param location 坐标
 */
- (IDRRegion*)loadNearRegionData:(CLLocationCoordinate2D)userLocation inRegions:(NSArray*)regions block:(CalcDistance)calcDistance;

- (NSMutableArray*)loadNearRegions:(CLLocationCoordinate2D)userLocation inRegions:(NSArray*)regions block:(CalcDistance)calcDistance;

@property (nonatomic, weak) id <IDRCoreManagerDelegate> delegate;

@property (nonatomic, copy) NSString *sessionKey;

@property (nonatomic, copy, readonly) NSString *appiduuidsession;

@property (nonatomic, retain) NSArray<IDRRegion *> *regions;

@property (nonatomic, assign, getter = isInitSuccess) BOOL initSuccess;

@end
