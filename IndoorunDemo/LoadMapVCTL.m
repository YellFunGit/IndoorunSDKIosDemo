//
//  LoadMapVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/11/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "LoadMapVCTL.h"
#import "IDRFloorListView.h"

@interface LoadMapVCTL ()<IDRMapViewDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, retain) IDRFloorListView *floorListView;


@end

@implementation LoadMapVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self loadMap];
}

- (void)loadMap {
    
    _mapView = [[IDRMapView alloc] init];
    
    [_mapView loadMap:_region floor:_region.defaultFloor];
    
    _mapView.delegate = self;
    
    [self.view addSubview:_mapView];
    
//    [_mapView addDefaultFloorListView];
    
    [self initFloorView];
}

- (void)initFloorView
{
    NSArray *floors = _region.floorList;
    
    _floorListView = [[IDRFloorListView alloc] initWithFloors:floors origionX:kScreenWidth - 45 origionY:97];
    
    [self.view addSubview:_floorListView];
    
    [_floorListView setMapView:_mapView];
}

#pragma mark --mapviewdelegate

- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegion *)region floor:(IDRFloor *)floor {
    
    NSLog(@"加载地图%@:%@成功", region.name, floor.title);
    [_floorListView setCurrentFloor:floor];

}

@end
