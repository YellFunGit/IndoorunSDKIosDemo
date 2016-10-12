//
//  IDRPassData.h
//  YFMapKit
//
//  Created by Sincere on 16/3/15.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDRPassData : NSObject

- (BOOL)needPassData;

- (NSArray*)getTargetUnitWithFloorId:(NSString*)floorId;

- (NSArray*)getAllValidPassgroups:(NSString*)startFloorId endFloor:(NSString*)endFloorId isCar:(BOOL)caiNavi;

@property (nonatomic,copy)NSArray * passGroup;

@end
