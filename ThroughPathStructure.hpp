//
//  ThroughPathStructure.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef ThroughPathStructure_hpp
#define ThroughPathStructure_hpp

#include <stdio.h>
#include <vector>
#include "PassUnit.hpp"
#include "PathLengthPreIndex.hpp"

/**
 * 贯通路径数据
 * @author Administrator
 *
 */
class ThroughPathStructure {
    
private:
    std::vector<PassUnit> positions;//节点集合
    PathLengthPreIndex** matrix;//邻接矩阵
    
public:
    std::vector<PassUnit> getPositions() {
        return positions;
    }
    
    void setPositions(const std::vector<PassUnit>& positions) {
        this->positions = positions;
    }
    
    PathLengthPreIndex** getMatrix() {
        return matrix;
    }
    
    void setMatrix(PathLengthPreIndex** matrix) {
        this->matrix = matrix;
    }
    
};

#endif /* ThroughPathStructure_hpp */
