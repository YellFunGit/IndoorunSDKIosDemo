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

@property (nonatomic, assign) float x;

@property (nonatomic, assign) float y;

@property (nonatomic, copy) NSString *floorId;

- (instancetype)initWithX:(float)x Y:(float)y floor:(NSString*)floorId;

- (instancetype)initWithPosition:(IDRPosition*)p;

- (BOOL)equalPsition:(IDRPosition*)p;

- (BOOL)sameLine:(IDRPosition*)p;

- (BOOL)isSameFloor:(IDRPosition*)p;

- (BOOL)isInFloor:(IDRFloor*)floor;

- (CGPoint)point;

- (NSDictionary*)JSONDict;

@end
