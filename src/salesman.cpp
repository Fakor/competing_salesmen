#include "salesman.h"

Salesman::Salesman(double init_x, double init_y)
: Point{init_x, init_y}
{}

void Salesman::MoveTowards(const Point& target, double distance){
    Point direction = DirectionTo(target);
    x += direction.X() * distance;
    y += direction.Y() * distance;
}
