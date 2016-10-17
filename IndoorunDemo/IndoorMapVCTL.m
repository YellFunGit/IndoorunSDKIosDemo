//
//  IndoorMapVCTL.m
//  IndoorunDemo
//
//  Created by ky on 16/7/11.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import "IndoorMapVCTL.h"
#import "GCFloatedLabelView.h"
#import "IDRFloorListView.h"
#import "FunctionSelectVCTL.h"
#import "MyMapMarker.h"

typedef void(^SelectPosBlock)(IDRPosition*);
typedef void(^SelectUnitBlock)(IDRUnit*);

@interface IndoorMapVCTL ()<IDRMapViewDelegate, IDRLocationServerDelegate, IDRNavigationServerDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, copy) SelectPosBlock selectPosBlock;
@property (nonatomic, copy) SelectUnitBlock selectUnitBlock;
@property (nonatomic, retain) IBOutlet UIButton *ibnStopNavigation;
@property (nonatomic, retain) IBOutlet UILabel *ibDebugInfo;
@property (nonatomic, retain) IBOutlet UILabel *ibRegionDetail;
@property (nonatomic, retain) IDRCarMarker *startMarker;
@property (nonatomic, retain) IDRCarMarker *endMarker;
@property (nonatomic, retain) IDRFloorListView *floorListView;
@property (nonatomic, assign) BOOL dynamicNavi;
@property (nonatomic, retain) IDRPosition *sp;
@property (nonatomic, retain) IDRPosition *ep;

@end

@implementation IndoorMapVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self setupObserver];
    
    [self showRegionDetail];
    
    [_ibnStopNavigation setHidden:YES];
    
    [_ibDebugInfo setHidden:YES];
    
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"功能" style:UIBarButtonItemStylePlain target:self action:@selector(onFunctionSelect)];
}

- (void)showRegionDetail {
    
    NSString *name = [NSString stringWithFormat:@"区域名称:%@", _region.name];
    
    NSString *regionId = [NSString stringWithFormat:@"区域ID:%@", _region.Id];
    
    NSString *floorCount = [NSString stringWithFormat:@"楼层总数:%d", (int)_region.floorList.count];
    
    NSString *floorDetail = [[NSString alloc] init];
    
    for (IDRFloor *floor in _region.floorList) {
        
        floorDetail = [floorDetail stringByAppendingString:[NSString stringWithFormat:@"楼层名与ID:%@, %@", floor.title, floor.Id]];
        
        floorDetail = [floorDetail stringByAppendingString:@"\n"];
    }
    
    NSString *endy = _region.enDyGuide.boolValue ? @"支持" : @"不支持";
    
    NSString *enableLocateStr = [NSString stringWithFormat:@"是否支持定位:%@", endy];
    
    NSString *detail = [NSString stringWithFormat:@"%@\n%@\n%@\n%@\n%@\n详细功能请点击右上角-功能按钮", name, regionId, floorCount, floorDetail, enableLocateStr];
    
    [_ibRegionDetail setText:detail];
}

- (void)onLocate {
    
    [[IDRCoreManager locationServer] startServer:_region];
    
    [[IDRCoreManager locationServer] setDelegate:self];
    
    [_mapView addDefaultMapModeBtn];
}

- (void)setupObserver {
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onLoadMap) name:@"onLoadMap" object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onNavigate) name:@"onNavigate" object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onLocate) name:@"onLocate" object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onMapResponse) name:@"onMapResponse" object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onMapMarkerResponse) name:@"onMarkerResponse" object:nil];
}

- (void)onMapResponse {
    
    [self floatedLabelWithText:@"单击地图上的单元，返回poi信息"];
    
    __weak IndoorMapVCTL *weakself = self;
    
    self.selectUnitBlock = ^(IDRUnit* unit) {
        
        [weakself showDetail:unit];
    };
}

- (NSString*)getUnitDetail:(IDRUnit *)unit {
    
    NSString *name = [NSString stringWithFormat:@"名字:%@", unit.name];
    
    IDRPosition *pos = unit.getUnitPos;
    
    NSString *posStr = [NSString stringWithFormat:@"位置:(%d, %d)", (int)pos.x, (int)pos.y];
    
    NSString *typeStr = [NSString stringWithFormat:@"类型:%@", unit.unitType];
    
    NSString *detail = [NSString stringWithFormat:@"%@\n%@\n%@", name, posStr, typeStr];
    
    return detail;
}

- (void)showDetail:(IDRUnit*)unit {
    
    [_ibDebugInfo setHidden:NO];
    
    [_ibDebugInfo setText:[self getUnitDetail:unit]];
}

- (void)onMapMarkerResponse {
    
    IDRPosition *pos = [[IDRPosition alloc] initWithX:300 Y:300 floor:_mapView.currentFloor.Id];
    
    MyMapMarker *marker = [[MyMapMarker alloc] initWithPos:pos];
    
    [_mapView addMarker:marker];
    
    [self floatedLabelWithText:@"单击移除marker"];
}

#pragma mark --IDRLocationServerDelegate

- (void)location:(IDRLocationServer*)locationServer didLocationSuccess:(IDRUserLocation*)userLocation {
    
    [_mapView setUserLocation:userLocation];
    
    [_floorListView setLocatedFloor:[_region getFloorBy:userLocation.pos.floorId]];
}

- (void)location:(IDRLocationServer*)locationServer didLocationFailed:(NSString *)regionId {
    
    [_floorListView setLocatedFloor:nil];
}

