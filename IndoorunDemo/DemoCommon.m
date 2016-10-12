//
//  DemoCommon.m
//  IndoorunDemo
//
//  Created by ky on 10/11/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "DemoCommon.h"
#import "GCFloatedLabelView.h"
#import <IndoorunMap_Core/IndoorunMap_Core.h>

@interface DemoCommon ()

@end

@implementation DemoCommon

+ (void)floatedLabelWithText:(NSString *)text {
    
    GCFloatedLabelView* labelview = [[GCFloatedLabelView alloc] init];
    
    UIWindow *window = [[[UIApplication sharedApplication] delegate] window];
    
    [window addSubview:labelview];
    
    [labelview show:CGPointMake(kScreenWidth * 0.5, kScreenHeight * 0.5) withTime:2 withText:text];
}

@end
