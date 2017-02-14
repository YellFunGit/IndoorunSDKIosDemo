//
//  LocateVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/11/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "LocateVCTL.h"

@interface LocateVCTL ()<IDRLocationServerDelegate,IDRMapViewDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, retain) IBOutlet UILabel *ibDebug;
@property (nonatomic) IDRLocationServer *server;

@end

@implementation LocateVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self loadMap];
}

- (void)loadMap {
    
    _mapView = [[IDRMapView alloc] init];
    
    [_mapView loadMap:_region];
    
    [_mapView setDelegate:self];
    
    [self.view addSubview:_mapView];
}

- (void)locate {
    
    _server = [[IDRLocationServer alloc] init];
    
    _server.delegate = self;

    LocateStartResult result = [_server startServer:_mapView];
    
    if (result == LocateStart_bluetoothDisable) {
        
        [_ibDebug setText:@"定位开始失败,蓝牙服务异常"];
    }
    
    if (result == LocateStart_locationAvailable) {
        
        [_ibDebug setText:@"定位开始失败,定位服务异常"];
    }
    
    if (result == LocateStart_regionDisable) {
        
        [_ibDebug setText:@"定位开始失败,当前区域不支持蓝牙定位"];
    }
}

#pragma mark --LocationServer Delegate
- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegionEx *)regionEx {
    
    NSLog(@"加载地图%@成功", regionEx.name);
    
    [_mapView addDefaultMapModeBtn];
    
    [_mapView addDefaultFloorListView];
    
    [_mapView changeFloor:regionEx.defaultFloorId];
    
    [self locate];
}

- (void)mapViewFinishChangeFloor:(IDRMapView *)mapView floor:(IDRFloor *)floor {
    
    
}

- (void)location:(IDRLocationServer*)locationServer didLocationSuccess:(IDRUserLocation*)userLocation {
    
    [_mapView setUserLocation:userLocation];
    
    [_mapView setMapMode:IDRMapMode_ModeFollowing];
    
    //是否显示罗盘
    [_mapView showComposs:YES];
    
    [_ibDebug setText:[NSString stringWithFormat:@"定位成功,当前坐标(%.2f, %.2f)", userLocation.pos.x, userLocation.pos.y]];
}

- (void)location:(IDRLocationServer*)locationServer didLocationFailed:(NSString *)regionId {
    
    [_ibDebug setText:@"定位失败"];
}

@end
