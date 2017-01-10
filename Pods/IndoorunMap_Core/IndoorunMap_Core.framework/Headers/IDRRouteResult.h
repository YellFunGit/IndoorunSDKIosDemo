//
//  IDRRouteResult.h
//  IndoorunMap_Core
//
//  Created by ky on 16/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "IDRFloorPath.h"

@interface IDRRouteResult : NSObject

@property (nonatomic, strong) NSArray<IDRFloorPath*>* floorPath;//每段路径数据

@property (nonatomic) double distance;//全路径的总距离

/**
 获取除第一段的所有长度
 */
- (CGFloat)getNextFloorPath;

@end
