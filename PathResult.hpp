//
//  PathResult.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef PathResult_hpp
#define PathResult_hpp

#include <stdio.h>
#include <list>
#include "Position.hpp"
#include "FloorPath.hpp"

/**
 * 完整路径结果
 * @author Administrator
 *
 */
class PathResult {
private:
    std::list<FloorPath> paths;//每段路径数据
    double distance;//全路径的总距离
    
public:
    std::list<FloorPath> getPaths() {
        return paths;
    }
    void setPaths(std::list<FloorPath> paths) {
        this->paths = paths;
    }
    double getDistance() {
        return distance;
    }
    void setDistance(double distance) {
        this->distance = distance;
    }
    
};


#endif /* PathResult_hpp */
