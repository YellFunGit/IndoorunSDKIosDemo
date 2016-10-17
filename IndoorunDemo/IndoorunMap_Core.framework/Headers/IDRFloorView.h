//
//  FloorListView.h
//  YellFunCars
//
//  Created by Sincere on 15/7/14.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDRRegion.h"
#import "IDRMapView.h"
#import "IDRFloor.h"

@class IDRMapView;

@interface IDRFloorView : UIView<UITableViewDataSource,UITableViewDelegate>

- (instancetype)initWithFloors:(NSArray*)floor origionX:(CGFloat)x origionY:(CGFloat)y;

@property (nonatomic, retain) NSArray *floors;

@property (nonatomic, weak) IDRMapView *mapView;

@property (nonatomic, retain) IDRFloor *currentFloor;

@property (nonatomic, retain) IDRFloor *locatedFloor;

@end
