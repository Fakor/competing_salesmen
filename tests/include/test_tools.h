#ifndef TEST_TOOLS_H
#define TEST_TOOLS_H

#include <gtest/gtest.h>

#include "point.h"
#include "salesman.h"
 
constexpr double EPSILON = 0.0001;

::testing::AssertionResult testPoint(const Point& p1, const Point& p2);
::testing::AssertionResult testPoint(const Point& p1, const Salesman& s1);

#endif /* TEST_TOOLS_H */
