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

/**
 *  unitId
 */
@property (nonatomic, copy) NSString * Id;
/**
 *  floorId
 */
@property (nonatomic, copy) NSString * floorId;
/**
 *  名称
 */
@property (nonatomic, copy) NSString * name;
/**
 *  类型编号
 */
@property (nonatomic, retain) NSNumber * unitTypeId;
/**
 *  详细信息
 */
@property (nonatomic, copy) NSString * aDescription;
/**
 *  左边界距离地图左边界的距离
 */
@property (nonatomic, retain) NSNumber * boundLeft;
/**
 *  顶部距离地图顶部的距离
 */
@property (nonatomic, retain) NSNumber * boundTop;
/**
 *  右边界距离截图左边界的距离
 */
@property (nonatomic, retain) NSNumber * boundRight;
/**
 *  底部距离地图顶部的距离
 */
@property (nonatomic, retain) NSNumber * boundBottom;
/**
 *  unit状态
 */
@property (nonatomic, copy) NSString * status;
/**
 *  unit编辑人
 */
@property (nonatomic, copy) NSString * creator;
/**
 *  unit创建时间
 */
@property (nonatomic, retain) NSDate   * gmtCreate;


@property (nonatomic, retain) IDRExtInfo * extInfo;

/**
 *  根据比例获取unit的Frame
 *
 *  @param scale 比例
 *
 *  @return CGRect
 */
- (CGRect)getRectWithScale:(CGFloat)scale;

/**
 *  根据比例获取unit的中心点
 *
 *  @param scale 比例
 *
 *  @return CGPoint
 */
- (CGPoint)getPointWithScale:(CGFloat)scale;

- (IDRPosition*)getUnitPos;

- (NSString*)unitType;

@end
