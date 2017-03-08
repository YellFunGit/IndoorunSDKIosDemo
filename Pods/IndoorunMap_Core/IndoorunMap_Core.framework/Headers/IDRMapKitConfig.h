//
//  IDRMapKitConfig.h
//  YFMapKit
//
//  Created by ky on 16/5/18.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>

#define IDR_VERSION 2.4.0

#define IDRRegionData IDRRegionEx

#define kScreenWidth  [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height

#define PhoneUUID [[[UIDevice currentDevice] identifierForVendor] UUIDString]

typedef NS_ENUM(NSInteger, IDRMapMode) {
    
    IDRMapMode_ModeFree,//自由模式，不跟随userlocation
    
    IDRMapMode_ModeTrace,//定位模式，跟随userlocation，自动切换楼层，userlocation跑出屏幕，地图会自动调整
    
    IDRMapMode_ModeFollowing,//跟随模式(1:非导航时地图随方位角旋转；2:导航时地图随导航线旋转)
};

typedef NS_ENUM(NSInteger, IDRMapDisplayMode) {
    
    IDRMap_2D,//普通2d地图
    
    IDRMap_3D,//地图3d显示
    
    IDRMap_AR,//地图3d && ar显示
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
    
    UnitType_AnQuanChuKou = 8,//安全出口
    
    UnitType_LouTi        = 9,//楼梯
    
    UnitType_XiCheChu     = 10,//洗车处
    
    UnitType_ShouFeiChu   = 11,//收费处
    
    UnitType_QuYu         = 12,//区域
};

typedef NS_ENUM(NSInteger, OfflineDataStatus) {
    
    OfflineDataStatus_needDownload,
    
    OfflineDataStatus_needUpdate,
    
    OfflineDataStatus_newest,
};

@interface IDRMapKitConfig : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, assign) LocateType locateType;//定位方式

@property (nonatomic, assign) BOOL showNaviLine;//显示导航直线

@property (nonatomic, assign) BOOL enableLog;//是否打印log

//-------以下为url地址，不建议自行改动
@property (nonatomic, assign) BOOL formalServer;//是否正式服务器

@property (nonatomic, copy) NSString *session_url;

@property (nonatomic, copy) NSString *login_url;

@property (nonatomic, copy) NSString *regionsOfUser_url;

@property (nonatomic, copy) NSString *locate_url;

@property (nonatomic, copy) NSString *stopLocate_url;

@property (nonatomic, copy) NSString *preLocate_url;

@property (nonatomic, copy) NSString *mutilocating_url;

@property (nonatomic, copy) NSString *regionZip_url;

@property (nonatomic, copy) NSString *appBoundleId;
//--------

@end
