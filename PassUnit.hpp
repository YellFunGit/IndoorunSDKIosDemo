//
//  PassUnit.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef PassUnit_hpp
#define PassUnit_hpp

#include <stdio.h>
#include <string>
#include "Position.hpp"

/**
 * 贯通节点数据
 *
 * @author Administrator
 *
 */
class PassUnit:public Comparable {

private:
    int floorIndex;// 楼层下标
    int unitTypeId; // 0:自定义类型;1:自动扶梯;2:电梯;3:卫生间;4:取款机;5:出口;6:点状图标;7:入口;8:安全出口;9:楼梯;10:洗车;11:收费处;12:区域
    std::string unitId;
    Position pos;// 节点坐标
    
public:
    int getFloorIndex() {
        
        return floorIndex;
    }
    
    void setFloorIndex(int floorIndex) {
        
        this->floorIndex = floorIndex;
    }
    
    int getUnitTypeId() {
        return unitTypeId;
    }
    
    void setUnitTypeId(int unitTypeId) {
        this->unitTypeId = unitTypeId;
    }
    
    Position getPos() {
        return pos;
    }
    
    void setPos(Position pos) {
        this->pos = pos;
    }
    
    std::string getUnitId() {
        return unitId;
    }
    
    void setUnitId(std::string unitId) {
        this->unitId = unitId;
    }
    
public:
    int compareTo(Comparable* obj) {
        
        PassUnit *o = (PassUnit*)obj;
        if (!o) {
            
            return 0;
        }
        
        if (this->getFloorIndex() < o->getFloorIndex()) {
            return -1;
        } else if (this->getFloorIndex() > o->getFloorIndex()) {
            return 1;
        } else if (this->getPos().getX() < o->getPos().getX()) {
            return -1;
        } else if (this->getPos().getX() > o->getPos().getX()) {
            return 1;
        } else if (this->getPos().getY() < o->getPos().getY()) {
            return -1;
        } else if (this->getPos().getY() > o->getPos().getY()) {
            return 1;
        } else {
            return 0;
        }
    }
    
    virtual bool equals(const Comparable* obj) {
        
        return false;
    }
};


#endif /* PassUnit_hpp */
