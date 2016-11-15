//
//  Comparable.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef Comparable_hpp
#define Comparable_hpp

#include <stdio.h>

class Comparable {
    
public:
    
    virtual bool equals(const Comparable* obj) = 0;
    
    virtual int compareTo(Comparable* o);
};

#endif /* Comparable_hpp */
