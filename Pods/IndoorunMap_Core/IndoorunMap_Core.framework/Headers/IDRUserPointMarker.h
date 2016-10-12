//
//  IDRUserPointView.h
//  IndoorunMap_Core
//
//  Created by ky on 16/8/2.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import "IDRMapMarker.h"

@interface IDRUserPointMarker : IDRMapMarker

@property (nonatomic, assign) BOOL isMoving;

- (id)initWithPos:(IDRPosition*)pos;

@end
