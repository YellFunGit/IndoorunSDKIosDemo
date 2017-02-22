//
//  IDRMapMarker.h
//  YellfunMapKit
//
//  Created by Sincere on 15/7/31.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDRPosition.h"
#import "IDRMapKitConfig.h"

/**
 *  IDRMapMarkerProtocal,自定义marker必须实现此协议
 *
 */
@protocol IDRMapMarkerProtocal <NSObject>

@property (nonatomic, copy) NSString *iconName;

//@property (nonatomic, retain) UIImage *icon;

@property (nonatomic, retain) IDRPosition *pos;

@property (nonatomic, readonly) NSInteger Id;

@property (nonatomic, readonly) NSInteger Id_AR;

@property (nonatomic, assign) BOOL alwaysShow;

@end

/**
 *  IDRMapMarker，help类，如果不需要其他功能，从此类派生更便捷
 *
 */
@interface IDRMapMarker : NSObject<IDRMapMarkerProtocal>

@property (nonatomic, copy) NSString *iconName;

@property (nonatomic, assign) BOOL alwaysShow;

//@property (nonatomic, retain) UIImage *icon;

@property (nonatomic, retain) IDRPosition *pos;

@property (nonatomic, readonly) NSInteger Id;

@property (nonatomic, readonly) NSInteger Id_AR;

@end

//下面3中marker为sdk提供的默认marker，方便用户使用
/**
 *  车marker
 */
@interface IDRCarMarker : IDRMapMarker

- (instancetype)initWith:(IDRPosition*)pos;

@end

/**
 起点marker
 */
@interface IDRStartMarker : IDRMapMarker

- (id)initWith:(IDRPosition*)pos;

@end

/**
  便利设施
 */
@interface IDRFacilitiesMarker : IDRMapMarker

@property (nonatomic) UnitType type;

- (instancetype)initWith:(IDRPosition *)pos type:(UnitType)type;

@end

@interface IDRTestMarker : IDRMapMarker

- (instancetype)initWith:(IDRPosition *)pos;

@end


