//
//  IDRLocationSimulateManager.h
//  IndoorunMap_Core
//
//  Created by ky on 8/15/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDRLocationSimulateManager;

@protocol IDRLocationSimulateManagerDelegate <NSObject>

- (void)didSimulateStop:(IDRLocationSimulateManager*)sender;

- (void)didSimulateStart:(IDRLocationSimulateManager*)sender;

@end

@interface IDRLocationSimulateManager : NSObject

@property (nonatomic, weak) id<IDRLocationSimulateManagerDelegate> delegate;

@property (nonatomic, assign) BOOL startSimulate;

+ (instancetype)sharedInstance;

- (void)startRecord:(NSString*)regionId;

- (void)stopRecord;

- (void)recordBeacons:(NSString*)regionId beacons:(NSArray*)beacons;

- (void)startSimulate:(NSString*)regionId;

@end
