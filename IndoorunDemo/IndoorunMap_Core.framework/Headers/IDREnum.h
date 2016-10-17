//
//  YFTCEnum.h
//  YFTools
//
//  Created by Sincere on 15/8/13.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#ifndef YFTools_YFTCEnum_h
#define YFTools_YFTCEnum_h

/**
 * 数据上传模式
 */
typedef enum {
    YFUpLoadModeTotal  = 0,              /// 整体上传
    YFUpLoadModeSingle = 1               /// 单条上传
} YFUpLoadMode;

/**
 * 路线状态
 */
typedef enum {
    IDRLineStateNormal    = 0,            // 未采集
    IDRLineStateCollected = 1,            // 已采集 未上传
    IDRLineStateUploaded  = 2,            // 已上传
}IDRLineState;

/**
 *  采集界面供功能按钮
 */
typedef enum {
    YFFunctionTypeSelect = 0,          /// 选择
    YFFunctionTypeDelete = 1,             /// 删除
    YFFunctionTypeStart  = 2,             /// 开始
    YFFunctionTypeStop   = 3,             /// 暂停
    YFFunctionTypeEnd    = 4              /// 结束
}YFFunctionType;

/**
 *  点击屏幕时选择线段和点的枚举
 */
typedef enum {
     YFTapTypeLine  = 0,                /// 选择点
     YFTapTypePoint = 1                 /// 选择线
}YFTapType;

typedef enum{
    IDRPositionStateUnCollected       = 0,
    IDRPositionStateCollected         = 1,
    IDRPositionStateStartPosition     = 2,
    IDRPositionStateEndPosition       = 3
}IDRPositionState;

#endif
