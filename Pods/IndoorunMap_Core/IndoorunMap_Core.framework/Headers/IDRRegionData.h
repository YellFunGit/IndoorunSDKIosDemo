//
//  IDRRegionData.h
//  YFMapKit
//
//  Created by 刘浩 on 16/2/19.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class IDRFloor;
@class IDRPath;
@class IDRPosition;
@class IDRPassUnit;
@class IDRPassData;

/**
*  单个Region的全部数据
*/
@interface IDRRegionData : NSObject

/**
 *  编辑人
 */
@property (nonatomic, copy  ) NSString *modifyUser;
/**
 *  状态
 */
@property (nonatomic, copy  ) NSString *status;
/**
 *  采集状态
 */
@property (nonatomic, strong) NSNumber *collectStatus;
/**
 *  编辑时间
 */
@property (nonatomic, strong) NSNumber *modifyTime;
/**
 *  联系电话
 */
@property (nonatomic, copy  ) NSString *telephone;
/**
 *  默认显示楼层id
 */
@property (nonatomic, copy  ) NSString *defaultFloorId;
/**
 *  停车场类型
 */
@property (nonatomic, copy  ) NSString *packingType;
/**
 *  安装蓝牙设备UUID
 */
@property (nonatomic, copy  ) NSString *beaconUUID;
/**
 *  工作时间
 */
@property (nonatomic, copy  ) NSString *workTimes;
/**
 *  楼层列表
 */
@property (nonatomic, copy  ) NSArray  *floorList;
/**
 *  纬度
 */
@property (nonatomic, strong) NSNumber *latitude;
/**
 *  楼层连通列表
 */
@property (nonatomic, retain) IDRPassData *passData;
/**
 *  区域类型
 */
@property (nonatomic, copy  ) NSString *regionType;
/**
 *  名称
 */
@property (nonatomic, copy  ) NSString *name;
/**
 *  停车费用
 */
@property (nonatomic, copy  ) NSString *packingFee;
/**
 *  地图偏北角
 */
@property (nonatomic, strong) NSNumber *northDeflectionAngle;
/**
 *  RegionId
 */
@property (nonatomic, copy  ) NSString *Id;
/**
 *  城市Id
 */
@property (nonatomic, copy  ) NSString *cityId;
/**
 *  经度
 */
@property (nonatomic, strong) NSNumber *longitude;
/**
 *  记录时间
 */
@property (nonatomic, strong) NSNumber *recordTime;
/**
 *  记录人
 */
@property (nonatomic, copy  ) NSString *recordUser;
/**
 *  测试状态
 */
@property (nonatomic, strong) NSNumber *checkStatus;
/**
 *  地址
 */
@property (nonatomic, copy  ) NSString *address;
/**
 *  停车位总数
 */
@property (nonatomic, copy  ) NSString *totalPackSize;
/**
 *  广告列表
 */
@property (nonatomic, copy  ) NSArray  *advertList;

@property (nonatomic, copy  ) NSArray  *outerExitList;

@property (nonatomic, copy  ) NSString *photoUrl;

@property (nonatomic, strong) NSNumber *enDyGuide;


/**
 *  是否包含楼层
 *
 *  @param floor FLoor
 *
 *  @return （YES包含、NO不包含）
 */
- (BOOL)containFloor:(IDRFloor*)floor;

/**
 *  根据楼层获取楼层的Units
 *
 *  @param floor 楼层
 *
 *  @return Unit数组
 */
- (NSArray*)getUnitsWithFloor:(NSString*)floorId;

/**
 *  根据Floor获取路线数据
 *
 *  @param floorId 楼层Id
 *
 *  @return 路线数据
 */
- (IDRPath*)findPathByFloor:(NSString*)floorId;

- (IDRFloor*)getFloorWithFloorId:(NSString*)floorId;

- (NSArray*)getAllValidPassgroups:(NSString*)startFloorId endFloor:(NSString*)endFloorId car:(BOOL)isCar;

- (CGFloat)getDisWith:(IDRPosition*)startPos end:(IDRPosition*)endPos withPass:(NSArray<IDRPassUnit*>*)pass;

@end
