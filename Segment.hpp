//
//  Segment.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef Segment_hpp
#define Segment_hpp

#include <stdio.h>
#include "Position.hpp"

class Segment {
private:
    Position endPointOne;
    Position endPointTwo;
    
public:
    Position getEndPointOne() {
        return endPointOne;
    }
    
    void setEndPointOne(Position endPointOne) {
        this->endPointOne = endPointOne;
    }
    
    Position getEndPointTwo() {
        return endPointTwo;
    }
    
    void setEndPointTwo(Position endPointTwo) {
        this->endPointTwo = endPointTwo;
    }
    
};

#endif /* Segment_hpp */
