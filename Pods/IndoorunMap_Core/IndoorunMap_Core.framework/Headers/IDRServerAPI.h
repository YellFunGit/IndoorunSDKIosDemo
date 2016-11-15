//
//  IDRServerAPI.h
//  YFMapKit
//
//  Created by ky on 16/5/19.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#ifndef IDRServerAPI_h
#define IDRServerAPI_h

#ifdef DEBUG

#define INTERFACE @"http://test.interface.indoorun.com/ck"
#define LOCATING @"http://test.locating.indoorun.com/IndoorunV2/0/beacons"

#else

#define INTERFACE @"http://interface.indoorun.com/ck"
#define LOCATING @"http://ips.indoorun.com/IndoorunV2/0/beacons"

#endif

//#define APPBundleID [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"]

#define APPBundleID @"com.Yellfun.Cars"

#define PhoneUUID [[[UIDevice currentDevice] identifierForVendor] UUIDString]

#define SESSION_URL       [NSString stringWithFormat:@"%@/initAppSession.html", INTERFACE]

#define LOGIN_URL         [NSString stringWithFormat:@"%@/login.html", INTERFACE]

#define FLOORS_URL        [NSString stringWithFormat:@"%@/getFloorsByRegionId.html", INTERFACE]

#define UNITS_URL         [NSString stringWithFormat:@"%@/getUnitsByFloorId.html", INTERFACE]

#define RegionsOfUser_URL [NSString stringWithFormat:@"%@/getRegionsOfUser.html", INTERFACE]

#define QUYU_URL          [NSString stringWithFormat:@"%@/getQuyuUnitsByFloorId.html", INTERFACE]

#define HEAT_URL          [NSString stringWithFormat:@"%@/getQuyuHeatOfRegion.html", INTERFACE]

#define RegionAllData_URL [NSString stringWithFormat:@"%@/getRegionAllInfo.html", INTERFACE]

#define RegionPassData_URL [NSString stringWithFormat:@"%@/getRegionFloorPassData.html", INTERFACE]

#define OfflineDataUrl     [NSString stringWithFormat:@"%@/getZipLocatingBaseDataOfRegion2.html", INTERFACE]

#define LOCATE_URL         [NSString stringWithFormat:@"%@/locating", LOCATING]

#define STOPLOCATE_URL     [NSString stringWithFormat:@"%@/locating/stop", LOCATING]

#define PRELOCATING_URL    [NSString stringWithFormat:@"%@/preLocating", LOCATING]

#define Mutilocating_URL   [NSString stringWithFormat:@"%@/getMultiLocating", LOCATING]

#define Map_URL            [NSString stringWithFormat:@"%@/getFloorMapVbfZipData.html", INTERFACE]

#define RegionZip_URL     [NSString stringWithFormat:@"%@/downloadZipRegionWholeData.html", INTERFACE]

#endif /* IDRServerAPI_h */
