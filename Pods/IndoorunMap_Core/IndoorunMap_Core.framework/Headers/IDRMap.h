//
//  MapRender.h
//  TestOpengles
//
//  Created by ky on 8/8/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDRMapMarker.h"
#import "IDRLine.h"
#import "IDRGlesMap.h"

@class IDRNaviSuggestion;
@class IDRMapView;
@class IDRUnit;
@class IDRPosition;

@interface IDRMap : IDRGlesMap

- (void)setBirdLookMargin:(CGFloat)left top:(CGFloat)top right:(CGFloat)right bottom:(CGFloat)bottom;

@end
