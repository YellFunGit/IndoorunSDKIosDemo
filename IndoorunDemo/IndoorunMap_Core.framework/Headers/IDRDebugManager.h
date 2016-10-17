//
//  IDRDebugManager.h
//  YFMapKit
//
//  Created by ky on 16/5/7.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol IDRDebugManagerDelegate <NSObject>

- (void)debugOutput:(NSString*)debugText;

@end

@interface IDRDebugManager : NSObject

@property (nonatomic, weak) id<IDRDebugManagerDelegate> delegate;

+ (instancetype)sharedInstance;

- (void)debugOutput:(NSString*)debugText;

@end
