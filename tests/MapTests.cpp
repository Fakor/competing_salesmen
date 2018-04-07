#include <gtest/gtest.h>

#include "test_tools.h"

#include "map.h"

TEST(MapTest, testAddCity){
    Map map;

    map.AddCities({{2,3}, {1,5}});

    EXPECT_EQ(2, map.NrOfCities());

    testPoint({2,3}, map.CityLocation(0));
    testPoint({1,5}, map.CityLocation(1));
}
