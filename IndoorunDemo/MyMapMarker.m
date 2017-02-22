//
//  MyMapMarker.m
//  IndoorunDemo
//
//  Created by ky on 10/8/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import "MyMapMarker.h"

@implementation MyMapMarker

- (id)initWithPos:(IDRPosition*)pos {
    
    self = [super init];
    
    if (self) {
        
        self.pos = pos;
        
        self.iconName = @"IndoorunMap_Resource.bundle/YF_CarPosition.png";
    }
    
    return self;
}

@end
