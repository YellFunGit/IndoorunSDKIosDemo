//
//  IDRMapData.h
//  YFMapKit
//
//  Created by Sincere on 16/1/20.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "IDRRegion.h"
#import "IDRFloor.h"
#import "IDRUnit.h"
#import "IDRPath.h"
//#import "SVGZip.h"

#import "IDRCoreManager.h"
#import "IDRPassData.h"
#import "IDRPassUnit.h"

@class IDRMapData;

@protocol IDRMapDataDelegate <NSObject>

/**
 *  楼层信息加载成功(svg,path,units,pass数据)
 *
 *  @param sender sender
 */
- (void)loadMapDataSuccess:(IDRMapData*)sender;

@end

@interface IDRMapData : NSObject

- (instancetype)initWithRegion:(IDRRegion*)region delegate:(id)delegate;

/**
 *  加载地图数据
 */
- (void)loadData:(NSString*)floorId;

@property (nonatomic, weak  ) id<IDRMapDataDelegate> delegate;

@property (nonatomic, copy  ) NSString           *mapFile;

@property (nonatomic, strong) IDRRegion          *region;

@property (nonatomic, strong) IDRFloor           *floor;

@end
