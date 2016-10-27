//
//  IDRMultiLocationInfo.h
//  IndoorunMap_Core
//
//  Created by ky on 16/8/2.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JSONModel/JSONModel.h>

@interface IDRMultiLocationPos : JSONModel

@property (nonatomic, assign) CGFloat x;

@property (nonatomic, assign) CGFloat y;

@end

@interface IDRMultiLocationInfo : JSONModel

@property (nonatomic, copy) NSString *phoneUUID;

@property (nonatomic, retain) NSNumber<Optional> *inLocating;

@property (nonatomic, retain) NSNumber<Optional> *lastLocatingTime;

@property (nonatomic, copy) NSString<Optional> *regionId;

@property (nonatomic, copy) NSString<Optional> *regionName;

@property (nonatomic, retain) IDRMultiLocationPos<Optional> *pos;

@property (nonatomic, copy) NSString<Optional> *floorId;

@property (nonatomic, copy) NSString<Optional> *floorName;

@end
