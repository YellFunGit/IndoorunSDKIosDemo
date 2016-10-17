//
//  IDRMapMarker.h
//  YellfunMapKit
//
//  Created by Sincere on 15/7/31.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDRPosition.h"

/**
 *  IDRMapMarkerProtocal,自定义marker必须实现此协议
 *
 */
@protocol IDRMapMarkerProtocal <NSObject>

@property (nonatomic, retain) UIImage *icon;

@property (nonatomic, retain) IDRPosition *pos;

@property (nonatomic, assign) NSInteger Id;

@end

/**
 *  IDRMapMarker，help类，如果不需要其他功能，从此类派生更便捷
 *
 */
@interface IDRMapMarker : NSObject<IDRMapMarkerProtocal>

@property (nonatomic, retain) UIImage *icon;

@property (nonatomic, retain) IDRPosition *pos;

@property (nonatomic, assign) NSInteger Id;

@end


