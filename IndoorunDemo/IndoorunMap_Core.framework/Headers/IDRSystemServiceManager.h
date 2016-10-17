//
//  IDRSystemServiceManager.h
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@interface IDRSystemServiceManager : NSObject

@property (nonatomic, assign, readonly)  BOOL isNetworkAvailable;

@property (nonatomic, assign, readonly) BOOL isBlueToothAvailable;

@property (nonatomic, assign, readonly) BOOL isLocationAvailable;

+ (instancetype)sharedInstance;

- (void)initServer;

@end
