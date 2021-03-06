#ifndef POINT_H
#define POINT_H

#include <cmath>

class Point {
    public:
        Point(double x_init, double y_init);

        double GetX() const;
        double GetY() const;

	void MoveTo(const Point& target);
	void MoveTowards(const Point& target, double distance);

        double DistanceTo(const Point& target) const;
        Point DirectionTo(const Point& target) const;

        bool operator ==(const Point& other) const;
    protected:
        double x;
        double y;
};
 
#endif
