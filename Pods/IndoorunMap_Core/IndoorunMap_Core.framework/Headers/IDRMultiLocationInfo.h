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

@property (nonatomic) CGFloat x;

@property (nonatomic) CGFloat y;

@end

@interface IDRMultiLocationInfo : NSObject

- (id)initWithDictionary:(NSDictionary*)dic;

@property (nonatomic, copy) NSString *phoneUUID;//phoneuuid

@property (nonatomic, strong) NSNumber *inLocating;//对方是否在定位中

@property (nonatomic, strong) NSNumber *lastLocatingTime;//对方最后一次定位时间

@property (nonatomic, copy) NSString *regionId;//所处的regionid

@property (nonatomic, copy) NSString *regionName;//所处的region名称

@property (nonatomic, strong) IDRMultiLocationPos *pos;//定位坐标

@property (nonatomic, copy) NSString *floorId;//定位楼层id

@property (nonatomic, copy) NSString *floorName;//定位楼层名称

@end
