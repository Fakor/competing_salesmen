#ifndef SALESMAN_H
#define SALESMAN_H

#include <optional>

#include "point.h"

class Salesman: public Point{
    public:
        Salesman(double init_x, double init_y);
    
        void SetTarget(Point const *target);
        void MoveTowardsTarget(double distance);
        std::optional<double> DistanceToTarget() const;

    private:
        Point const *target_{nullptr};
};
 
#endif
