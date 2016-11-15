//
//  PathStructure.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef PathStructure_hpp
#define PathStructure_hpp

#include <stdio.h>
#include <vector>
#include "Segment.hpp"
#include "Position.hpp"
#include "PathLengthPreIndex.hpp"

/**
 * 楼层路径数据
 * @author Administrator
 *
 */
class PathStructure {
    
private:
    std::vector<Segment> lines;//线段集合
    std::vector<Position> positions;//节点集合
    PathLengthPreIndex** matrix;//邻接矩阵
    
public:
    std::vector<Segment> getLines() {
        return lines;
    }
    
    void setLines(std::vector<Segment>& lines) {
        this->lines = lines;
    }
    
    std::vector<Position> getPositions() {
        return positions;
    }
    
    void setPositions(std::vector<Position>& positions) {
        this->positions = positions;
    }
    
    PathLengthPreIndex** getMatrix() {
        return matrix;
    }
    
    void setMatrix(PathLengthPreIndex** matrix) {
        this->matrix = matrix;
    }
    
};


#endif /* PathStructure_hpp */
