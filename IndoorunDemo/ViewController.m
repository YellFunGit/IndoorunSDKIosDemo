//
//  ViewController.m
//  IndoorunDemo
//
//  Created by ky on 16/7/11.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import "ViewController.h"
#import "RegionListVCTL.h"
#import "GCFloatedLabelView.h"
#import <IndoorunMap_Core/IndoorunMap_Core.h>

@interface ViewController ()<IDRCoreManagerDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [[IDRCoreManager sharedInstance] setDelegate:self];
}

- (IBAction)onEnterClick:(id)sender {
    
    [[IDRMapKitConfig sharedInstance] setFormalServer:NO];//使用测试服
    
    [[IDRMapKitConfig sharedInstance] setAppBoundleId:@"com.Yellfun.Cars"];
    
    [[IDRCoreManager sharedInstance] initWith:@"2b497ada3b2711e4b60500163e0e2e6b" appkey:@"3d256f0e0ebd51f6176358abd62c1ae0"];
}

- (void)idrCoreManager:(IDRCoreManager*)sender didServerStartSuccess:(BOOL)success regions:(NSArray*)regions {
    
    if (!success) {
        
        NSLog(@"Indoorun服务启动失败");
        
        return;
    }
    
    RegionListVCTL *vctl = [[RegionListVCTL alloc] init];
    
    vctl.regionsList = regions;
    
    [self.navigationController pushViewController:vctl animated:YES];
}

@end
