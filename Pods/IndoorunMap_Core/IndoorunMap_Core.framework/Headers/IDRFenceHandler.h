//
//  IDRAreaMgr.h
//  IndoorunMap_Core
//
//  Created by ky on 06/12/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDRFence;
@class IDRPosition;

@interface IDRFenceHandler : NSObject

- (void)addNewArea:(IDRFence*)area;

- (void)removeArea:(IDRFence*)area;

- (void)removeAllAreas;

- (void)processOnNewPos:(IDRPosition*)newPos;

@end
