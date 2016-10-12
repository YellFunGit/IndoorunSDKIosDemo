//
//  IDRPath.h
//  YFTools
//
//  Created by Sincere on 15/9/28.
//  Copyright © 2015年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IDRCalculate.h"
#import "YFDataTransfer.h"
#import "IDRPassUnit.h"

@interface IDRPath : NSObject

/**
 *  初始化路线数据
 *
 *  @param JSONData JSON
 *
 *  @return instancetype
 */
- (instancetype)initWithJSONData:(id)JSONData;

/**
 *  初始化路线数据
 *
 *  @param lines  路线集合
 *  @param points 路线节点集合
 *  @param matrix 路线节点二位数组
 *
 *  @return instancetype
 */
- (instancetype)initWithLines:(NSArray*)lines
                       points:(NSArray*)points
                       matrix:(NSArray*)matrix;

/**
 *  根据起点终点获取路线
 *
 *  @param sp 起点
 *  @param ep 终点
 *
 *  @return 路线点数组
 */
- (NSArray*)getPathPointsWithSp:(IDRPosition*)sp EP:(IDRPosition*)ep;

/**
 *  根据起点和多个终点获取路线最短的终点
 *
 *  @param sp           起点
 *  @param endPositions 终点集合
 *
 *  @return 路线最短的终点
 */
- (IDRPosition*)getPathPointsWithSp:(IDRPosition *)sp endPositions:(NSArray *)endPositions;

/**
 *  根据起点和多个终点（IDRUnit类型）获取路线最短的终点
 *
 *  @param sp       起点
 *  @param endUnits 终点集合
 *
 *  @return 路线最短的终点
 */
- (IDRPosition*)getPathPointsWithSp:(IDRPosition *)sp endUnits:(NSArray *)endUnits;

- (IDRPosition*)getPathPointsWithSp:(IDRPosition *)sp endUnits:(NSArray *)endUnits WithType:(NSInteger)type;

/**
 *  根据起点和多个公共设置终点获取路线最短的公共设施终点
 *
 *  @param sp          起点
 *  @param endFacUnits 终点集合
 *
 *  @return 终点
 */
- (IDRPosition*)getPathPointsWithSp:(IDRPosition *)sp endFacUnits:(NSArray *)endFacUnits;

/**
 *  根据起点和终点集合（IDRUnit类型）
 *
 *  @param sp       起点
 *  @param endUnits 终点集合
 *
 *  @return 终点Unit（路线终点）
 */
- (IDRUnit*)getPathUnitWithSp:(IDRPosition *)sp endUnits:(NSArray *)endUnits;

/**
 *  根据起点和终点集合（IDRUnit类型）
 *
 *  @param sp       起点
 *  @param endUnits 终点集合
 *
 *  @return 终点Unit（车位终点）
 */
- (IDRUnit*)getCarUnitWithSp:(IDRPosition *)sp endUnits:(NSArray *)endUnits;

/**
 *  根据起点、当前楼层Id、可连通数据获取最近的连通点
 *
 *  @param sp        起点
 *  @param passUnits 连通数据
 *  @param floorId   当前楼层id
 *
 *  @return 连通点
 */
- (IDRPassUnit*)getPassUnitWithSp:(IDRPosition *)sp endUnits:(NSArray *)passUnits floorId:(NSString*)floorId;

/**
 *  获取两点间路线的长度
 *
 *  @param startPos 起点
 *  @param endPos   终点
 *
 *  @return 路线长度
 */
- (CGFloat)getPathDistanceWith:(IDRPosition*)startPos endPosition:(IDRPosition*)endPos;

/**
 *  根据起点、多个终点（Unit类型）获取路线最近的点
 *
 *  @param pos      起点
 *  @param endUnits 终点集合
 *
 *  @return 路线最近点
 */
- (IDRPosition*)getNearestUnitTo:(IDRPosition *)pos allUnits:(NSArray *)endUnits;

/**
 *  路线集合
 */
@property (nonatomic,strong)NSArray * lines;
/**
 *  路线点集合
 */
@property (nonatomic,strong)NSArray * points;
/**
 *  路线二维数组
 */
@property (nonatomic,strong)NSArray * matrix;


@end
