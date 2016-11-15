//
//  PathLengthPreIndex.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef PathLengthPreIndex_hpp
#define PathLengthPreIndex_hpp

#include <stdio.h>
#include "Position.hpp"

/**
 * 邻接矩阵单元
 * @author Administrator
 *
 */
class PathLengthPreIndex {
    
private:
    double length;//路径长度
    int proIndex;//前驱节点
    
public:
    PathLengthPreIndex() {
        
        length = -1;
    }
    
    bool isValid() {
        
        return length != -1;
    }
    
    double getLength() {
        return length;
    }
    
    void setLength(double length) {
        this->length = length;
    }
    
    int getProIndex() {
        return proIndex;
    }
    
    void setProIndex(int proIndex) {
        this->proIndex = proIndex;
    }
    
    PathLengthPreIndex(double length, int proIndex) {
        
        this->length = length;
        this->proIndex = proIndex;
    }
};


#endif /* PathLengthPreIndex_hpp */
