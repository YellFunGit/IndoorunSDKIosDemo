//
//  IDRPassData.h
//  SDK
//
//  Created by Indoorun
//  Copyright © 2016年 Indoorun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDRPassData : NSObject

/**
 是否有通道
 */
- (BOOL)needPassData;

/**
 获取能到对应楼层的所有通道unit数组

 @param floorId 楼层id

 @return 通道数组
 */
- (NSArray*)getTargetUnitWithFloorId:(NSString*)floorId;

@property (nonatomic, copy) NSArray * passGroup;

@end
