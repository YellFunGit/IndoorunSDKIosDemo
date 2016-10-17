//
//  FloorListView.h
//  YellFunCars
//
//  Created by Sincere on 15/7/14.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IndoorunMap_Core/IndoorunMap_Core.h>

@class IDRMapView;

@protocol IDRFloorListProtocol <NSObject>

@optional

- (void)didShownFloorList;

- (BOOL)didSelectFloor:(IDRFloor*)floor;

- (BOOL)didISNetWork;

- (void)floorListShownDisabled;

- (BOOL)didIsShow;

@end

@class IDRFloor;

@protocol IDRFloorSelectProtocol <NSObject>

@required

/**
 *  设置定位楼层
 *
 */
- (void)setLocatedFloor:(IDRFloor*)floor;

/**
 *  设置当前楼层
 *
 */
- (void)setCurrentFloor:(IDRFloor*)floor;

@end

@interface IDRFloorListView : UIView<IDRFloorSelectProtocol,UITableViewDataSource,UITableViewDelegate>

- (instancetype)initWithFloors:(NSArray*)floor origionX:(CGFloat)x origionY:(CGFloat)y;

- (void)exchangeFloors:(NSArray*)floors;

- (void)showFloor;

- (void)disMissFloor;

@property (nonatomic, assign) BOOL isShownEnable;
@property (nonatomic, retain) NSArray * floors;
@property (nonatomic, retain) UITableView * table;
@property (nonatomic, retain)UIButton    * button;
@property (nonatomic, weak) IDRMapView *mapView;
@property (nonatomic, assign) BOOL isShown;

@end
