#include <gtest/gtest.h>

#include "test_tools.h"

#include "map.h"

TEST(MapTest, testAddCity){
    Map map;

    map.AddCities({{2,3}, {1,5}});

    EXPECT_EQ(2, map.NrOfCities());
}

TEST(MapTest, testAddSalesman){
    Map map;

    map.AddSalesman({{1,4},{2,5},{3,6}});

    EXPECT_EQ(3, map.NrOfSalesman());
}
