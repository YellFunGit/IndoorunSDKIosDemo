//
//  UIColor+YFHexColor.h
//  YFMapKitDemo
//
//  Created by Sincere on 15/9/21.
//  Copyright © 2015年 Sincere. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (YFHexColor)

+ (UIColor *)ColorWithHex:(NSString *)hexColor;

+ (UIColor *)ColorWithHex:(NSString *)hexColor alpha:(CGFloat)alpha;

@end
