//
//  Calculate.h
//  YFTools
//
//  Created by Sincere on 15/9/6.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IDRRegion.h"
#import "IDRFloor.h"
#import "IDRUnit.h"
#import "IDRPath.h"
#import "IDRLine.h"
#import "IDRPosition.h"

@interface IDRCalculate : NSObject

/**
 *  选择点
 *
 *  @param tapPoint 点击点
 *  @param points   点数组
 */
+ (IDRPosition*)selectPointsWithPoint:(IDRPosition*)tapPoint
                              points:(NSArray*)points;

+ (float)getPointDistanceWithPointA:(IDRPosition*)pointA
                             PointB:(IDRPosition*)pointB;

+ (float)getLineDistanceWithPoint:(IDRPosition*)point
                             line:(IDRLine*)line;

@end
