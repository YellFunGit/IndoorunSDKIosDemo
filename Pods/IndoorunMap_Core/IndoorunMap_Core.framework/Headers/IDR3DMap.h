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
#import "IDRLine.h"
#import "IDRGlesMap.h"

@interface IDR3DMap : IDRGlesMap

@property (nonatomic, assign) BOOL normal2DMap;

@property (nonatomic, assign) NSInteger floorIndex;

- (void)setMiniMap:(CGRect)frame;

- (void)setBirdLookMargin:(CGFloat)left top:(CGFloat)top right:(CGFloat)right bottom:(CGFloat)bottom;

@end
