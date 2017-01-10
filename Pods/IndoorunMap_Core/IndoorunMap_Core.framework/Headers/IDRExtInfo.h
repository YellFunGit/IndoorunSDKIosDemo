//
//  IDRExtInfo.h
//  YFMapKit
//
//  Created by Sincere on 16/4/28.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 出口结构数据类型
 */
@interface IDRExtInfo : NSObject

- (id)initWithJson:(NSDictionary*)jsonData;

@property (nonatomic, assign) BOOL outerExit;

@property (nonatomic, copy) NSString * outerLink;

@property (nonatomic, copy) NSString * exitName;

@end
