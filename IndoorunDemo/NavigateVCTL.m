//
//  NavigateVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/11/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "NavigateVCTL.h"
#import "IDRFloorListView.h"
#import "DemoCommon.h"

typedef void(^SelectPosBlock)(IDRPosition*);
typedef void(^SelectUnitBlock)(IDRUnit*);


@interface NavigateVCTL ()<IDRMapViewDelegate, IDRLocationServerDelegate, IDRNavigationServerDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, copy) SelectUnitBlock selectUnitBlock;
@property (nonatomic, copy) SelectPosBlock selectPosBlock;
@property (nonatomic, retain) IDRPosition *sp;
@property (nonatomic, retain) IDRPosition *ep;
@property (nonatomic, assign) BOOL dynamicNavi;
@property (nonatomic, retain) IDRStartMarker *startMarker;
@property (nonatomic, retain) IDRCarMarker *endMarker;

@end

@implementation NavigateVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self loadMap];
    
    [self locate];
}

- (void)loadMap {
    
    _mapView = [[IDRMapView alloc] init];
    
    [_mapView loadMap:_region floor:_region.defaultFloor];
    
    [self.view addSubview:_mapView];
    
    [_mapView addDefaultFloorListView];
}

- (void)locate {
    
    [[IDRCoreManager locationServer] startServer:_region];
    
    [[IDRCoreManager locationServer] setDelegate:self];
    
    [_mapView addDefaultMapModeBtn];
}

- (void)onNavigate {
    
    UIAlertController *vctl = [UIAlertController alertControllerWithTitle:@"选择导航模式" message:@"" preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *dynamicNavi = [UIAlertAction actionWithTitle:@"动态导航" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        __weak NavigateVCTL *weakself = self;
        
        [weakself onDynamicNavi];
    }];
    
    UIAlertAction *staticNavi = [UIAlertAction actionWithTitle:@"静态导航" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        __weak NavigateVCTL *weakself = self;
        
        [weakself onStaticNavi];
    }];
    
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        
    }];
    
    [vctl addAction:dynamicNavi];
    
    [vctl addAction:staticNavi];
    
    [vctl addAction:cancel];
    
    [self presentViewController:vctl animated:YES completion:nil];
}

- (void)onDynamicNavi {
    
    if (_region.enDyGuide.integerValue == 0) {
        
        [DemoCommon floatedLabelWithText:@"当前地图不支持动态导航"];
        
        return;
    }
    
    _dynamicNavi = YES;
    
    [DemoCommon floatedLabelWithText:@"单击地图选择终点"];
    
    __weak NavigateVCTL *weakself = self;
    
    self.selectPosBlock = ^(IDRPosition* pos) {
        
        [weakself setEp:pos];
    };
}

- (void)onStaticNavi {
    
    _dynamicNavi = NO;
    
    [DemoCommon floatedLabelWithText:@"单击地图选择起点"];
    
    __weak NavigateVCTL *weakself = self;
    
    self.selectPosBlock = ^(IDRPosition* pos) {
        
        [weakself setSp:pos];
    };
}

- (void)setSp:(IDRPosition *)sp {
    
    _sp = sp;
    
    _startMarker = [[IDRStartMarker alloc] initWith:sp];
    
    [_mapView addMarker:_startMarker];
    
    [DemoCommon floatedLabelWithText:@"单击地图选择终点"];
    
    __weak NavigateVCTL *weakself = self;
    
    self.selectPosBlock = ^(IDRPosition* pos) {
        
        [weakself setEp:pos];
    };
}

- (void)setEp:(IDRPosition *)ep {
    
    _ep = ep;
    
    _endMarker = [[IDRCarMarker alloc] initWith:ep];
    
    [_mapView addMarker:_endMarker];
    
    [[IDRCoreManager navigationServer] setDelegate:self];
    
    [[IDRCoreManager navigationServer] setMapView:_mapView];
    
    if (_dynamicNavi) {
        
        [[IDRCoreManager navigationServer] startServer:_region navi:[IDRNaviParm createWith:nil end:ep]];
    }
    else{
        
        [[IDRCoreManager navigationServer] startServer:_region navi:[IDRNaviParm createWith:_sp end:ep]];
    }
    
    self.selectPosBlock = nil;
}

#pragma mark --LocationServer Delegate
- (void)location:(IDRLocationServer*)locationServer didLocationSuccess:(IDRUserLocation*)userLocation {
    
    [_mapView setUserLocation:userLocation];
}

#pragma mark --MapView Delegate
- (BOOL)mapview:(IDRMapView *)mapView onClickUnit:(IDRUnit *)unit {
    
    if (self.selectUnitBlock) {
        
        self.selectUnitBlock(unit);
    }
    
    return YES;
}

#pragma mark --NavigationServer Delegate
- (void)navigationDidFinish:(IDRNavigationServer *)sender {
    
    NSLog(@"抵达目标点，导航结束");
}


@end
