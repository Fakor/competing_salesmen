#include <gtest/gtest.h>

#include <cmath>

#include "point.h"
#include "test_tools.h"

TEST(PointTest, testDistanceTo){
    Point p{1, 2};
    
    double distance = p.DistanceTo({4,6});

    EXPECT_DOUBLE_EQ(5, distance);
}

TEST(PointTest, testDirectionTo){
    Point p1{0,2};
    Point p2{-1, 4};

    Point d1 = p1.DirectionTo(p2);

    testPoint({-1/sqrt(5), 2/sqrt(5)}, d1);

    Point d2 = p2.DirectionTo(p1);

    testPoint({1/sqrt(5), -2/sqrt(5)}, d2);
}
