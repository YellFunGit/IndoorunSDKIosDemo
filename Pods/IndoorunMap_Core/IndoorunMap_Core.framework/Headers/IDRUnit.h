//
//  IDRUnit.h
//  YellfunMapKit
//
//  Created by Sincere on 15/7/30.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class IDRPosition;
@class IDRExtInfo;
/**
 *  单元数据
 */
@interface IDRUnit : NSObject

- (id)initWithJson:(NSDictionary*)unitDict;

@property (nonatomic, copy) NSString * Id;//unitId

@property (nonatomic, copy) NSString * floorId;//floorId

@property (nonatomic, copy) NSString * name;//名称

@property (nonatomic, strong) NSNumber * unitTypeId;//类型编号

@property (nonatomic, copy) NSString * aDescription;//详细信息

@property (nonatomic, strong) NSNumber * boundLeft;//左边界距离地图左边界的距离

@property (nonatomic, strong) NSNumber * boundTop;//顶部距离地图顶部的距离

@property (nonatomic, strong) NSNumber * boundRight;//右边界距离截图左边界的距离

@property (nonatomic, strong) NSNumber * boundBottom;//底部距离地图顶部的距离

@property (nonatomic, copy) NSString * status;//unit状态

@property (nonatomic, copy) NSString *creator;//unit编辑人

@property (nonatomic, copy) NSString *points;//unit的形状(x0,y0 x1,y1, ....)

@property (nonatomic, strong) NSDate *gmtCreate;//unit创建时间

@property (nonatomic, strong) IDRExtInfo * extInfo;

@property (nonatomic, strong) UIColor *color;//unit颜色

/**
 获取unit的poly形状

 @return NSString集合，使用CGPointFromString获取每个point
 */
- (NSArray*)getPoly;

- (IDRPosition*)getUnitPos;

- (NSString*)unitType;

@end
