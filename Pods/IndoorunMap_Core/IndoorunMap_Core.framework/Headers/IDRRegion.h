//
//  IDRRegion.h
//  YellfunMapKit
//
//  Created by Sincere on 15/7/30.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

@class IDRFloor;


/**
 区域
 */
@interface IDRRegion : NSObject<NSCopying>

/**
 *  区域编号
 */
@property (nonatomic, copy) NSString *Id;
/**
 *  区域名称
 */
@property (nonatomic, copy) NSString *name;
/**
 *  区域默认显示楼层
 */
@property (nonatomic, copy) NSString *defaultFloorId;
/**
 *  区域中楼层数据
 */
@property (nonatomic, retain) NSArray *floorList;
/**
 *  安装蓝牙设备UUID
 */
@property (nonatomic, copy) NSString *beaconUUID;
/**
 *  区域拼音
 */
@property (nonatomic, copy) NSString *pinyin;
/**
 *  区域类型
 */
@property (nonatomic, copy) NSString *regionType;
/**
 *  区域所在城市id
 */
@property (nonatomic, copy) NSString *cityId;
/**
 *  区域描述信息
 */
@property (nonatomic, copy) NSString *aDescription;
/**
 *  区域地址
 */
@property (nonatomic, copy) NSString *address;
/**
 *  区域地图的偏北角
 */
@property (nonatomic, retain) NSNumber *northDeflectionAngle;
/**
 *  联系电话
 */
@property (nonatomic, copy) NSString *telephone;
/**
 *  区域所在位置经度
 */
@property (nonatomic, retain) NSNumber *longitude;
/**
 *  区域所在位置的纬度
 */
@property (nonatomic, retain) NSNumber *latitude;
/**
 *  区域状态
 */
@property (nonatomic, copy) NSString *status;
/**
 *  区域数据记录时间
 */
@property (nonatomic, retain) NSNumber *recordTime;
/**
 *  区域数据记录人
 */
@property (nonatomic, copy) NSString *recordUser;
/**
 *  区域数据监测状态
 */
@property (nonatomic, retain) NSNumber *checkStatus;
/**
 *  区域数据采集状态
 */
@property (nonatomic, retain) NSNumber *collectStatus;
/**
 *  停车费用
 */
@property (nonatomic, copy) NSString *packingFee;
/**
 *  区域停车场类型
 */
@property (nonatomic, copy) NSString *packingType;
/**
 *  停车场车位总数
 */
@property (nonatomic, copy) NSString *totalPackSize;
/**
 *  工作时间
 */
@property (nonatomic, copy) NSString *workTimes;
/**
 *  广告列表
 */
@property (nonatomic, retain) NSArray *advertList;

/**
 *  默认显示图片
 */
@property (nonatomic, copy) NSString *photoUrl;

/**
 *  是否准许动态导航
 */
@property (nonatomic, copy) NSNumber *enDyGuide;

/**
 *  指纹数据更新时间
 */
@property (nonatomic, retain) NSNumber *fingerDataUpdateTime;
/**
 *  数据最新更新时间
 */
@property (nonatomic, retain) NSNumber *modifyTime;
/**
 region全数据文件名称
 */
@property (nonatomic, copy) NSString *RegionWholeDataFileName;
/**
 region全数据大小
 */
@property (nonatomic, retain) NSNumber *RegionWholeDataFileSize;

/**
 获取楼层

 @param floorId 楼层ID

 @return 对应楼层
 */
- (IDRFloor*)getFloorBy:(NSString*)floorId;

/**
 默认楼层

 @return 默认楼层
 */
- (IDRFloor*)defaultFloor;

/**
 区域北偏角

 @return 北偏角(弧度)
 */
- (CGFloat)northAngle;

@end
