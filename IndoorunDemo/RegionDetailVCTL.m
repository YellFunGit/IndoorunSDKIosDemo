//
//  RegionDetailVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/11/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "RegionDetailVCTL.h"
#import "LoadMapVCTL.h"
#import "LocateVCTL.h"
#import "StaticNavigationVCTL.h"
#import "DynamicNavigateVCTL.h"
#import "MapResponseVCTL.h"
#import "MapMarkerResponseVCTL.h"
#import "MapUnitResponseVCTL.h"
#import "ARMapVCTL.h"

typedef NS_ENUM(NSInteger, FunctionType) {
    
    onLoadMap,//加载地图
    
    onMapResponse,//地图响应
    
    onMapUnitResponse,//地图unit响应
    
    onMarkerResponse,//地图marker响应
    
    onLocate,//定位
    
    onStaticNavigate,//静态导航
    
    onDynamicNavigate,//动态导航
    
    onAR,//AR导航
    
    FunctionType_Max
};


@interface RegionDetailVCTL ()<UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, retain) IBOutlet UILabel *ibRegionDetail;

@end

@implementation RegionDetailVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self showRegionDetail];
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
    
    NSString *beaconUUID = [NSString stringWithFormat:@"服务器UUID:%@", _region.beaconUUID];
    
    NSString *detail = [NSString stringWithFormat:@"%@\n%@\n%@\n%@\n%@\n\%@\n详细功能请点击点击下面列表", name, regionId, floorCount, floorDetail, enableLocateStr, beaconUUID];
    
    [_ibRegionDetail setText:detail];
}

- (NSString*)getTitle:(FunctionType)type {
    
    switch (type) {
        case onLoadMap:
            return @"加载地图";
        case onLocate:
            return @"定位";
        case onMarkerResponse:
            return @"地图marker响应";
        case onMapResponse:
            return @"地图响应";
        case onMapUnitResponse:
            return @"地图unit响应";
        case onStaticNavigate:
            return @"静态导航";
        case onDynamicNavigate:
            return @"动态导航";
        case onAR:
            return @"AR模式切换";
        
        default:
            return @"";
    }
}

#pragma mark --tableviewdelegate
- (UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"UITableViewCell"];
    
    NSString *title = [self getTitle:indexPath.row];
    
    [cell.textLabel setText:title];
    
    return cell;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return FunctionType_Max;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    
    if (indexPath.row == onLoadMap) {
        
        LoadMapVCTL *vctl = [[LoadMapVCTL alloc] init];
        
        vctl.region = _region;
        
        [self.navigationController pushViewController:vctl animated:YES];
    }
    
    if (indexPath.row == onAR) {
        
        ARMapVCTL *vctl = [[ARMapVCTL alloc] init];
        
        vctl.region = _region;
        
        [self.navigationController pushViewController:vctl animated:YES];
    }
    
    if (indexPath.row == onLocate) {
        
        LocateVCTL *vctl = [[LocateVCTL alloc] init];
        
        vctl.region = _region;
        
        [self.navigationController pushViewController:vctl animated:YES];
    }
    
    if (indexPath.row == onMapResponse) {
        
        MapResponseVCTL *vctl = [[MapResponseVCTL alloc] init];
        
        vctl.region = _region;
        
        [self.navigationController pushViewController:vctl animated:YES];
    }
    
    if (indexPath.row == onMapUnitResponse) {
        
        MapUnitResponseVCTL *vctl = [[MapUnitResponseVCTL alloc] init];
        
        vctl.region = _region;
        
        [self.navigationController pushViewController:vctl animated:YES];
    }
    
    if (indexPath.row == onMarkerResponse) {
        
        MapMarkerResponseVCTL *vctl = [[MapMarkerResponseVCTL alloc] init];
        
        vctl.region = _region;
        
        [self.navigationController pushViewController:vctl animated:YES];
    }
    
    if (indexPath.row == onStaticNavigate) {
        
        StaticNavigationVCTL *vctl = [[StaticNavigationVCTL alloc] init];
        
        vctl.region = _region;
        
        [self.navigationController pushViewController:vctl animated:YES];
    }
    
    if (indexPath.row == onDynamicNavigate) {
        
        DynamicNavigateVCTL *vctl = [[DynamicNavigateVCTL alloc] init];
        
        vctl.region = _region;
        
        [self.navigationController pushViewController:vctl animated:YES];
    }
}

@end
