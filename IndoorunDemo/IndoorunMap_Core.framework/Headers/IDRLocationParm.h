//
//  IDRLocationParm.h
//  YFMapKit
//
//  Created by binghuang on 16/1/26.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDRPosition;
@class CLHeading;

@interface IDRLocationParm : NSObject

@property(nonatomic,strong) NSString *regionId;
@property(nonatomic,strong) NSString *floorId;

@end

@interface IDRUserLocation : NSObject

@property (nonatomic, retain) IDRPosition *pos;
@property (nonatomic, copy) NSString *regionId;
@property (nonatomic, retain) CLHeading *heading;

@end
