//
//  IDRDownLoadManager.h
//  IndoorunMap_Core
//
//  Created by ky on 8/13/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDRRegion.h"
#import "IDRMapKitConfig.h"

@interface IDRDownLoadManager : NSObject

+ (instancetype)sharedInstance;

- (OfflineDataStatus)getRegionDataPercent:(IDRRegion*)region;

@end
