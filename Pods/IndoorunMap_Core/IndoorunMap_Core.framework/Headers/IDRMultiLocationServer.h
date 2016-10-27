//
//  IDRMultiLocationServer.h
//  IndoorunMap_Core
//
//  Created by ky on 16/8/2.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDRMapView;

@interface IDRMultiLocationServer : NSObject

/**
 *  地图view
 */
@property (nonatomic, weak) IDRMapView *mapView;

/**
 *  请求所需要的uuid
 */
@property (nonatomic, retain) NSArray *phoneUUIDs;

+ (instancetype)sharedInstance;

/**
 *  启动服务
 */
- (void)startServer;

/**
 *  停止服务
 */
- (void)stopServer;

- (void)serverCallLocation:(NSArray*)phoneUUIDs success:(void(^)(NSArray* locationInfos))success;

@end
