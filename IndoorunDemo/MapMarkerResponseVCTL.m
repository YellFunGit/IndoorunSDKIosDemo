//
//  MapMarkerResponseVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/12/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "MapMarkerResponseVCTL.h"
#import "MyMapMarker.h"
#import "IDRFloorListView.h"

@interface MapMarkerResponseVCTL ()<IDRMapViewDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, retain) IBOutlet UILabel *ibDebug;
@property (nonatomic, retain) IDRFloorListView *floorListView;

@end

@implementation MapMarkerResponseVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self loadMap];
}

- (void)loadMap {
    
    _mapView = [[IDRMapView alloc] init];
    
    [_mapView loadMap:_region floor:_region.defaultFloor];
    
    _mapView.delegate = self;
    
    [self.view addSubview:_mapView];
    
    [self.view sendSubviewToBack:_mapView];
    
//    [_mapView addDefaultFloorListView];
    
    [self initFloorView];
    
    [_mapView addDefaultMapModeBtn];
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
