//
//  PositionDistance.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef PositionDistance_hpp
#define PositionDistance_hpp

#include <stdio.h>
#include "Position.hpp"

/**
 * 点和距离的组合
 * @author Administrator
 *
 */
class PositionDistance {
private:
    Position position;
    double distance;
    
public:
    Position getPosition() {
        return position;
    }
    void setPosition(Position position) {
        this->position = position;
    }
    double getDistance() {
        return distance;
    }
    void setDistance(double distance) {
        this->distance = distance;
    }
    
};

#endif /* PositionDistance_hpp */
