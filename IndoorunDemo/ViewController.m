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
    
    [[IDRCoreManager sharedInstance] initWith:@"yf645309714" appkey:@"Y4rSCI27NF3t7Ru76KNq60PQIjgP06L4"];
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
