//
//  IDRMapView.h
//  YFMapKit
//
//  Created by yellfun on 16/2/3.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDRMapMarker.h"
#import "IDRMapKitConfig.h"


@class IDRRegion;
@class IDRRegionEx;
@class IDRFloor;
@class IDRPosition;
@class IDRMapModeBtn;
@class IDRMapView;
@class IDRUserLocation;
@class CLHeading;
@class IDRUnit;
@class IDRMap;
@class IDRGlesMap;
@class IDR3DMap;
@class IDRUnit;
@class IDRNaviSuggestion;
@class IDRFloorView;
@class IDRNavigationServer;
@class IDRLocationServer;
@class IDRRouteResult;
@class IDRLine;

@protocol IDRMapViewDelegate <NSObject>

@optional

- (void)mapView:(IDRMapView*)map didChangeState:(NSInteger)state;

/**
 地图加载成功

 @param mapView 地图view
 @param region  加载的区域
 @param floor   加载的楼层
 */
- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegionEx*)regionEx;

/**
地图加载失败

 @param mapView 地图view
 @param region 加载的区域
 @param floor 加载的楼层
 */
- (void)mapViewLoadFailure:(IDRMapView *)mapView region:(IDRRegion*)region;

/**
 切换楼层完毕

 @param mapView 地图view
 @param floor 切换的楼层
 */
- (void)mapViewFinishChangeFloor:(IDRMapView *)mapView floor:(IDRFloor*)floor;

/**
 地图状态切换

 @param mapView    地图view
 @param oldMapMode 地图之前的状态
 @param newMode    地图之后的状态
 */
- (void)mapView:(IDRMapView*)mapView didMapModeChange:(IDRMapMode)oldMapMode newMode:(IDRMapMode)newMode;

/**
 地图进行旋转、平移、缩放操作回

 @param mapView 地图view
 */
- (void)mapDidTransform:(IDRMapView *)mapView;

/**
 单击一个marker的回调
 
 @param mapView 地图View
 @param marker 选中的marker

 @return 是否继续响应onClickUnit,onClickMap,为NO时响应继续传递
 */
- (BOOL)mapView:(IDRMapView *)mapView onClickMarker:(id<IDRMapMarkerProtocal>)marker;

/**
 长按marker的回调

 @param mapView 地图view
 @param marker 选中的marker

 @return 是否继续响应onLongPressUnit,onLongPressMap,为NO时响应继续传递
 */
- (BOOL)mapView:(IDRMapView *)mapView onLongPressMarker:(id<IDRMapMarkerProtocal>)marker;

/**
 选中地图上的Unit会回调此接口

 @param mapView 地图View
 @param unit    选中的unit

 @return 是否继续响应onClickMap,为NO时响应继续传递
 */
- (BOOL)mapview:(IDRMapView *)mapView onClickUnit:(IDRUnit*)unit;

/**
 长按unit时会回调此接口

 @param mapview 地图View
 @param unit  地图坐标

 @return 是否继续响应onLongPressMap,为NO时响应继续传递
 */
- (BOOL)mapview:(IDRMapView *)mapView onLongPressUnit:(IDRUnit*)unit;

/**
 *双击地图时会回调此接口
 *@param mapview 地图View
 *@param pos  地图坐标
 */
- (void)mapview:(IDRMapView *)mapView onDoubleClick:(IDRPosition*)pos;

/**
 *单击地图时会回调此接口
 *@param mapview 地图View
 *@param pos  地图坐标
 */
- (void)mapview:(IDRMapView *)mapView onClickMap:(IDRPosition*)pos;

/**
 *长按地图时会回调此接口
 *@param mapview 地图View
 *@param pos  地图坐标
 */
- (void)mapview:(IDRMapView *)mapView onLongPressMap:(IDRPosition*)pos;

/**
 点击定位按钮触发此回调

 @param mapView 地图view
 @param sender button
 */
- (void)mapview:(IDRMapView *)mapView onLocateClick:(IDRMapModeBtn*)sender;

