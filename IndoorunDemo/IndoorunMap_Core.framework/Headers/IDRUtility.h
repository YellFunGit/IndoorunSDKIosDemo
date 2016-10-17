//
//  IDRUtility.h
//  IndoorunMap_Core
//
//  Created by ky on 16/7/27.
//  Copyright © 2016年 yellfun. All rights reserved.
//

#ifndef IDRUtility_h
#define IDRUtility_h

#import <UIKit/UIKit.h>

//CGpoint math
CGPoint pointAddPoint(CGPoint a, CGPoint b);

CGPoint pointMinusPoint(CGPoint a, CGPoint b);

CGPoint operator+(const CGPoint& lhs, const CGPoint& rhs);

CGPoint operator-(const CGPoint& lhs, const CGPoint& rhs);

CGPoint operator*(const CGPoint& lhs, CGFloat scale);

bool operator==(const CGPoint& lhs, const CGPoint& rhs);

CGPoint operator*(const CGPoint& lhs, const CGAffineTransform& tm);

CGFloat lengthOfPoint(const CGPoint& parm);

CGPoint normalOfPoint(const CGPoint& p);

CGFloat retriveNorthAngle(CGPoint p);

#endif /* IDRUtility_h */
