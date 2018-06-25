#ifndef SALESMAN_H
#define SALESMAN_H

#include <optional>

#include "point.h"

class Salesman{
    public:
        Salesman(double init_x, double init_y);
    
        void SetTarget(const Point *target);
        void MoveToTarget();
        void MoveTowardsTarget(double distance);
        std::optional<double> DistanceToTarget() const;
	double DistanceTo(const Point& other_point) const;
        const Point* GetTarget() const;
	Point GetPosition() const;

	void AddScore();
	int GetScore() const;
    private:
        Point const *target_{nullptr};
	int score_{0};
	Point position_;
};
 
#endif