/**
 点击AR小地图

 @param mapView 地图view
 */
- (void)clickMiniMap:(IDRMapView *)mapView;

@end

/**
 *  地图View类，使用此View可以显示地图窗口，并且对地图进行相关的操作
 */
@interface IDRMapView : UIView

@property (nonatomic, assign) BOOL ar3DMap;//ar3d地图

@property (nonatomic, assign) IDRMapMode mapMode;//地图当前mode(自由，定位，跟随)

@property (nonatomic, weak) id<IDRMapViewDelegate> delegate;

@property (nonatomic, retain) IDRRegionEx *regionEx;//地图显示的区域

@property (nonatomic, retain) IDRFloor *currentFloor;//当前显示的楼层

@property (nonatomic, assign) BOOL enableTransform;//是否支持旋转缩放平移手势

@property (nonatomic, assign) BOOL enableClick;//是否支持点击响应

@property (nonatomic, assign) BOOL enableLongPress;//是否支持长按响应

@property (nonatomic, assign) BOOL enableDoubleFingerSinglePress;//是否支持双指单击缩小

@property (nonatomic, readonly) CGFloat mapRotate;//地图的旋转角度

@property (nonatomic, retain) IDRPosition *userPos;//定位点位置

@property (nonatomic, readonly) IDRGlesMap *glesMap;//opengles地图

@property (nonatomic, assign) CGRect miniMapFrame;//仅在AR模式下有效

- (void)onMapStateChange:(NSInteger)state;

/**
 设置当前的位置与方向

 @param userLocation 位置与方位
 */
- (void)setUserLocation:(IDRUserLocation*)userLocation;

/**
 更新设备方向

 @param heading 设备方向
 */
- (void)updateHeading:(CLHeading*)heading;

/**
 加载地图view

 @param region 加载的region
 */
- (void)loadMap:(IDRRegion*)region;

/**
 切换楼层

 @param floor 对应楼层数据, 可以从IDRRegion中取得
*/
- (BOOL)changeFloor:(NSString*)floorId;

/**
 获取最近的unit

 @param pos  地图坐标
 @param type unit类型

 @return 最近的unit
 */
- (IDRUnit*)findMostNearUnit:(IDRPosition*)pos type:(UnitType)type;

/**
 根据Ids获取unit数组

 @param unitIds 名字数组
 @return unit数组
 */
- (NSArray<IDRUnit*>*)findUnits:(NSArray<NSString*>*)unitIds;

/**
 获取最近的marker

 @param pos 地图坐标

 @return 返回的marker
 */
- (id<IDRMapMarkerProtocal>)findMark:(IDRPosition*)pos;

/**
 缩放
 
 @param zoomScale   放大的倍数
 @param anchor      锚点(地图坐标)
 @param anim        是否渐进动画
 */
- (void)zoom:(CGFloat)zoomScale anchor:(CGPoint)anchor anim:(BOOL)anim;

/**
 放大一级比例尺
 */
- (void)zoomIn;

/**
 缩小一级比例尺
 */
- (void)zoomOut;

/**
 地图缩放比例
 @return 缩放比例,单位（逻辑像素/米）
 */
- (CGFloat)mapScale;

/**
 地图宽
 */
- (CGFloat)mapWidth;

/**
 地图高
 */
- (CGFloat)mapHeight;

/**
 地图中心点
 */
- (CGPoint)mapCenter;

- (void)mapOnTranform;

- (void)mapDidChangeTo2DScene:(NSInteger)floorIndex;

/**
 平移
 @param x x平移量(屏幕坐标)
 @param y y平移量(屏幕坐标)
 @param anim 是否动画
 */
- (void)scroll:(CGFloat)x y:(CGFloat)y anim:(BOOL)anim;

/**
 重置地图(地图的位置、旋转、缩放、倾斜等都重置为加载的默认状态)
 */
- (void)resetMap;

/**
 停止地图渲染
 */
- (void)pause;

/**
 恢复地图渲染
 */
- (void)resume;

/**
 鸟瞰地图（缩放地图以至能完全显示导航线）
 */
