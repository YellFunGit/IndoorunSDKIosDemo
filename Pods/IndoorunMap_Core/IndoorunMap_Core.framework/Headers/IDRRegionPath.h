//
//  IDRRegionPath.h
//  IndoorunMap_Core
//
//  Created by ky on 16/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDRPosition.h"
#import "IDRLine.h"
#import "IDRRouteResult.h"


@class IDRRegion;

@interface IDRRegionPath : NSObject 

@property (nonatomic, strong) IDRRegion *region;

- (NSArray<IDRLine*>*)getPath:(NSString*)floorId;

- (id)initWithJson:(NSDictionary*)data;

- (IDRRouteResult*)searchFrom:(IDRPosition*)p1 to:(IDRPosition*)p2 car:(BOOL)car;

@end
