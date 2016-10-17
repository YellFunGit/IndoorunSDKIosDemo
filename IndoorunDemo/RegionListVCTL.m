//
//  RegionListVCTL.m
//  IndoorunDemo
//
//  Created by ky on 16/7/11.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import "RegionListVCTL.h"
#import <IndoorunMap_Core/IndoorunMap_Core.h>
#import "IndoorMapVCTL.h"
#import "RegionDetailVCTL.h"

@interface RegionListVCTL() <UITableViewDelegate, UITableViewDataSource>

@end

@implementation RegionListVCTL

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self.navigationItem setTitle:@"可用区域列表"];
}

- (UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"UITableViewCell"];
    
    if (!cell) {
        
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"UITableViewCell"];
    }
    
    if (indexPath.row >= _regionsList.count) {
        
        [cell.textLabel setText:@""];
        
        return cell;
    }
    
    [cell.textLabel setText:_regionsList[indexPath.row].name];
    
    return cell;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return _regionsList.count;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    if (indexPath.row >= _regionsList.count) {
        
        return;
    }
    
    RegionDetailVCTL *vctl = [[RegionDetailVCTL alloc] init];
    
    vctl.region = _regionsList[indexPath.row];
    
    [self.navigationController pushViewController:vctl animated:YES];
}

@end
