#ifndef PP_H
#define PP_H

#include <cmath>

class Point {
    public:
        Point(double x_init, double y_init);

        double GetX() const;
        double GetY() const; 
        
        double DistanceTo(const Point& target) const;
        Point DirectionTo(const Point& target) const;
    protected:
        double x;
        double y;
};
 
#endif /* PP_H */
