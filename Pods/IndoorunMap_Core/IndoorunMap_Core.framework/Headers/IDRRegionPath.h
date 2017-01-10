//
//  IDRRegionPath.h
//  IndoorunMap_Core
//
//  Created by ky on 16/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "IDRPosition.h"
#include "IDRPathResult.h"
#include "IDRRegion.h"

@interface IDRRegionPath : NSObject 

@property (nonatomic) IDRRegion *region;

- (id)initWithJson:(NSDictionary*)data;

- (IDRPathResult*)searchFrom:(IDRPosition*)p1 to:(IDRPosition*)p2 car:(BOOL)car;

@end
