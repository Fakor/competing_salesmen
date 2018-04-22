#include <gtest/gtest.h>

#include "salesman.h"

#include "test_tools.h"

TEST(SalesmanTest, testMoveTowardsTarget) {
    Salesman salesman{1, 2};

    Point target{4,6};
    salesman.SetTarget(&target);
    salesman.MoveTowardsTarget(2.5);

    testPoint(salesman, {2.5, 4});
}

TEST(SalesmanTest, testDistanceToTarget) {
    Salesman salesman{0,0};

    Point target{2,0};
    salesman.SetTarget(&target);

    EXPECT_DOUBLE_EQ(2, salesman.DistanceToTarget().value());
}
