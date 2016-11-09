//
//  IDRMapKitConfig.h
//  YFMapKit
//
//  Created by ky on 16/5/18.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>

#define IDR_VERSION 2.1.0

#define kScreenWidth  [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height

typedef NS_ENUM(NSInteger, IDRMapMode) {
    
    /**
     *  自由模式，不跟随userlocation
     */
    IDRMapMode_ModeFree,
    /**
     *  定位模式，跟随userlocation，自动切换楼层，userlocation跑出屏幕，地图会自动调整
     */
    IDRMapMode_ModeTrace,
    /**
     *  跟随模式(1:非导航时地图随方位角旋转；2:导航时地图随导航线旋转)
     */
    IDRMapMode_ModeFollowing,
};

typedef NS_ENUM(NSInteger, LocateType){
    
    LocateType_mix,//混合(优先使用在线定位，若失败则使用离线定位)
    
    LocateType_online,//在线
    
    LocateType_offline,//离线
};

typedef NS_ENUM(NSInteger, UnitType) {
    
    UnitType_None         = 0,
    
    UnitType_FuTi         = 1,//"扶梯"
    
    UnitType_DianTi       = 2,//电梯
    
    UnitType_XiShouJian   = 3,//洗手间
    
    UnitType_ATM          = 4,//ATM取款机
    
    UnitType_ChuKou       = 5,//出口
    
    UnitType_RuKou        = 7,//入口
    
    UnitType_LouTi        = 9,//楼梯
    
    UnitType_ShouFeiChu   = 11,//收费处
};

typedef NS_ENUM(NSInteger, OfflineDataStatus) {
    
    OfflineDataStatus_needDownload,
    
    OfflineDataStatus_needUpdate,
    
    OfflineDataStatus_newest,
};

@interface IDRMapKitConfig : NSObject

+ (instancetype)sharedInstance;

/**
 *  定位方式
 */
@property (nonatomic, assign) LocateType locateType;

/**
 *  显示导航直线
 */
@property (nonatomic, assign) BOOL showNaviLine;

/**
 *  是否打印log
 */
@property (nonatomic, assign) BOOL enableLog;

@end
