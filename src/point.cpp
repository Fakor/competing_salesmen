#include "point.h"

Point::Point(double x_init, double y_init)
: x{x_init}, y{y_init}
{}

double Point::GetX() const {
    return x;
}

double Point::GetY() const {
    return y;
}

double Point::DistanceTo(const Point& target) const{
    double x_mag = target.GetX() - x;
    double y_mag = target.GetY() - y;

    return std::sqrt(x_mag*x_mag+y_mag*y_mag);
}

Point Point::DirectionTo(const Point& target) const{
    return {1,2};
}
