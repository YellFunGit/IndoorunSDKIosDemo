//
//  MyMapMarker.h
//  IndoorunDemo
//
//  Created by ky on 10/8/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IndoorunMap_Core/IndoorunMap_Core.h>

@interface MyMapMarker : NSObject<IDRMapMarkerProtocal>

@property (nonatomic) UIImage *icon;

@property (nonatomic) IDRPosition *pos;

@property (nonatomic) NSInteger Id;

- (id)initWithPos:(IDRPosition*)pos;

@end
