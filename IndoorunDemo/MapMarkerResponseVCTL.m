//
//  MapMarkerResponseVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/12/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "MapMarkerResponseVCTL.h"
#import "MyMapMarker.h"

@interface MapMarkerResponseVCTL ()<IDRMapViewDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, retain) IBOutlet UILabel *ibDebug;

@end

@implementation MapMarkerResponseVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self loadMap];
}

- (void)loadMap {
    
    _mapView = [[IDRMapView alloc] init];
    
    [_mapView loadMap:_region];
    
    _mapView.delegate = self;
    
    [self.view addSubview:_mapView];
    
    [self.view sendSubviewToBack:_mapView];
    
    [_mapView addDefaultFloorListView];
    
    [_mapView addDefaultMapModeBtn];
}

#pragma mark --MapView Delegate
- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegionEx *)regionEx {
    
    NSLog(@"加载地图%@成功", regionEx.name);
    
    [_mapView addDefaultFloorListView];
    
    [_mapView changeFloor:regionEx.defaultFloorId];
}

- (void)mapview:(IDRMapView *)mapView onClickMap:(IDRPosition *)pos {
    
    MyMapMarker *marker = [[MyMapMarker alloc] initWithPos:pos];
    
    [_mapView addMarker:marker];
}

- (BOOL)mapView:(IDRMapView *)mapView onClickMarker:(id<IDRMapMarkerProtocal>)marker {
    
    [_mapView removeMarker:marker];
    
    return YES;
}

- (BOOL)mapView:(IDRMapView *)mapView onLongPressMarker:(id<IDRMapMarkerProtocal>)marker {
    
    [_mapView removeMarker:marker];
    
    return YES;
}

@end
