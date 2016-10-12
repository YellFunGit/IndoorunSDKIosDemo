//
//  StaticNavigationVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/11/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "StaticNavigationVCTL.h"

@interface StaticNavigationVCTL ()<IDRMapViewDelegate, IDRNavigationServerDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, retain) IDRPosition *sp;
@property (nonatomic, retain) IDRPosition *ep;
@property (nonatomic, retain) IDRStartMarker *startMarker;
@property (nonatomic, retain) IDRCarMarker *carMarker;
@property (nonatomic, retain) IBOutlet UILabel *ibDebug;

@end

@implementation StaticNavigationVCTL

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
    
    [_mapView addDefaultFloorListView];
}

- (IBAction)onStopNavigation:(id)sender {
    
    [[IDRCoreManager navigationServer] stopServer];
    
    [_mapView removeMarker:_startMarker];
    
    _startMarker = nil;
    
    [_mapView removeMarker:_carMarker];
    
    _carMarker = nil;
    
    [_mapView setNaviState:NO];
    
    [_ibDebug setText:@"导航结束"];
}

#pragma mark --MapView Delegate
- (void)mapview:(IDRMapView *)mapView onClickMap:(IDRPosition *)pos {
    
    if (!_sp) {
        
        _sp = pos;
        
        _startMarker = [[IDRStartMarker alloc] initWith:pos];
        
        [_mapView addMarker:_startMarker];
        
        return;
    }
    
    if (!_ep) {
        
        _ep = pos;
        
        _carMarker = [[IDRCarMarker alloc] initWith:pos];
        
        [_mapView addMarker:_carMarker];
        
        [[IDRCoreManager navigationServer] setDelegate:self];
        
        //设置地图，不然不会显示导航线
        [[IDRCoreManager navigationServer] setMapView:_mapView];
        
        [[IDRCoreManager navigationServer] startServer:_region navi:[IDRNaviParm createWith:_sp end:_ep]];
    }
}

#pragma mark --NavigationServer Delegate

- (void)navigation:(IDRNavigationServer *)sender didStartSuccess:(NaviServerStartStatus)status naviParm:(IDRNaviParm *)naviParm {
    
    if (status == NaviServerStartStatus_Success) {
        
        [_ibDebug setText:@"导航启动成功"];
    }
    
    if (status == NaviServerStartStatus_TooNear) {
        
        [_ibDebug setText:@"地点终点距离太近，导航启动失败"];
    }
    
    if (status == NaviServerStartStatus_PassNotFind) {
        
        [_ibDebug setText:@"楼层之间没有连通性，导航启动失败"];
    }
}

@end
