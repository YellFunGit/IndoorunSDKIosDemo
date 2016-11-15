//
//  PathUtil.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef PathUtil_hpp
#define PathUtil_hpp

#include <stdio.h>
#include "Position.hpp"
#include "PositionDistance.hpp"
#include "Segment.hpp"
#include <vector>
#include "math.h"

#define DOUBLE_MAX_VALUE 999999999999

class PathUtil {
    /**
     * 在线段集合中找到距离目标点最近的线段
     *
     * @param p目标点
     * @return 线段index
     */
public:
    static int findNearestLine(Position p, std::vector<Segment>& lines) {
        int index = 0;
        double minDes = DOUBLE_MAX_VALUE;
        for (long i = lines.size() - 1; i >= 0; i--) {
            double des = PathUtil::p2lDes(p, lines[i]).getDistance();
            if (des < minDes) {
                index = i;
                minDes = des;
            }
        }
        return index;
    }
    
    /**
     * 二分查找点在有序集合中的位置下标
     *
     * @param pos待查找点
     * @param positions点集
     * @return pos在positions中的下标，若找不到返回-1
     */
public:
    static int findPositionIndex(Position pos, std::vector<Position>& positions) {
        int left = 0;
        int right = positions.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            int t = pos.compareTo(&positions[mid]);
            if (t < 0) {
                right = mid - 1;
            } else if (t == 0) {
                return mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
    
    /**
     * 求两点间欧氏距离
     *
     * @param a点A
     * @param b点B
     * @return AB间欧式距离
     */
public:
    static double p2pDes(Position a, Position b) {
        
        return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
    }
    
    /**
     * 求点到线段的最短距离及其端点
     *
     * @param p点
     * @param l线段
     * @return 最短距离及其端点
     */
public:
    static PositionDistance p2lDes(Position p, Segment l) {
        return p2lDes(p.getX(), p.getY(), l.getEndPointOne().getX(), l.getEndPointOne().getY(),
                      l.getEndPointTwo().getX(), l.getEndPointTwo().getY());
    }
    
    /**
     * 求点到线段的最短距离及其端点
     *
     * @param x点横坐标
     * @param y点纵坐标
     * @param x1线段端点1横坐标
     * @param y1线段端点1纵坐标
     * @param x2线段端点2横坐标
     * @param y2线段端点2纵坐标
     * @return 最短距离及其端点
     */
public:
    static PositionDistance p2lDes(double x, double y, double x1, double y1, double x2, double y2) {
        double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
        if (cross <= 0)
            return getPositionDistance(x, y, x1, y1);
        double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        if (cross >= d2)
            return getPositionDistance(x, y, x2, y2);
        double r = cross / d2;
        double px = x1 + (x2 - x1) * r;
        double py = y1 + (y2 - y1) * r;
        return getPositionDistance(x, y, px, py);
    }
    
private:
    static PositionDistance getPositionDistance(double x, double y, double px, double py) {
        PositionDistance result;
        Position p;
        p.setX(px);
        p.setY(py);
        result.setPosition(p);
        result.setDistance(sqrt((x - px) * (x - px) + (y - py) * (y - py)));
        return result;
    }
};


#endif /* PathUtil_hpp */
