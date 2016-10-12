//
//  IDRCarInsManager.h
//  IndoorunMap_Core
//
//  Created by ky on 16/7/29.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface IDRCarInsManager : NSObject

@property (nonatomic, assign) BOOL disable;

+ (instancetype)sharedInstance;

- (double*)getDisplacement;

- (BOOL)isValueValid;

- (void)setupMotionAndMonitor;

- (void)stop;

@end
