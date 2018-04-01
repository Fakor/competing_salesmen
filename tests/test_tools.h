#ifndef TEST_TOOLS_H
#define TEST_TOOLS_H

#include <gtest/gtest.h>
 
void testPoint(Point p1, Point p2) {
    EXPECT_DOUBLE_EQ(p1.X(), p2.X());
    EXPECT_DOUBLE_EQ(p1.Y(), p2.Y());
}

#endif /* TEST_TOOLS_H */
