//
//  MapUnitResponseVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/12/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "MapUnitResponseVCTL.h"
#import "IDRFloorListView.h"

@interface MapUnitResponseVCTL ()<IDRMapViewDelegate>

@property (nonatomic, retain) IDRMapView *mapView;
@property (nonatomic, retain) IBOutlet UILabel *ibDebug;
@property (nonatomic, retain) IDRFloorListView *floorListView;


@end

@implementation MapUnitResponseVCTL

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

- (NSString*)getUnitDetail:(IDRUnit *)unit {
    
    NSString *name = [NSString stringWithFormat:@"名字:%@", unit.name];
    
    IDRPosition *pos = unit.getUnitPos;
    
    NSString *posStr = [NSString stringWithFormat:@"位置:(%d, %d)", (int)pos.x, (int)pos.y];
    
    NSString *typeStr = [NSString stringWithFormat:@"类型:%@", unit.unitType];
    
    NSString *detail = [NSString stringWithFormat:@"%@\n%@\n%@", name, posStr, typeStr];
    
    return detail;
}

#pragma mark --MapView Delegate

- (void)mapViewDidFinishLoading:(IDRMapView *)mapView region:(IDRRegion *)region floor:(IDRFloor *)floor
{
    [_floorListView setCurrentFloor:floor];
}

- (BOOL)mapview:(IDRMapView *)mapView onClickUnit:(IDRUnit *)unit {
    
    NSString *text = [self getUnitDetail:unit];
    
    [_ibDebug setText:text];
    
    return YES;
}

- (BOOL)mapview:(IDRMapView *)mapView onLongPressUnit:(IDRUnit *)unit {
    
    NSString *text = [self getUnitDetail:unit];
    
    [_ibDebug setText:text];
    
    return YES;
}

@end
