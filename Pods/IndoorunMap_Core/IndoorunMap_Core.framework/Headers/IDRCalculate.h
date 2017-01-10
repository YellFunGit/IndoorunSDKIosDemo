//
//  Calculate.h
//  YFTools
//
//  Created by Sincere on 15/9/6.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDRDataDefine.h"


@interface IDRCalculate : NSObject

/**
 *  点到点距离
 *
 *  @param pointA A点
 *  @param pointB B点
 *
 *  @return distance 距离
 */
+ (float)getPointDistanceWithPointA:(IDRPosition*)pointA PointB:(IDRPosition*)pointB;

/**
 *  点到线的距离
 *
 *  @param point 点
 *  @param line  线
 *
 *  @return 线
 */
+ (float)getLineDistanceWithPoint:(IDRPosition*)point line:(IDRLine*)line;

@end