//-----------------------------------------------------------
- (void)onLoadMap {
    
    _mapView = [[IDRMapView alloc] init];
    
    _mapView.delegate = self;
    
    [_mapView loadMap:_region floor:_region.defaultFloor];
    
    [self.view addSubview:_mapView];
    
    [self.view sendSubviewToBack:_mapView];
    
    [self initFloorView];
}

- (void)onFunctionSelect {
    
    [_ibRegionDetail setHidden:YES];
    
    FunctionSelectVCTL *vctl = [[FunctionSelectVCTL alloc] init];
    
    [self.navigationController pushViewController:vctl animated:YES];
}

#pragma mark --mapViewDelegate

- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegion*)region floor:(IDRFloor*)floor {
    
    NSLog(@"地图加载完成");
    
    [_floorListView setCurrentFloor:floor];
}

- (void)mapview:(IDRMapView *)mapView onClickMap:(IDRPosition *)pos {
    
    if (self.selectPosBlock) {
        
        self.selectPosBlock(pos);
    }
}

- (BOOL)mapview:(IDRMapView *)mapView onClickUnit:(IDRUnit *)unit {
    
    if (self.selectUnitBlock) {
        
        self.selectUnitBlock(unit);
    }
    
    return YES;
}

- (BOOL)mapView:(IDRMapView *)mapView onClickMarker:(id<IDRMapMarkerProtocal>)marker {
    
    [_mapView removeMarker:marker];
    
    return YES;
}

- (void)navigation:(IDRNavigationServer *)sender didStartSuccess:(NaviServerStartStatus)status naviParm:(IDRNaviParm*)naviParm {
    
    if (status != NaviServerStartStatus_Success) {
        
        [_mapView setNaviState:NO];
        
        return;
    }
    
    [_mapView setNaviState:YES];
    
    [_ibDebugInfo setHidden:!sender.isDynamicNavi];
    
    [_ibnStopNavigation setHidden:NO];
}

- (void)onDynamicNavi {
    
    if (_region.enDyGuide.integerValue == 0) {
        
        [self floatedLabelWithText:@"当前地图不支持动态导航"];
        
        return;
    }
    
    _dynamicNavi = YES;
    
    [self floatedLabelWithText:@"单击地图选择终点"];
    
    __weak IndoorMapVCTL *weakself = self;
    
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

- (void)onStaticNavi {

    _dynamicNavi = NO;
    
    [self floatedLabelWithText:@"单击地图选择起点"];
    
    __weak IndoorMapVCTL *weakself = self;
    
    self.selectPosBlock = ^(IDRPosition* pos) {
        
        [weakself setSp:pos];
    };
}

- (void)setSp:(IDRPosition *)sp {
    
    _sp = sp;
    
    _startMarker = [[IDRCarMarker alloc] initWith:sp];
    
    [_mapView addMarker:_startMarker];
    
    [self floatedLabelWithText:@"单击地图选择终点"];
    
    __weak IndoorMapVCTL *weakself = self;
    
    self.selectPosBlock = ^(IDRPosition* pos) {
        
        [weakself setEp:pos];
    };
}

- (void)onNavigate {
    
    UIAlertController *vctl = [UIAlertController alertControllerWithTitle:@"选择导航模式" message:@"" preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *dynamicNavi = [UIAlertAction actionWithTitle:@"动态导航" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        __weak IndoorMapVCTL *weakself = self;
        
        [weakself onDynamicNavi];
    }];
    
    UIAlertAction *staticNavi = [UIAlertAction actionWithTitle:@"静态导航" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        __weak IndoorMapVCTL *weakself = self;
        
        [weakself onStaticNavi];
    }];
    
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        
    }];
    
    [vctl addAction:dynamicNavi];
    
    [vctl addAction:staticNavi];
    
    [vctl addAction:cancel];
    
    [self presentViewController:vctl animated:YES completion:nil];
}

- (void)onStopNavigation {
    
    [[IDRCoreManager navigationServer] stopServer];
    
    [_mapView removeMarker:_startMarker];
    
    _startMarker = nil;
    
    [_mapView removeMarker:_endMarker];
    
    _endMarker = nil;
    
    [_mapView setNaviState:NO];
    
    [_ibnStopNavigation setHidden:YES];
    
    [_ibDebugInfo setHidden:YES];
}

- (IBAction)onStopNavigationClick:(id)sender {
    
    [self onStopNavigation];
}

- (void)navigation:(IDRNavigationServer *)sender didUpdateSuggestion:(IDRNaviSuggestion *)naviSuggestion {
    
    NSString *suggestion = [[naviSuggestion getNaviStatusText] string];
    
    [_ibDebugInfo setText:suggestion];
}

- (void)navigationDidFinish:(IDRNavigationServer *)sender {
    
    [self onStopNavigation];
    
    [self floatedLabelWithText:@"导航结束"];
}

- (void)initFloorView
{
    NSArray *floors = _region.floorList;
    
    _floorListView = [[IDRFloorListView alloc] initWithFloors:floors origionX:kScreenWidth - 45 origionY:97];
    
    [self.view addSubview:_floorListView];
    
    [_floorListView setMapView:_mapView];
}

- (void)dealloc {
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)floatedLabelWithText:(NSString *)text {
    
    GCFloatedLabelView* labelview = [[GCFloatedLabelView alloc] init];
    
    UIWindow *window = [[[UIApplication sharedApplication] delegate] window];
    
    [window addSubview:labelview];
    
    [labelview show:CGPointMake(kScreenWidth * 0.5, kScreenHeight * 0.5) withTime:2 withText:text];
}

@end
