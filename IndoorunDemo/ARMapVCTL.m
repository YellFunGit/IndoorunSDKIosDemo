//
//  ARMapVCTL.m
//  IndoorunDemo
//
//  Created by ky on 12/01/2017.
//  Copyright © 2017 yellfun. All rights reserved.
//

#import "ARMapVCTL.h"
#import "MyMapMarker.h"

@interface ARMapVCTL ()<IDRMapViewDelegate, IDRLocationServerDelegate, IDRNavigationServerDelegate>

@property (nonatomic) IDRMapView *mapView;
@property (nonatomic) IDRLocationServer *locator;
@property (nonatomic, retain) IDRPosition *ep;
@property (nonatomic, retain) IDRCarMarker *carMarker;
@property (nonatomic, strong) IDRNavigationServer *navigator;


@end

@implementation ARMapVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
}

- (void)loadMap {
    
    self.view.autoresizingMask = UIViewAutoresizingNone;
    
    _mapView = [[IDRMapView alloc] initWithFrame:self.view.bounds];
    
    _mapView.delegate = self;
    
    [_mapView loadMap:_region];
    
    [self.view addSubview:_mapView];
    
    [self.view sendSubviewToBack:_mapView];
}

- (void)viewDidAppear:(BOOL)animated {
    
    [super viewDidAppear:animated];
    
    [self loadMap];
}

- (IBAction)onChangeMap:(id)sender {
    
    [_mapView setAr3DMap:!_mapView.ar3DMap];
}

#pragma mark --mapviewdelegate

- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegionEx *)regionEx {
    
    NSLog(@"加载地图%@成功", regionEx.name);
    
    [_mapView addDefaultFloorListView];
    
    [_mapView changeFloor:regionEx.defaultFloorId];
    
    _locator = [[IDRLocationServer alloc] init];
    
    [_locator setDelegate:self];
    
    [_locator startServer:_mapView];
    
    [_locator setUseWalkFilter:YES];
}

- (void)location:(IDRLocationServer *)locationServer didLocationSuccess:(IDRUserLocation *)userLocation {
    
    [_mapView setUserLocation:userLocation];
}

@end
