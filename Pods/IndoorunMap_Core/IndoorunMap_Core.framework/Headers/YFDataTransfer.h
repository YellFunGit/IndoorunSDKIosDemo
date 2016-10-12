//
//  YFDataTransfer.h
//  YellfunMapKit
//
//  Created by Sincere on 15/8/3.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IDRRegion.h"
#import "IDRFloor.h"
#import "IDRUnit.h"
#import "IDRPath.h"
#import "IDRPosition.h"
#import "YFLengthPre.h"
#import "IDRRegionData.h"
#import "IDRPassData.h"
#import "IDRPassUnit.h"

/**
 *  数据类型转化
 **/
@interface YFDataTransfer : NSObject

/**
 *  字典数据转YFregionData
 *
 *  @param regionDict NSDictionary
 *
 *  @return IDRRegionData
 */
+ (IDRRegionData *)transferDataToRegionData:(id)dataDict;

/**
 *  字典数据转YFregion
 *
 *  @param regionDict NSDictionary
 *
 *  @return IDRRegion
 */
+ (IDRRegion*)transferDataToRegion:(id)regionDict;

/**
 *  字典数据转IDRFloor
 *
 *  @param floorDict NSDictionary
 *
 *  @return IDRFloor
 */
+ (IDRFloor*)transferDataToFloor:(id)floorDict;

/**
 *  字典数据转IDRUnit
 *
 *  @param unitDict NSDictionary
 *
 *  @return IDRUnit
 */
+ (IDRUnit*)transFerDataToUnit:(id)unitDict;

/**
 *  字典数据转IDRPosition
 *
 *  @param positionDict 点
 *
 *  @return IDRPosition*
 */
+ (IDRPosition*)transferDataToPosition:(id)positionDict;

+ (YFLengthPre*)transferDataToLengthPre:(id)length;

+ (IDRPassData*)transferDataToPassData:(id)passdata;

+ (IDRPassUnit*)transferDataToPassUnit:(id)passUnit;

@end
