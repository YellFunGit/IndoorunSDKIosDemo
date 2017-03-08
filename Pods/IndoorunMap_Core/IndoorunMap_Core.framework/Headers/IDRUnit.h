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
NS_ASSUME_NONNULL_BEGIN

@interface IDRUnit : NSObject

- (id)initWithJson:(NSDictionary*)unitDict;

@property (nonatomic, copy) NSString * Id;//unitId

@property (nonatomic, copy) NSString * floorId;//floorId

@property (nonatomic, copy) NSString * name;//名称

@property (nonatomic, strong) NSNumber * unitTypeId;//类型编号

@property (nonatomic, copy, nullable) NSString * aDescription;//详细信息

@property (nonatomic, strong, nullable) NSNumber * boundLeft;//左边界距离地图左边界的距离

@property (nonatomic, strong, nullable) NSNumber * boundTop;//顶部距离地图顶部的距离

@property (nonatomic, strong, nullable) NSNumber * boundRight;//右边界距离截图左边界的距离

@property (nonatomic, strong, nullable) NSNumber * boundBottom;//底部距离地图顶部的距离

@property (nonatomic, copy, nullable) NSString * status;//unit状态

@property (nonatomic, copy, nullable) NSString *creator;//unit编辑人

@property (nonatomic, copy, nullable) NSString *points;//unit的形状(x0,y0 x1,y1, ....)

@property (nonatomic, strong, nullable) NSDate *gmtCreate;//unit创建时间

@property (nonatomic, strong, nullable) NSDictionary * extInfo;

@property (nonatomic, strong, nullable) UIColor *color;//unit颜色

/**
 获取unit的poly形状

 @return NSString集合，使用CGPointFromString获取每个point
 */
- (NSArray*)getPoly;

- (IDRPosition*)getUnitPos;

- (NSString*)unitType;

- (BOOL)outerExit;

- (NSString*)outerLink;

- (NSString*)exitName;

@end

NS_ASSUME_NONNULL_END
