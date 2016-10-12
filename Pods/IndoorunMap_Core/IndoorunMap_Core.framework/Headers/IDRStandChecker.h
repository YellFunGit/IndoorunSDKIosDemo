//
//  IDRStandChecker.h
//  YFTools
//
//  Created by ky on 16/5/6.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class IDRPosition;

@class IDRStandChecker;

@interface IDRStandChecker : NSObject

@property (nonatomic, retain) IDRPosition *lastPos;

+ (instancetype)sharedInstance;

- (BOOL)checkIsStand:(IDRPosition*)pos;

@end
