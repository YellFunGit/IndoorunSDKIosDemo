//
//  IDRSystemServiceManager.h
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface IDRSystemServiceManager : NSObject

/**
 网络连接是否可用
 */
@property (nonatomic, assign, readonly)  BOOL isNetworkAvailable;

/**
 蓝牙是否可用
 */
@property (nonatomic, assign, readonly) BOOL isBlueToothAvailable;

/**
 定位服务是否可用
 */
@property (nonatomic, assign, readonly) BOOL isLocationAvailable;

+ (instancetype)sharedInstance;

/**
 启动服务
 */
- (void)initServer;

@end
