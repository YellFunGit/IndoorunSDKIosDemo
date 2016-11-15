//
//  RegionPath.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef RegionPath_hpp
#define RegionPath_hpp

#include <stdio.h>

#include "PathStructure.hpp"
#include "ThroughPathStructure.hpp"

/**
 * Region完整路径数据
 * @author Administrator
 *
 */
class RegionPath {
private:
    std::vector<PathStructure> floorPath;//楼层路径数据
    ThroughPathStructure footPath;//人行贯通路径数据
    ThroughPathStructure carPath;//车行贯通路径数据
    
public:
    std::vector<PathStructure> getFloorPath() {
        return floorPath;
    }
    void setFloorPath(const std::vector<PathStructure>& floorPath) {
        this->floorPath = floorPath;
    }
    ThroughPathStructure getFootPath() {
        return footPath;
    }
    void setFootPath(ThroughPathStructure footPath) {
        this->footPath = footPath;
    }
    ThroughPathStructure getCarPath() {
        return carPath;
    }
    void setCarPath(ThroughPathStructure carPath) {
        this->carPath = carPath;
    }
    
};


#endif /* RegionPath_hpp */
