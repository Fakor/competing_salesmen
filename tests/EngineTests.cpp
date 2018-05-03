#include <gtest/gtest.h>

#include "test_tools.h"

#include "basic_selectors.h"
#include "salesman.h"
#include "map.h"
#include "engine.h"

TEST(EngineTest, Closest){
    Map map;
    
    map.AddCities({{0,6}, {-3,0}, {5,1}});
    map.AddSalesman({1,0});

    Engine engine{map};

    std::unique_ptr<Selector> selector(new Closest());

    Salesman& salesman = *map.GetSalesman(0);

    engine.AddSelector(std::unique_ptr<Selector>(new Closest()), 0);

    engine.PerformTurn();
    testPoint({-3,0}, salesman);

    engine.PerformTurn();
    testPoint({0,6}, salesman);
}
