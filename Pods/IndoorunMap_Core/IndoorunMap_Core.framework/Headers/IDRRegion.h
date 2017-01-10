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

@interface IDRRegion : NSObject<NSCopying>

- (id)initWithJson:(NSDictionary*)jsonData;

@property (nonatomic, copy) NSString *Id;//区域编号

@property (nonatomic, copy) NSString *name;//区域名称

@property (nonatomic, copy) NSString *pinyin;//区域拼音

@property (nonatomic, copy) NSString *defaultFloorId;//区域默认显示楼层

@property (nonatomic, copy) NSArray<IDRFloor*> *floorList;//楼层列表

@property (nonatomic, copy) NSString *beaconUUID;//蓝牙设备UUID

@property (nonatomic, copy) NSString *regionType;//区域类型

@property (nonatomic, copy) NSString *cityId;//区域所在城市id

@property (nonatomic, copy) NSString *aDescription;//区域描述信息

@property (nonatomic, copy) NSString *address;//区域地址

@property (nonatomic, strong) NSNumber *northDeflectionAngle;//区域地图的偏北角

@property (nonatomic, copy) NSString *telephone;//联系电话

@property (nonatomic, strong) NSNumber *longitude;//区域所在位置经度

@property (nonatomic, strong) NSNumber *latitude;//区域所在位置的纬度

@property (nonatomic, copy) NSString *status;//区域状态

@property (nonatomic, strong) NSNumber *recordTime;//区域数据记录时间

@property (nonatomic, copy) NSString *recordUser;//区域数据记录人

@property (nonatomic, strong) NSNumber *checkStatus;//区域数据监测状态

@property (nonatomic, strong) NSNumber *collectStatus;//区域数据采集状态

@property (nonatomic, copy) NSString *packingFee;//停车费用

@property (nonatomic, copy) NSString *packingType;//区域停车场类型

@property (nonatomic, copy) NSString *totalPackSize;//停车场车位总数

@property (nonatomic, copy) NSString *workTimes;//工作时间

@property (nonatomic, strong) NSArray *advertList;//广告列表

@property (nonatomic, copy) NSString *photoUrl;//默认显示图片

@property (nonatomic, copy) NSNumber *enDyGuide;//是否准许动态导航

@property (nonatomic, copy) NSString *RegionWholeDataFileName;//region全数据文件名称

@property (nonatomic, strong) NSNumber *RegionWholeDataFileSize;//region全数据大小

@property (nonatomic, strong) NSDictionary *extInfo;//额外属性

/**
 区域北偏角

 @return 北偏角(弧度)
 */
- (CGFloat)northAngle;

/**
 获取楼层index（0是最下一层）
 
 @param floorId 楼层ID
 @return 对应楼层index, -1为未找到
 */
- (NSInteger)getFloorIndex:(NSString*)floorId;

/**
 获取floor结构
 
 @param floorId floorId
 @return IDRFloor简略结构
 */
- (IDRFloor*)getFloor:(NSString*)floorId;

/**
 获取floorId
 
 @param nIndex 楼层Index
 @return 楼层id
 */
- (NSString*)getFloorId:(int)nIndex;

@end
