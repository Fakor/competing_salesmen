#ifndef TEST_TOOLS_H
#define TEST_TOOLS_H

#include <gtest/gtest.h>

#include "point.h"
 
constexpr double EPSILON = 0.0001;

::testing::AssertionResult testPoint(const Point& p1, const Point& p2);

#endif /* TEST_TOOLS_H */
