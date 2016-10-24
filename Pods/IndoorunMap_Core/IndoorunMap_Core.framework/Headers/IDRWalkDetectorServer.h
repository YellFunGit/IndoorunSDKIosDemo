//
//  IDRWalkDetectorServer.h
//  移动检测
//
//  Created by ky on 16/4/15.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>

@class IDRWalkDetectorServer;

@protocol IDRWalkDetectorServerDelegate <NSObject>

/**
 *  静止状态切换为行走状态(可用于停车检测)
 *
 */
- (void)onChangeToWalk:(IDRWalkDetectorServer*)sender;

@end

@interface IDRWalkDetectorServer : NSObject

@property (nonatomic, weak) id<IDRWalkDetectorServerDelegate> delegate;

/**
 *  启动服务
 */
- (void)startServer;

/**
 *  停止检测
 */
- (void)stopServer;

@end
