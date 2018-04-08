#include "salesman.h"

Salesman::Salesman(double init_x, double init_y)
: Point{init_x, init_y}
{}

void Salesman::SetTarget(Point const *target){
    target_ = target;
}

void Salesman::MoveTowardsTarget(double distance){
    Point direction = DirectionTo(*target_);
    x += direction.X() * distance;
    y += direction.Y() * distance;
}

double Salesman::DistanceToTarget() const{
    return DistanceTo(*target_);
}
