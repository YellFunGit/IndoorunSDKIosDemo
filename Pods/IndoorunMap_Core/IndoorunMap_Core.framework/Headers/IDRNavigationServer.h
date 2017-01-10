//
//  IDRNavigationServer.h
//  YFMapKit
//
//  Created by ky on 16/4/26.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class IDRLocationServer;
@class IDRPassUnit;
@class IDRRouteResult;
@class IDRPosition;
@class IDRMapView;
@class IDRFloor;
@class IDRRegionEx;
@class IDRNavigationServer;
@class IDRNaviSuggestion;
@class IDRNaviParm;

typedef NS_ENUM(NSInteger, NaviServerStartStatus) {
    
    //启动成功
    NaviServerStartStatus_Success,
    
    //RegionData不存在
    NaviServerStartStatus_RegionDataNil,
    
    //定位服务启动失败（动态导航）
    NaviServerStartStatus_LocationServerFailed,
    
    //起点终点距离太近
    NaviServerStartStatus_TooNear,
    
    //路径数据没找到
    NaviServerStartStatus_PassNotFind,
};

/**
 *  IDRNaviParm
 */
@interface IDRNaviParm : NSObject

+ (instancetype)createWith:(IDRPosition*)start end:(IDRPosition*)end car:(BOOL)carNavi;

- (instancetype)initWith:(IDRPosition*)start end:(IDRPosition*)end car:(BOOL)carNavi;

@property (nonatomic, retain) IDRPosition *startPos;//起点

@property (nonatomic, retain) IDRPosition *endPos;//终点

@property (nonatomic) BOOL isCarNavi;//是否车行

@end

/**
 *  IDRNavigationServerDelegate
 */
@protocol IDRNavigationServerDelegate <NSObject>

@optional
/**
 *  导航启动成功
 *
 *  @param sender   IDRNavigationServer
 *  @param status   是否成功
 *  @param naviParm 导航参数
 */
- (void)navigation:(IDRNavigationServer *)sender didStartSuccess:(NaviServerStartStatus)status naviParm:(IDRNaviParm*)naviParm;
/**
 *  导航信息提示
 *
 *  @param sender    IDRNavigationServer实例
 *  @param naviSuggestion 导航信息
 */
- (void)navigation:(IDRNavigationServer *)sender didUpdateSuggestion:(IDRNaviSuggestion*)naviSuggestion;

/**
 规划路径成功

 @param sender IDRNavigationServer实例
 @param routeResult 路径规划结果
 */
- (void)navigation:(IDRNavigationServer *)sender didFinishRoute:(IDRRouteResult*)routeResult;

@end

/**
 *  IDRNavigationServer
 */
@interface IDRNavigationServer : NSObject

+ (instancetype)instance;//实例变量

@property (nonatomic, weak) id<IDRNavigationServerDelegate> delegate;

@property (nonatomic, assign) BOOL carNavi;//车行导航（车行时跨楼层时找寻出口，入口，否则寻找电梯，扶梯，楼梯）

@property (nonatomic, readonly) BOOL isDynamicNavi;//是否是动态导航

@property (nonatomic) CGFloat limitDistanceStartNavi;//启动导航的最小距离限制

@property (nonatomic, weak) IDRLocationServer *locater;//动态导航时需要设置定位器

/**
 *  开始导航
 *  @param region   对应区域
 *  @param naviParm 导航起点终点，如果起点为nil，以“我的位置”为起点（此时为动态导航）
 *
 */
- (void)startServer:(IDRMapView*)map navi:(IDRNaviParm*)naviParm;

/**
 *  停止导航
 */
- (void)stopServer;

/**
 *  获取对应楼层的导航路径1
 *
 *  @param floor 对应楼层
 *
 *  @return IDRPosition数组
 */
- (NSArray*)retriveNaviPath:(IDRFloor*)floor;

/**
 更新终点位置

 @param newPos 新位置，触发重新规划路径
 */
- (void)updateEndPos:(IDRPosition *)newPos;

/**
 重新规划路径
 */
- (void)reRoutePath;

@end
