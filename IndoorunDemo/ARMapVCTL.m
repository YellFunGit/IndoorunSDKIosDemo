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

- (IBAction)addMarker:(id)sender {
    
    _carMarker = [[IDRCarMarker alloc] initWith:[[IDRPosition alloc] initWithX:606 Y:192 floor:@"14557583851000004"]];
    
    [_mapView addMarker:_carMarker];
}

- (IBAction)onChangeTo3dMap:(id)sender {
    
    _mapView.eyeDistanceScale = 0.5;
    
    _mapView.mapDisplayMode = IDRMap_3D;
}

- (IBAction)onChangeTo2dMap:(id)sender {
    
    _mapView.mapDisplayMode = IDRMap_2D;
}

- (IBAction)onChangeToArMap:(id)sender {
    
    _mapView.mapDisplayMode = IDRMap_AR;
}

#pragma mark --mapviewdelegate

- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegionEx *)regionEx {
    
    NSLog(@"加载地图%@成功", regionEx.name);
    
    [_mapView addDefaultFloorListView];
    
    [_mapView changeFloor:regionEx.defaultFloorId];
    
    _locator = [[IDRLocationServer alloc] init];
    
    [IDRMapKitConfig sharedInstance].locate_url = @"http://192.168.0.104:3000/users/locating";
    
    [_locator setDelegate:self];
    
    [_locator startServer:_mapView];
    
    [_locator setUseWalkFilter:YES];
}

- (void)location:(IDRLocationServer *)locationServer didLocationSuccess:(IDRUserLocation *)userLocation {
    
    [_mapView setUserLocation:userLocation];
}



@end
