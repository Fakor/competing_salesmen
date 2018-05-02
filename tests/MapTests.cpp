#include <gtest/gtest.h>

#include "test_tools.h"

#include "map.h"

TEST(MapTest, testAddCity){
    Map map;

    map.AddCities({{2,3}, {1,5}});

    EXPECT_EQ(2, map.NrOfCities());
}

TEST(MapTest, testMapSalesmanDistance){
    Map map;

    map.AddCities({{0,0}});

    map.AddSalesman({2,0});
    map.AddSalesman({3,0});
    map.AddSalesman({1,0});

    map.SetSalesmanTarget(0,0);
    map.SetSalesmanTarget(1,0);
    map.SetSalesmanTarget(2,0);


    auto maped_salesman = map.MapSalesmanDistance();

    auto map_it = maped_salesman.begin();

    EXPECT_DOUBLE_EQ(1, map_it->first);
    testPoint({1,0}, *map_it->second);

    ++map_it;
    EXPECT_DOUBLE_EQ(2, map_it->first);
    testPoint({2,0}, *map_it->second);

    ++map_it;
    EXPECT_DOUBLE_EQ(3, map_it->first);
    testPoint({3,0}, *map_it->second);
}

TEST(MapTest, testUnvisitedCities){
    Map map;

    map.AddCities({{0,0},{1,0},{2,0}});

    auto unvisited_cities = map.GetUnvisitedCities();

    EXPECT_EQ(3, unvisited_cities->size());
    testPoint({0,0}, *unvisited_cities->at(0));
    testPoint({1,0}, *unvisited_cities->at(1));
    testPoint({2,0}, *unvisited_cities->at(2));
    map.VisitCity(1);

    EXPECT_EQ(2, unvisited_cities->size());
    testPoint({0,0}, *unvisited_cities->at(0));
    testPoint({2,0}, *unvisited_cities->at(1));
}
