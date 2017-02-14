//
//  IDRWalkInsManager.h
//  YFMapKit
//
//  Created by ky on 16/5/5.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>

@interface IDRWalkInsManager : NSObject

@property (nonatomic, assign) BOOL disable;

@property (nonatomic, assign) CMQuaternion quaternion;

+ (instancetype)sharedInstance;

- (double*)getDisplacement;

- (void)setupMotionAndMonitor:(CGFloat)northAngle;

- (void)stop;

- (CGFloat)getMagnetism;

@end
