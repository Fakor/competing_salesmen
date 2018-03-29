#include <gtest/gtest.h>

#include <cmath>

#include "point.h"

void testPoint(Point p1, Point p2) {
    EXPECT_DOUBLE_EQ(p1.GetX(), p2.GetX());
    EXPECT_DOUBLE_EQ(p1.GetY(), p2.GetY());
}

TEST(PointTest, testDistanceTo){
    Point p{1, 2};
    
    double distance = p.DistanceTo({4,6});

    EXPECT_DOUBLE_EQ(5, distance);
}

TEST(PointTest, testDirectionTo){
    Point p1{0,2};
    Point p2{-1, 4};

    Point d1 = p1.DirectionTo(p2);

    EXPECT_DOUBLE_EQ(-1/sqrt(5), d1.GetX());
    EXPECT_DOUBLE_EQ(2/sqrt(5), d1.GetY());

    Point d2 = p2.DirectionTo(p1);

    EXPECT_DOUBLE_EQ(1/sqrt(5), d2.GetX());
    EXPECT_DOUBLE_EQ(-2/sqrt(5), d2.GetY());
}
