//
//  IDRMultiLocationInfo.h
//  IndoorunMap_Core
//
//  Created by ky on 16/8/2.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface IDRMultiLocationPos : NSObject

- (id)initWithDictionary:(NSDictionary*)dic;

@property (nonatomic) NSNumber* x;

@property (nonatomic) NSNumber* y;

@end

@interface IDRMultiLocationInfo : NSObject

- (id)initWithDictionary:(NSDictionary*)dic;

@property (nonatomic, copy) NSString *phoneUUID;

@property (nonatomic) NSNumber *inLocating;

@property (nonatomic) NSNumber *lastLocatingTime;

@property (nonatomic, copy) NSString *regionId;

@property (nonatomic, copy) NSString *regionName;

@property (nonatomic) IDRMultiLocationPos *pos;

@property (nonatomic, copy) NSString *floorId;

@property (nonatomic, copy) NSString *floorName;

@end
