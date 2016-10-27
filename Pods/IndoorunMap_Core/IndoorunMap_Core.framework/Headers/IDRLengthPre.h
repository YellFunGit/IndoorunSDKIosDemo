//
//  IDRLengthPre.h
//  YFTools
//
//  Created by Sincere on 15/9/29.
//  Copyright © 2015年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDRLengthPre : NSObject<NSCoding>

- (instancetype)initWithLength:(double)length
                      preIndex:(int)preIndex;

@property (nonatomic)NSNumber* length;
@property (nonatomic)NSNumber* preIndex;

@end
