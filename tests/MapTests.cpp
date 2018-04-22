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

TEST(MapTest, testMoveSalesmen){
    Map map;

    Salesman s1{0,1};
    Salesman s2{0,3};
    Salesman s3{0,-2};

    map.AddSalesman(&s1);
    map.AddSalesman(&s2);
    map.AddSalesman(&s3);

    map.AddCities({{0,0}});
    s1.SetTarget(&map.AllCities()[0]);
    s2.SetTarget(&map.AllCities()[0]);
    s3.SetTarget(&map.AllCities()[0]);

    map.MoveSalesmen();

    testPoint({0,0}, s1);
    testPoint({0,2}, s2);
    testPoint({0,-1}, s3);
}

TEST(MapTest, testMoveSalesmenDifferentTargets){
    Map map;

    Salesman s1{4,0};
    Salesman s2{5,1};

    map.AddSalesman(&s1);
    map.AddSalesman(&s2);

    map.AddCities({{0,0}, {7,1}});
    s1.SetTarget(&map.AllCities()[0]);
    s2.SetTarget(&map.AllCities()[1]);

    map.MoveSalesmen();

    testPoint({2,0}, s1);
    testPoint({7,1}, s2);
}
