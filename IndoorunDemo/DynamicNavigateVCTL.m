//
//  DynamicNavigateVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/12/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "DynamicNavigateVCTL.h"

@interface DynamicNavigateVCTL ()<IDRMapViewDelegate, IDRNavigationServerDelegate, IDRLocationServerDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, retain) IDRPosition *ep;
@property (nonatomic, retain) IDRCarMarker *carMarker;
@property (nonatomic, retain) IBOutlet UILabel *ibDebug;
@property (nonatomic, strong) IDRLocationServer *locator;
@property (nonatomic, strong) IDRNavigationServer *navigator;

@end

@implementation DynamicNavigateVCTL

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
    
    [_mapView addDefaultMapModeBtn];
}

- (void)locate {
    
    if (!_locator) {
        
        _locator = [[IDRLocationServer alloc] init];
    }
    
    [_locator startServer:_mapView];
    
    [_locator setDelegate:self];
}

- (IBAction)onChangeTo3dMap:(id)sender {
    
    _mapView.mapDisplayMode = IDRMap_3D;
}

- (IBAction)onChangeTo2dMap:(id)sender {
    
    _mapView.mapDisplayMode = IDRMap_2D;
}

- (IBAction)onChangeToArMap:(id)sender {
    
    _mapView.mapDisplayMode = IDRMap_AR;
}

- (IBAction)onStopNavigation:(id)sender {
    
    [_navigator stopServer];
    
    [_mapView removeMarker:_carMarker];
    
    _carMarker = nil;
    
    [_mapView setNaviState:NO];
    
    [_ibDebug setText:@"导航结束"];
}

#pragma mark --MapView Delegate
- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegionEx *)regionEx {
    
    NSLog(@"加载地图%@成功", regionEx.name);
    
    [_mapView addDefaultFloorListView];
    
    [_mapView changeFloor:regionEx.defaultFloorId];
    
    [self locate];
}

- (void)mapview:(IDRMapView *)mapView onClickMap:(IDRPosition *)pos {
    
    if (!_ep) {
        
        _ep = pos;
        
        _carMarker = [[IDRCarMarker alloc] initWith:pos];
        
        [_mapView addMarker:_carMarker];
        
        if (!_navigator) {
            
            _navigator = [IDRNavigationServer instance];
        }
        
        [_navigator setDelegate:self];
        
        //动态导航需设置定位器
        [_navigator setLocater:_locator];
        
        [_mapView setBirdLookMargin:200 top:200 right:200 bottom:200];
        //动态导航，起点设置为nil
        [_navigator startServer:_mapView navi:[IDRNaviParm createWith:nil end:_ep car:NO]];
    }
}

#pragma mark --LocationServer Delegate 
- (void)location:(IDRLocationServer *)locationServer didLocationSuccess:(IDRUserLocation *)userLocation {
    
    [_mapView setUserLocation:userLocation];
}

#pragma mark --NavigationServer Delegate
- (void)navigation:(IDRNavigationServer *)sender didStartSuccess:(NaviServerStartStatus)status naviParm:(IDRNaviParm *)naviParm {
    
    if (status == NaviServerStartStatus_Success) {
        
        [_ibDebug setText:@"导航启动成功"];
    }
    
    if (status == NaviServerStartStatus_LocationServerFailed) {
        
        [_ibDebug setText:@"定位失败，动态导航启动失败"];
    }
    
    if (status == NaviServerStartStatus_TooNear) {
        
        [_ibDebug setText:@"地点终点距离太近，动态导航启动失败"];
    }
    
    if (status == NaviServerStartStatus_PassNotFind) {
        
        [_ibDebug setText:@"楼层之间没有连通性，动态导航启动失败"];
    }
    
    [_mapView birdLook];
}

- (void)navigation:(IDRNavigationServer *)sender didUpdateSuggestion:(IDRNaviSuggestion *)naviSuggestion {
    
    [_ibDebug setAttributedText:naviSuggestion.getNaviStatusText];
}

- (void)navigationDidFinish:(IDRNavigationServer *)sender {
    
    [_ibDebug setText:@"导航完毕"];
}

@end
