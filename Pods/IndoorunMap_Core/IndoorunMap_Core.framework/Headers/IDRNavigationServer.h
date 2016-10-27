//
//  IDRNavigationServer.h
//  YFMapKit
//
//  Created by ky on 16/4/26.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDRLocationServer.h"

@class IDRPosition;
@class IDRMapView;
@class IDRPassUnit;
@class IDRFloor;
@class IDRRegion;
@class IDRNavigationServer;
@class IDRNaviSuggestion;
@class IDRNaviParm;
@class IDRUserLocation;

typedef NS_ENUM(NSInteger, NaviServerStartStatus) {
    
    //启动成功
    NaviServerStartStatus_Success,
    
    //RegionData不存在
    NaviServerStartStatus_RegionDataNil,
    
    //定位服务启动失败（动态导航）
    NaviServerStartStatus_LocationServerFailed,
    
    //起点终点距离太近
    NaviServerStartStatus_TooNear,
    
    //跨楼层失败
    NaviServerStartStatus_PassNotFind,
};

/**
 *  IDRNaviParm
 */
@interface IDRNaviParm : NSObject

+ (instancetype)createWith:(IDRPosition*)start end:(IDRPosition*)end;

- (instancetype)initWith:(IDRPosition*)start end:(IDRPosition*)end;

@property (nonatomic, retain) IDRPosition *startPos;//起点

@property (nonatomic, retain) IDRPosition *endPos;//终点

@end

/**
 *  IDRNavigationServerDelegate
 */
@protocol IDRNavigationServerDelegate <NSObject>

@optional
/**
 *  导航结束回调
 *
 *  @param navi IDRNavigationServer实例
 */
- (void)navigationDidFinish:(IDRNavigationServer *)sender;
/**
 *  导航提示建议
 *
 *  @param sender    IDRNavigationServer实例
 *  @param naviSuggestion 导航建议
 */
- (void)navigation:(IDRNavigationServer *)sender didUpdateSuggestion:(IDRNaviSuggestion*)naviSuggestion;

/**
 *  导航启动成功
 *
 *  @param sender   IDRNavigationServer
 *  @param status   是否成功
 *  @param naviParm 导航参数
 */
- (void)navigation:(IDRNavigationServer *)sender didStartSuccess:(NaviServerStartStatus)status naviParm:(IDRNaviParm*)naviParm;

- (void)navigation:(IDRNavigationServer *)sender didUpdateData:(IDRNaviParm*)naviParm withPass:(IDRPassUnit*)pass;

@end

/**
 *  IDRNavigationServer
 */
@interface IDRNavigationServer : NSObject

+ (instancetype)instance;//实例变量

@property (nonatomic, weak) id<IDRNavigationServerDelegate> delegate;

/**
 *  车行导航（车行时跨楼层时找寻出口，入口，否则寻找电梯，扶梯，楼梯）
 */
@property (nonatomic, assign) BOOL carNavi;

/**
 *  如需在地图上显示导航线，需要设置对应mapview
 */
@property (nonatomic, weak) IDRMapView *mapView;

/**
 *  导航建议(为YES时需要实现didUpdateNaviSuggestion代理)
 */
@property (nonatomic, assign) BOOL naviSuggestion;

/**
 *  是否是动态导航
 */
@property (nonatomic, readonly) BOOL isDynamicNavi;

/**
 动态导航时需要设置定位器
 */
@property (nonatomic, weak) IDRLocationServer *locater;

/**
 *  开始导航
 *  @param region   对应区域
 *  @param naviParm 导航起点终点，如果起点为nil，以“我的位置”为起点（此时为动态导航）
 *
 */
- (void)startServer:(IDRRegion*)region navi:(IDRNaviParm*)naviParm;

/**
 *  停止导航
 */
- (void)stopServer;

/**
 *  获取对应楼层的导航路径
 *
 *  @param floor 对应楼层
 *
 *  @return IDRPosition数组
 */
- (NSArray*)retriveNaviPath:(IDRFloor*)floor;

/**
 *  更新定位位置
 *
 *  @param userLocation 定位位置
 */
- (void)updateUserLocation:(IDRUserLocation *)userLocation;

@end