- (void)birdLook;

/**
 设置鸟瞰地图边距
 
 @param left 左边距
 @param top 上边距
 @param right 右边距
 @param bottom 下边距
 */
- (void)setBirdLookMargin:(CGFloat)left top:(CGFloat)top right:(CGFloat)right bottom:(CGFloat)bottom;

/**
 居中pos，同时进行缩放

 @param pos 居中的位置（如果pos不在当前显示楼层，会自动切换楼层然后居中）
 */
- (void)centerPos:(IDRPosition*)pos;

/**
 获取导航状态

 @return 当前导航状态，详情参见IDRNaviSuggestion类
 */
- (IDRNaviSuggestion*)getNavStatus;

/**
 显示路径

 @param naviPaths 导航路点
 */
- (void)showPaths:(NSArray*)naviPaths;

/**
 是否显示定位罗盘

 @param show 是否显示
 */
- (void)showComposs:(BOOL)show;

/**
 *  罗盘是否显示偏转圆弧
 */
- (void)showCompossRoute:(BOOL)show;

/**
 显示导航引导线

 @param show 是否显示
 */
- (void)showRouteDirectLine:(BOOL)show;

/**
 是否强制投影点至导航线

 @param force 是否强制投影
 */
- (void)forceRoute:(BOOL)force;

/**
 添加默认定位按钮控件
 */
- (void)addDefaultMapModeBtn;

/**
 添加默认楼层列表控件

 @return 楼层控件
 */
- (IDRFloorView*)addDefaultFloorListView;

/**
 在地图上加上一条字符串

 @param text 字符串内容
 @param p    位置

 @return 返回字符串的ID，需要移除时，调用Removelabel
 */
- (NSInteger)addLabel:(NSString*)text pos:(CGPoint)p;

/**
 移除地图上的字符串

 @param Id 字符串ID
 */
- (void)removeLabel:(NSInteger)Id;

@property (nonatomic) BOOL showPlotingScale;//是否显示比例尺

@property (nonatomic) CGPoint scaleOrigin;//比例尺位置

@property (nonatomic) BOOL showCompassBtn;//左上角的指南针按钮是否显示

@property (nonatomic) CGPoint compassBtnCenter;//左上角的指南针按钮坐标

@property (nonatomic, strong) IDRMapModeBtn *mapModeBtn;//左下角的地图状态按钮，默认不显示，需要主动调用addDefaultMapModeBtn;

@property (nonatomic, strong) IDRFloorView *floorListView;//右上角的楼层列表控件，默认不显示，需要主动调用addDefaultFloorListView;

@property (nonatomic, strong) UIView *compassBtn;//左上角的指南针按钮，默认添加，如用户需要修改，则请自行添加并调用addNorthAngleBtn

@property (nonatomic) BOOL enableChangeFloor;//是否能切换楼层

@property (nonatomic, strong) UIColor *backColor;//地图背景色

- (void)doAddMarker:(id<IDRMapMarkerProtocal>)marker;

- (void)doRemoveMarker:(id<IDRMapMarkerProtocal>)marker;

/**
 添加指南针按钮

 @param view 按钮view
 */
- (void)addNorthAngleBtn:(UIView*)view;

/**
 根据地图坐标，获取屏幕坐标

 @param mapPos 地图坐标

 @return 屏幕坐标
 */
- (CGPoint)getScreenPos:(IDRPosition*)mapPos;

/**
 根据地图view的坐标，获取地图坐标

 @param screenPoint 地图view上的坐标

 @return 地图坐标
 */
- (IDRPosition*)getMapPos:(CGPoint)screenPoint;

/**
 更新指南针角度
 */
- (void)updateNorthAngle;

/**
 是否自动切换到定位点所在楼层
 */
@property (nonatomic, assign) BOOL autoChangeToUserFloor;

/**
 当前mapView中所有的marker
 */
@property (nonatomic, retain) NSMutableArray *markers;

/**
 NavState:地图的导航状态（普通状态、导航状态）
 NO   默认为普通状态
 YES  导航状态
 */
