//
//  IDRPassUnit.h
//  YFMapKit
//
//  Created by Sincere on 16/3/15.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDRPassUnit : NSObject

- (BOOL)equalFloorId:(NSString*)floorId;

@property (nonatomic,copy)   NSString * floorName;
@property (nonatomic,strong) NSNumber * unitTypeId;
@property (nonatomic,copy)   NSString * unitId;

@property (nonatomic,copy)   NSString * floorId;
@property (nonatomic,strong) NSNumber * x;
@property (nonatomic,strong) NSNumber * y;

@end
