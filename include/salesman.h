#ifndef SALESMAN_H
#define SALESMAN_H

#include <optional>

#include "point.h"

class Salesman: public Point{
    public:
        Salesman(double init_x, double init_y);
    
        void SetTarget(const Point *target);
        void MoveToTarget();
        void MoveTowardsTarget(double distance);
        std::optional<double> DistanceToTarget() const;
        const Point* GetTarget() const;
    private:
        Point const *target_{nullptr};
};
 
#endif
