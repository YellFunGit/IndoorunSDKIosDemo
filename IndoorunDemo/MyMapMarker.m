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
        
        self.icon = [UIImage imageNamed:@"YF_CarPosition"];
    }
    
    return self;
}

@end
