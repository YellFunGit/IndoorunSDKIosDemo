//
//  IDRLocationParm.h
//  YFMapKit
//
//  Created by binghuang on 16/1/26.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDRPosition;
@class CLHeading;

/**
 定位结果
 */
@interface IDRUserLocation : NSObject

/**
 坐标
 */
@property (nonatomic, retain) IDRPosition *pos;

/**
 区域id
 */
@property (nonatomic, copy) NSString *regionId;

/**
 设备偏北角
 */
@property (nonatomic, retain) CLHeading *heading;

@end
