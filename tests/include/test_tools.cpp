#include "test_tools.h"

::testing::AssertionResult testPoint(const Point& p1, const Point& p2) {
    bool x_same = std::abs(p1.X()-p2.X()) < EPSILON;
    bool y_same = std::abs(p1.Y()-p2.Y()) < EPSILON;
    if(x_same && y_same){
        return ::testing::AssertionSuccess();
    }
    else{
        return ::testing::AssertionFailure() << "[" << p1.X() << ", " << p1.Y() << "] != ""[" << p2.X() << ", " << p2.Y() << "]";
    }
}