@property (nonatomic, assign) BOOL naviState;

/**
 导航器
 */
@property (nonatomic, weak) IDRNavigationServer *navigator;

/**
 定位器
 */
@property (nonatomic, weak) IDRLocationServer *locator;

@end

/**
 地图View类(和Marker操作相关的接口)
 */
@interface IDRMapView (MarkerAPI)

/**
 向地图view添加Marker

 @param marker 要添加的marker
 */
- (void)addMarker:(id<IDRMapMarkerProtocal>)marker;

/**
 向地图view添加一组marker

 @param markers 要添加的marker数组
 */
- (void)addMarkers:(NSArray*)markers;

/**
 移除marker

 @param marker 要移除的marker
 */
- (void)removeMarker:(id<IDRMapMarkerProtocal>)marker;

/**
 移除一组marker

 @param markers 要移除的marker数组
 */
- (void)removeMarkers:(NSArray*)markers;

/**
 重新设置marker的位置

 @param newPos 新位置
 @param marker 需要设置的marker
 */
- (void)setMarkerPos:(IDRPosition*)newPos marker:(id<IDRMapMarkerProtocal>)marker;

/**
 重新设置marker的图标

 @param newIcon 新icon
 @param marker 需要设置的marker
 */
- (void)setMarkerImage:(NSString*)newIcon marker:(id<IDRMapMarkerProtocal>)marker;

@end

//---------------------------------------------------------------------
///
@interface IDRMapView (UnitAPI)

/**
 更新一组Units的颜色

 @param units units数组
 */
- (void)updateUnitsColor:(NSArray<IDRUnit*>*)units;

/**
 清除当前楼层所有的units颜色
 */
- (void)clearAllUnitsColor;

@end

//---------------------------------------------------------------------
/**
 路径规划，查找相关
 */
@interface IDRMapView (RouteAPI)

- (IDRUnit*)getUnitWithName:(NSString*)name floorId:(NSString*)floorId;
/**
 *  根据楼层获取楼层的Units
 *
 *  @param floor 楼层
 *
 *  @return Unit数组
 */
- (NSArray*)getUnitsWithFloor:(NSString*)floorId;

/**
 获取详细IDRfloor结构
 
 @param floorId 楼层id
 
 @return IFRFloor实例
 */
- (IDRFloor*)getFloorWithFloorId:(NSString*)floorId;

/**
 获取路径
 
 @param floorId 楼层id
 @return 路径数组
 */
- (NSArray<IDRLine*>*)getPath:(NSString*)floorId;

/**
 路径搜索
 
 @param p0 起始点
 @param p1 终点
 @param car 是否车行（跨楼层有影响）
 @return 搜索结果
 */
- (IDRRouteResult*)route:(IDRPosition*)p0 to:(IDRPosition*)p1 car:(BOOL)car;
/**
 从近到远排列所有unit
 
 @param pos 位置pos
 @param units 目标units
 @param isCar 是否按照车行搜索路径
 @return 按离pos的路径距离从近到远排列
 */
- (NSArray<IDRUnit*>*)sortWithRouteDistance:(IDRPosition*)pos inTarget:(NSArray<IDRUnit*>*)units car:(BOOL)isCar;
/**
 获取最近的units
 
 @param pos 输入pos
 @param units unit列表
 @param isCar 是否按照车行搜索路径
 @return 最近的unit
 */
- (IDRUnit*)findMostNearUnit:(IDRPosition*)pos inTarget:(NSArray<IDRUnit*>*)units car:(BOOL)isCar;

/**
 获取路径距离
 @param p0 起始点
 @param p1 终点
 @param car 是否车行（跨楼层有影响）
 @return 搜索结果
 */
- (CGFloat)routeDistance:(IDRPosition*)p0 to:(IDRPosition*)p1 car:(BOOL)car;

/**
 获取最近的导航线
 
 @param pos 位置
 @return 导航线
 */
- (IDRLine*)findMostNearLine:(IDRPosition*)pos;

@end

