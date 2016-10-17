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

/**
 建议为YES时候有效
 */
@property(nonatomic, assign) bool validate;

/**
 当前路径的长度
 */
@property(nonatomic, assign) float serialdist;

/**
 错误距离长度
 */
@property(nonatomic, assign) float errordist;

/**
 下一段路径的长度
 */
@property(nonatomic, assign) float nextserialdist;

/**
 路径索引
 */
@property(nonatomic, assign) int segindex;

/**
 当前路径建议
 */
@property(nonatomic, assign) enum CurrentSuggestion curSuggestion;

/**
 下一段路径建议
 */
@property(nonatomic, assign) enum NextSuggestion nextSuggestion;

/**
 获取格式化提示字符串，例如:直行10米，左转15米

 @return 提示字符串
 */
- (NSAttributedString*)getNaviStatusText;

@end
