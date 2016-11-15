//
//  FloorPath.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef FloorPath_hpp
#define FloorPath_hpp

#include <stdio.h>
#include <list>
#include "Position.hpp"

class FloorPath {
    
private:
    int floorIndex;// 路径所在楼层
    int typeId;// 路径终点类型，0为终点，其余参考unitTypeId，分别表示楼梯、电梯等
    double distance;// 路线距离
    std::list<Position> position;// 路线点集
    
public:
    int getFloorIndex() {
        
        return floorIndex;
    }
    
    void setFloorIndex(int floorIndex) {
        
        this->floorIndex = floorIndex;
    }
    
    int getTypeId() {
        
        return typeId;
    }
    
    void setTypeId(int typeId) {
        
        this->typeId = typeId;
    }
    
    double getDistance() {
        
        return distance;
    }
    
    void setDistance(double distance) {
        
        this->distance = distance;
    }
    
    std::list<Position> getPosition() {
        return position;
    }
    
    void setPosition(std::list<Position> position) {
        this->position = position;
    }
};

#endif /* FloorPath_hpp */
