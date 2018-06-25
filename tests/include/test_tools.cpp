#include "test_tools.h"

::testing::AssertionResult testPoint(const Point& p1, const Point& p2) {
    bool x_same = std::abs(p1.GetX()-p2.GetX()) < EPSILON;
    bool y_same = std::abs(p1.GetY()-p2.GetY()) < EPSILON;
    if(x_same && y_same){
        return ::testing::AssertionSuccess();
    }
    else{
        return ::testing::AssertionFailure() << "[" << p1.GetX() << ", " << p1.GetY() << "] != ""[" << p2.GetX() << ", " << p2.GetY() << "]";
    }
}

::testing::AssertionResult testPoint(const Point& p1, const Salesman& s1){
  return testPoint(p1, s1.GetPosition());
}

