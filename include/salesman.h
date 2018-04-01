#ifndef SALESMAN_H
#define SALESMAN_H

#include <cmath>

#include "point.h"

class Salesman: public Point{
    public:
        Salesman(double init_x, double init_y);
    
        void MoveTowards(const Point& target, double distance);
};
 
#endif
