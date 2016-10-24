//
//  IDRPassUnit.h
//  YFMapKit
//
//  Created by Sincere on 16/3/15.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 通道unit
 */
@interface IDRPassUnit : NSObject

- (BOOL)equalFloorId:(NSString*)floorId;

@property (nonatomic,copy)   NSString * floorName;//楼层名
@property (nonatomic,strong) NSNumber * unitTypeId;//通道类型（UnitType）
@property (nonatomic,copy)   NSString * unitId;//unitid

@property (nonatomic,copy)   NSString * floorId;//楼层id
@property (nonatomic,strong) NSNumber * x;//x坐标
@property (nonatomic,strong) NSNumber * y;//y坐标

@end
