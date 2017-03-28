//
//  MultiplayerViewController.m
//  IndoorunDemo
//
//  Created by ky on 27/03/2017.
//  Copyright © 2017 yellfun. All rights reserved.
//

#import "MultiplayerViewController.h"
#import <IndoorunMap_Core/IndoorunMap_Core.h>
#include "UploadWithMessageView.h"

@interface MultiplayerViewController ()<IDRLocationServerDelegate,IDRMapViewDelegate,IDRMultiLocationServerDelegate,UploadWithMessageViewDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, retain) IBOutlet UILabel *ibDebug;
@property (nonatomic) IDRLocationServer *server;
@property (nonatomic) IDRMultiLocationServer *multiLocateServer;
@property (nonatomic) IDRUserPointMarker *userMarker;

@end

@implementation MultiplayerViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self loadMap];
}

- (void)loadMap {
    
    _mapView = [[IDRMapView alloc] init];
    
    [_mapView loadMap:_region];
    
    [_mapView setDelegate:self];
    
    [self.view addSubview:_mapView];
    
    [self.view sendSubviewToBack:_mapView];
    
    NSLog(@"phoneuuid---%@", PhoneUUID);
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
    
    [_mapView setShowPlotingScale:YES];
    
    [self locate];
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

- (IBAction)onTestMulitilocate:(id)sender {
    
    UploadWithMessageView *view = (UploadWithMessageView *)[[self class] viewByClassName:@"UploadWithMessageView" inNib:@"UploadWithMessageView"];
    
    view.frame = self.view.bounds;
    
    view.delegate = self;
    
    [self.view addSubview:view];
}

#pragma IDRMultiLocationServerDelegate

- (void)onMultilocateSuccess:(IDRMultiLocationServer*)sender success:(NSArray<IDRMultiLocationInfo*>*)locationInfos {
    
    for (IDRMultiLocationInfo *info in locationInfos) {
        
        NSLog(@"对方位置%.2f, %.2f", info.pos.x, info.pos.y);
    }
}

- (void)UploadWithMessageView:(id)sender ok:(BOOL)ok message:(NSString*)message {
    
    NSArray *uuids = [message componentsSeparatedByString:@";"];
    
    if (!_multiLocateServer) {
        
        _multiLocateServer = [[IDRMultiLocationServer alloc] init];
        
        _multiLocateServer.delegate = self;
    }
    
    [_multiLocateServer startServer:uuids];
}

+ (UIView *)viewByClassName:(NSString *)className inNib:(NSString *)nibName {
    
    NSArray *nib = [[NSBundle mainBundle] loadNibNamed:nibName owner:self options:nil];
    
    Class cellClass = NSClassFromString(className);
    
    for (id oneObject in nib) {
        
        if ([oneObject isMemberOfClass:cellClass]) {
            
            return oneObject;
        }
    }
    
    return nil;
}


@end
