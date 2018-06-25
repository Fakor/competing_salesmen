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

void Point::MoveTo(const Point& target){
  x = target.GetX();
  y = target.GetY();
}

void Point::MoveTowards(const Point& target, double distance){
  Point direction = DirectionTo(target);
  x += direction.GetX() * distance;
  y += direction.GetY() * distance;
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
