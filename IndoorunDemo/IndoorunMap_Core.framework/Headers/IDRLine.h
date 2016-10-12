//
//  IDRLine.h
//  YFTools
//
//  Created by Sincere on 15/9/6.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDRPosition.h"

@interface IDRLine : NSObject

- (instancetype)initWithStartPosition:(IDRPosition*)sp endPosition:(IDRPosition*)ep;

- (BOOL)equalLine:(IDRLine*)line;

- (NSDictionary*)JSONDict;

@property (nonatomic, retain, readonly) IDRPosition *sPoint;

@property (nonatomic, retain, readonly) IDRPosition *ePoint;

@end
