//
//  MapResponseVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/11/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "MapResponseVCTL.h"
#import "IDRFloorListView.h"

@interface MapResponseVCTL ()<IDRMapViewDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, retain) IBOutlet UILabel *ibDebug;
@property (nonatomic, retain) IDRFloorListView *floorListView;

@end

@implementation MapResponseVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self loadMap];
    
    [self.view bringSubviewToFront:_ibDebug];
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

#pragma mark --MapView Delegate

- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegion *)region floor:(IDRFloor *)floor{
    
    [_floorListView setCurrentFloor:floor];
}

- (void)mapview:(IDRMapView *)mapView onClickMap:(IDRPosition *)pos {
    
    NSString *text = [NSString stringWithFormat:@"点击地图坐标为(%.2f, %.2f)", pos.x, pos.y];
    
    [_ibDebug setText:text];
}

- (void)mapview:(IDRMapView *)mapView onLongPressMap:(IDRPosition *)pos {
    
    NSString *text = [NSString stringWithFormat:@"长按地图坐标为(%.2f, %.2f)", pos.x, pos.y];
    
    [_ibDebug setText:text];
}



@end
