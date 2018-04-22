#include "salesman.h"

Salesman::Salesman(double init_x, double init_y)
: Point{init_x, init_y}
{}

void Salesman::SetTarget(Point const *target){
    target_ = target;
}

void Salesman::MoveTowardsTarget(double distance){
    if(target_ != nullptr){
        Point direction = DirectionTo(*target_);
        x += direction.X() * distance;
        y += direction.Y() * distance;
    }
}

std::optional<double> Salesman::DistanceToTarget() const{
    if(target_ != nullptr){
        return DistanceTo(*target_);
    }
    return std::nullopt;
}
