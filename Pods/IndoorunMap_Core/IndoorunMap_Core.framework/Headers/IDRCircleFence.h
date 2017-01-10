//
//  IDRCircleFence.h
//  IndoorunMap_Core
//
//  Created by ky on 27/12/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <IndoorunMap_Core/IndoorunMap_Core.h>
#import "IDRFence.h"

@interface IDRCircleFence : IDRFence

@property (nonatomic) IDRPosition *center;

@property (nonatomic) CGFloat radius;

- (id)init:(IDRPosition*)center radius:(CGFloat)radius enterBlock:(void(^)(IDRFence* fence))enterBlock leaveBlock:(void(^)(IDRFence* fence))leaveBlock;

@end
