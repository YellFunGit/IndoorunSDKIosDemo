//
//  IDRMultiLocationServer.h
//  IndoorunMap_Core
//
//  Created by ky on 16/8/2.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDRMultiLocationInfo;
@class IDRMultiLocationServer;

@protocol IDRMultiLocationServerDelegate <NSObject>

- (void)onMultilocateSuccess:(IDRMultiLocationServer*)sender success:(NSArray<IDRMultiLocationInfo*>*)locationInfos;

@end

@interface IDRMultiLocationServer : NSObject

@property (nonatomic, weak) id<IDRMultiLocationServerDelegate> delegate;

/**
 *  启动服务
 */
- (void)startServer:(NSArray*)phoneUUIDs;

/**
 *  停止服务
 */
- (void)stopServer;

@end
