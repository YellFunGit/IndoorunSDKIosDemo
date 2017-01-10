//
//  IDRPosition.h
//  YFMapKitDemo
//
//  Created by Sincere on 15/9/21.
//  Copyright © 2015年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import "IDREnum.h"

@class IDRFloor;

@interface IDRPosition : NSObject

- (id)initWithJson:(NSDictionary*)jsonData;

/**
 x坐标
 */
@property (nonatomic, assign) float x;

/**
 y坐标
 */
@property (nonatomic, assign) float y;

/**
 楼层id
 */
@property (nonatomic, copy) NSString *floorId;

- (instancetype)initWithX:(float)x Y:(float)y floor:(NSString*)floorId;

- (instancetype)initWithPosition:(IDRPosition*)p;

/**
 两点是否相等

 @param p 输入点
 
 @return 是否相等
 */
- (BOOL)equalPsition:(IDRPosition*)p;

/**
 是否同一楼层

 @param p 输入点

 @return 楼层
 */
- (BOOL)isSameFloor:(IDRPosition*)p;

/**
 点是否在对应楼层

 @param floor 输入楼层

 @return 点是否在对应楼层
 */
- (BOOL)isInFloor:(IDRFloor*)floor;

/**
 返回位置的CGPoint结构
 
 @return cgpint
 */
- (CGPoint)point;

- (NSDictionary*)JSONDict;

@end
