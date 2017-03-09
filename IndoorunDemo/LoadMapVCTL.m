//
//  LoadMapVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/11/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "LoadMapVCTL.h"
#import "MyMapMarker.h"
#import "IDRZoomView.h"

@interface LoadMapVCTL ()<IDRMapViewDelegate, IDRLocationServerDelegate>

@property (nonatomic) IDRLocationServer *server;
@property (nonatomic) IDRMapView *mapView;

@property (nonatomic) BOOL show;

@end

@implementation LoadMapVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self loadMap];
}

- (void)loadMap {
    
    _mapView = [[IDRMapView alloc] initWithFrame:self.view.bounds];
    
    _mapView.delegate = self;
    
    [_mapView loadMap:_region];
    
    [self.view addSubview:_mapView];
    
    CGRect r = CGRectMake([UIScreen mainScreen].bounds.size.width-44, [UIScreen mainScreen].bounds.size.height - 165 , 35, 70);
    
    IDRZoomView *view = [[IDRZoomView alloc] initWithFrame:r];
    
    [self.view addSubview:view];
}

#pragma mark --mapviewdelegate

- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegionEx *)regionEx {
    
    NSLog(@"加载地图%@成功", regionEx.name);
    
    [_mapView addDefaultFloorListView];
    
    [_mapView changeFloor:regionEx.defaultFloorId];
    
    [_mapView setShowPlotingScale:YES];
    
    IDRPosition *p = [[IDRPosition alloc] initWithX:0 Y:0 floor:@"14557583851000004"];
    
    IDRCarMarker *carMarker = [[IDRCarMarker alloc] initWith:p];
    
    [_mapView centerPos:p];
}

- (BOOL)mapview:(IDRMapView *)mapView onClickUnit:(IDRUnit *)unit {
    
    IDRPosition *p = unit.getUnitPos;
    
    MyMapMarker *marker = [[MyMapMarker alloc] initWithPos:p];
    
    [_mapView addMarker:marker];
    
    [_mapView centerPos:p];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        
        [_mapView zoom:1.2 anchor:p.point anim:YES];
    });
    
    return YES;
}

@end
