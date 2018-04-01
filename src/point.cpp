#include "point.h"

Point::Point(double x_init, double y_init)
: x{x_init}, y{y_init}
{}

double Point::X() const {
    return x;
}

double Point::Y() const {
    return y;
}

double Point::DistanceTo(const Point& target) const{
    double x_mag = target.x - x;
    double y_mag = target.y - y;

    return std::sqrt(x_mag*x_mag+y_mag*y_mag);
}

Point Point::DirectionTo(const Point& target) const{
    double x_mag = target.x - x;
    double y_mag = target.y - y;
    double distance = DistanceTo(target);
    return {x_mag/distance, y_mag/distance};
}
