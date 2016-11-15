//
//  IDRWalkInsManager.h
//  YFMapKit
//
//  Created by ky on 16/5/5.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface IDRWalkInsManager : NSObject

@property (nonatomic, assign) BOOL disable;

+ (instancetype)sharedInstance;

- (double*)getDisplacement;

- (void)setupMotionAndMonitor:(CGFloat)northAngle;

- (void)stop;

- (CGFloat)getMagnetism;

- (NSInteger)getStepCount;

- (CGFloat)getWalkDistance;

@end
