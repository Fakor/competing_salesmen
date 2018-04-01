#include "test_tools.h"

void testPoint(const Point& p1, const Point& p2) {
    EXPECT_DOUBLE_EQ(p1.X(), p2.X());
    EXPECT_DOUBLE_EQ(p1.Y(), p2.Y());
}

