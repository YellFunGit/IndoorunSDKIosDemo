//
//  YFNaviSuggetion.h
//  YFMapKit
//
//  Created by ky on 16/6/24.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * 在当前段内的建议
 */
typedef NS_ENUM(int, CurrentSuggestion) {
    
    SUG_FRONT = 0,
    SUG_LEFT,
    SUG_BACKWARD,
    SUG_RIGHT
};

/**
 * 下一段的建议
 */
typedef NS_ENUM(int, NextSuggestion) {
    
    NEXT_SUG_FRONT = 0,
    NEXT_SUG_LEFT,
    NEXT_SUG_RIGHT,
    NEXT_SUG_ARRIVE,
};


@interface IDRNaviSuggestion : NSObject

@property(nonatomic, assign) bool validate;//YES时，所有属性有效

@property(nonatomic, assign) float serialdist;//当前路径的长度

@property(nonatomic, assign) float errordist;//错误距离长度

@property(nonatomic, assign) float nextserialdist;//下一段路径的长度

@property(nonatomic) int segindex;//路径索引

@property(nonatomic) enum CurrentSuggestion curSuggestion;//当前路径建议

@property(nonatomic) enum NextSuggestion nextSuggestion;//下一段路径建议

@property(nonatomic) float totalDis;//导航剩余距离

/**
 获取格式化提示字符串，例如:直行10米，左转15米

 @return 提示字符串
 */
- (NSAttributedString*)getNaviStatusText;

@end
