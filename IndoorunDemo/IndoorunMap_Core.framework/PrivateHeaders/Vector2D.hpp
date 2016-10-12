//
//  Vector2D.h
//  YFMapKit
//
//  Created by ky on 16/4/14.
//  Copyright © 2016年 Sincere. All rights reserved.
//

#ifndef Vector2D_h
#define Vector2D_h

#include <math.h>


class Vector2D
{
public:
    
    float   x;
    float   y;
    
    Vector2D() {x = 0; y = 0;}
    
    Vector2D(float r, float s)
    {
        x = r;
        y = s;
    }
    
    Vector2D& operator *=(float t)
    {
        x *= t;
        y *= t;
        return (*this);
    }
    
    Vector2D& operator /=(float t)
    {
        float f = 1.0F / t;
        
        x *= f;
        
        y *= f;
        
        return (*this);
    }
    
    Vector2D& operator &=(const Vector2D& v)
    {
        x *= v.x;
        y *= v.y;
        return (*this);
    }
    
    Vector2D operator -(void) const
    {
        return (Vector2D(-x, -y));
    }
    
    Vector2D operator +(const Vector2D& v) const
    {
        return (Vector2D(x + v.x, y + v.y));
    }
    
    Vector2D operator -(const Vector2D& v) const
    {
        return (Vector2D(x - v.x, y - v.y));
    }
    
    Vector2D operator *(float t) const
    {
        return (Vector2D(x * t, y * t));
    }
    
    Vector2D operator /(float t) const
    {
        float f = 1.0F / t;
        
        return (Vector2D(x * f, y * f));
    }
    
    float operator *(const Vector2D& v) const
    {
        return (x * v.x + y * v.y);
    }
    
    Vector2D operator &(const Vector2D& v) const
    {
        return (Vector2D(x * v.x, y * v.y));
    }
    
    bool operator ==(const Vector2D& v) const
    {
        return ((x == v.x) && (y == v.y));
    }
    
    bool operator !=(const Vector2D& v) const
    {
        return ((x != v.x) || (y != v.y));
    }
    
    Vector2D& Normalize(void)
    {
        return (*this /= sqrtf(x * x + y * y));
    }
    
    Vector2D& Rotate(float angle);
    
    float length() { return sqrtf(x * x + y * y); }
    
    float dist(const Vector2D&v);
        
    Vector2D projection(const Vector2D& start, const Vector2D& end);
};

inline Vector2D operator *(float t, const Vector2D& v)
{
    return (Vector2D(t * v.x, t * v.y));
}

inline float Dot(const Vector2D& v1, const Vector2D& v2)
{
    return (v1 * v2);
}

#endif /* Vector2D_h */
