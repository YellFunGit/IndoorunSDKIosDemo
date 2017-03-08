//
//  IDR3DMap.h
//  IndoorunMap_Core
//
//  Created by ky on 09/01/2017.
//  Copyright © 2017 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDRMapMarker.h"
#import "IDRMapKitConfig.h"
#import "IDRLine.h"
#import "IDRGlesMap.h"

@interface IDR3DMap : IDRGlesMap

@property (nonatomic, assign) IDRMapDisplayMode mapDisplayMode;

@property (nonatomic, assign) NSInteger floorIndex;

@property (nonatomic, assign) CGFloat eyeDistanceFactor;

- (void)setMiniMap:(CGRect)frame;

- (void)setBirdLookMargin:(CGFloat)left top:(CGFloat)top right:(CGFloat)right bottom:(CGFloat)bottom;

@end
