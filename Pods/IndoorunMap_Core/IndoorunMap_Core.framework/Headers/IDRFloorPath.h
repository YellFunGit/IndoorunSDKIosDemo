//
//  IDRFloorPath.h
//  IndoorunMap_Core
//
//  Created by ky on 16/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDRPosition.h"

@interface IDRFloorPath : NSObject

@property (nonatomic) int floorIndex;// 路径所在楼层

@property (nonatomic) int typeId;// 路径终点类型，0为终点，其余参考unitTypeId，分别表示楼梯、电梯等(UnitType)

@property (nonatomic) double distance;// 路线距离;

@property (nonatomic, strong) NSArray<IDRPosition*> *positions;// 路线点集

- (void)print;

@end
