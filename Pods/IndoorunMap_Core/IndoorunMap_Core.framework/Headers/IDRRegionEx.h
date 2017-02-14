//
//  IDRRegionData.h
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDRRegion.h"

@class IDRRegionPath;
@class IDRFloor;
@class IDRPosition;
@class IDRUnit;
@class IDRRouteResult;

/**
*  单个Region的全部数据
*/
@interface IDRRegionEx : IDRRegion

@property (nonatomic, copy  ) NSArray<IDRUnit*> *outerExitList;//出口列表

@property (nonatomic, strong) IDRRegionPath *regionPath;

- (id)initWithJson:(NSDictionary *)jsonData;

- (BOOL)containFloor:(IDRFloor*)floor;

/**
 获取详细IDRfloor结构
 
 @param floorId 楼层id
 
 @return IFRFloor实例
 */
- (IDRFloor*)getFloorWithFloorId:(NSString*)floorId;

- (IDRFloor*)getFloorWithFloorIndex:(NSInteger)floorIndex;



/**
 获取围栏信息
 */
- (NSArray*)getFences;

@end
