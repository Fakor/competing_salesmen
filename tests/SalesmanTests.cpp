#include <gtest/gtest.h>

#include "salesman.h"

#include "test_tools.h"

TEST(SalesmanTest, testMoveTowards) {
    Salesman salesman{1, 2};

    salesman.MoveTowards({4,6}, 2.5);

    testPoint(salesman, {2.5, 4});
}

