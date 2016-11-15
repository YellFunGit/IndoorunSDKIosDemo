//
//  Position.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef Position_hpp
#define Position_hpp

#include <stdio.h>
#include "Comparable.hpp"
#include <string>

#define DOUBLE_INVALID_VALUE -99999999999999

class Position:public Comparable {
    
private:
    double x;
    
    double y;
    
public:
    
    bool isValid() {
        
        return x != DOUBLE_INVALID_VALUE;
    }
    
    Position() {
        
        x = DOUBLE_INVALID_VALUE;
    }
    
    double getX() {
        
        return x;
    }
    
    void setX(double x) {
        
        this->x = x;
    }
    
    double getY() {
        
        return y;
    }
    
    void setY(double y) {
        
        this->y = y;
    }
    
    int hashCode() {
        
        return (int) x + (int)y;
    }
    
    bool equals(const Comparable* obj) {
        
        Position* pos = (Position*)obj;
        
        if (!pos) {
            
            return false;
        }
        
        if (this->x != pos->x || this->y != pos->y)
            return false;
        
        return true;
    }
    
    
    int compareTo(Comparable* obj) {
        
        Position* o = (Position*)obj;
        
        if (!o) {
            
            return 0;
        }
        
        if (this->getX() < o->getX()) {
            return -1;
        } else if (this->getX() > o->getX()) {
            return 1;
        } else if (this->getY() < o->getY()) {
            return -1;
        } else if (this->getY() > o->getY()) {
            return 1;
        } else {
            return 0;
        }
    }
    
    
    std::string toString() {
        
        char szText[64] = {0};
        
        sprintf(szText, "%d, %d", (int)x, (int)y);
        
        return szText;
    }
};


#endif /* Position_hpp */
