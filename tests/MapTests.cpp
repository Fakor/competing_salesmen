#include <gtest/gtest.h>

#include "test_tools.h"

#include "map.h"

TEST(MapTest, testAddCity){
    Map map;

    map.AddCities({{2,3}, {1,5}});

    EXPECT_EQ(2, map.NrOfCities());
}

TEST(MapTest, testAddSalesmen){
    Map map;

    Salesman s1{1,4};
    Salesman s2{2,5};
    Salesman s3{3,6};

    map.AddSalesman(&s1);
    map.AddSalesman(&s2);
    map.AddSalesman(&s3);

    EXPECT_EQ(3, map.NrOfSalesman());
}
