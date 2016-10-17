//
//  LocateVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/11/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "LocateVCTL.h"
#import "IDRFloorListView.h"

@interface LocateVCTL ()<IDRLocationServerDelegate,IDRMapViewDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, retain) IBOutlet UILabel *ibDebug;
@property (nonatomic, retain) IDRFloorListView *floorListView;

@end

@implementation LocateVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self loadMap];
    
    [self locate];
}

- (void)loadMap {
    
    _mapView = [[IDRMapView alloc] init];
    
    [_mapView loadMap:_region floor:_region.defaultFloor];
    
    [_mapView setDelegate:self];
    
    [self.view addSubview:_mapView];
    
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

- (void)locate {
    
    [[IDRCoreManager locationServer] setDelegate:self];
    
    LocateStartResult result = [[IDRCoreManager locationServer] startServer:_region];
    
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

- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegion *)region floor:(IDRFloor *)floor{
    
    [_floorListView setCurrentFloor:floor];
}

- (void)location:(IDRLocationServer*)locationServer didLocationSuccess:(IDRUserLocation*)userLocation {
    
    [_mapView setUserLocation:userLocation];
    
    //是否显示罗盘
    [_mapView showComposs:YES];
    
    [_ibDebug setText:[NSString stringWithFormat:@"定位成功,当前坐标(%.2f, %.2f)", userLocation.pos.x, userLocation.pos.y]];
}

- (void)location:(IDRLocationServer*)locationServer didLocationFailed:(NSString *)regionId {
    
    [_ibDebug setText:@"定位失败"];
}

@end
