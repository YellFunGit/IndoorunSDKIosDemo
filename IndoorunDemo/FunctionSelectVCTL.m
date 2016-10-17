//
//  FunctionSelectVCTL.m
//  IndoorunDemo
//
//  Created by ky on 10/8/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "FunctionSelectVCTL.h"

typedef NS_ENUM(NSInteger, FunctionType) {
    
    onLoadMap,//加载地图
    onLocate,//定位
    onMapResponse,//地图响应
    onNavigate,//导航
    onMarkerResponse,//地图marker响应
    FunctionType_Max
};


@interface FunctionSelectVCTL ()<UITableViewDelegate, UITableViewDataSource>

@end

@implementation FunctionSelectVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
}

- (NSString*)getTitle:(FunctionType)type {
    
    switch (type) {
        case onLoadMap:
            return @"加载地图";
        case onLocate:
            return @"定位";
        case onMapResponse:
            return @"地图响应";
        case onNavigate:
            return @"导航";
        case onMarkerResponse:
            return @"地图marker响应";
            
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

- (NSString*)getNotif:(FunctionType)type {
    
    switch (type) {
        case onLoadMap:
            return @"onLoadMap";
        case onLocate:
            return @"onLocate";
        case onMapResponse:
            return @"onMapResponse";
        case onNavigate:
            return @"onNavigate";
        case onMarkerResponse:
            return @"onMarkerResponse";
            
        default:
            return @"";
    }
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    
    [self.navigationController popViewControllerAnimated:YES];
    
    NSString *notif = [self getNotif:indexPath.row];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:notif object:nil];
}

@end
