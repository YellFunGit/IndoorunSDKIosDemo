//
//  IDRFence.h
//  IndoorunMap_Core
//
//  Created by ky on 27/12/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDRPosition.h"


@interface IDRFence : NSObject

@property (nonatomic, copy) void (^enterTask)(IDRFence* fence);

@property (nonatomic, copy) void (^leaveTask)(IDRFence* fence);

- (BOOL)checkPosInFence:(IDRPosition*)p;

- (BOOL)isEnter:(IDRPosition*)p0 p1:(IDRPosition*)p1;

- (BOOL)isLeave:(IDRPosition*)p0 p1:(IDRPosition*)p1;

- (BOOL)isValid;

- (void)invalid;

@end
