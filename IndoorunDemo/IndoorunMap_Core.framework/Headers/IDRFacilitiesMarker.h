//
//  IDRFacilitiesOverlayView.h
//  YTSearchCar
//
//  Created by binghuang on 15/12/1.
//  Copyright © 2015年 Sincere. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDRMapMarker.h"
#import <CoreLocation/CoreLocation.h>
#import "IDRPosition.h"

@interface IDRFacilitiesMarker : IDRMapMarker

- (instancetype)initWith:(IDRPosition *)pos;

@property (nonatomic) BOOL isTemp;

@end
