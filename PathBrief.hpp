//
//  PathBrief.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef PathBrief_hpp
#define PathBrief_hpp

#include <stdio.h>
#include "Position.hpp"

/**
 * 简略路径结果
 *
 * @author Administrator
 *
 */
class PathBrief {

private:
    Position p1;//起点，当为null时表示起点与投影点过近，可忽略
    Position p2;//终点，当为null时表示起点与投影点过近，可忽略
    Position ps;//起点到最短路径的投影点
    Position pe;//终点到最短路径的投影点
    int f;//对应楼层，-1表示人行贯通，-2表示车行贯通
    int a;//邻接矩阵中的起点，若为-1表示ps、pe在一条线上无需中继点
    int b;//邻接矩阵中的终点
    double distance;//路径距离
    
public:
    
    bool isValid() {
        
        return distance != -1;
    }
    
    PathBrief() {
        
        distance = -1;
    }
    
    Position getP1() {
        return p1;
    }
    void setP1(Position p1) {
        this->p1 = p1;
    }
    Position getP2() {
        return p2;
    }
    void setP2(Position p2) {
        this->p2 = p2;
    }
    Position getPs() {
        return ps;
    }
    void setPs(Position ps) {
        this->ps = ps;
    }
    Position getPe() {
        return pe;
    }
    void setPe(Position pe) {
        this->pe = pe;
    }
    int getF() {
        return f;
    }
    void setF(int f) {
        this->f = f;
    }
    int getA() {
        return a;
    }
    void setA(int a) {
        this->a = a;
    }
    int getB() {
        return b;
    }
    void setB(int b) {
        this->b = b;
    }
    double getDistance() {
        return distance;
    }
    void setDistance(double distance) {
        this->distance = distance;
    }
    
};


#endif /* PathBrief_hpp */
