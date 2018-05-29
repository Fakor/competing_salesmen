#include <gtest/gtest.h>

#include <map>

#include "test_tools.h"

#include "basic_selectors.h"
#include "salesman.h"
#include "map.h"
#include "engine.h"

TEST(EngineTest, PerformTurn){
    Map map;
    
    map.AddCities({{0,6}, {-3,0}, {5,1}});
    map.AddSalesman({1,0});
    map.AddSalesman({-8,0});

    Engine engine{map};

    Salesman& salesman = *map.GetSalesman(0);
    Salesman& salesman2 = *map.GetSalesman(1);

    engine.AddSelector(std::unique_ptr<Selector>(new Closest()), 0);
    engine.AddSelector(std::unique_ptr<Selector>(new Closest()), 1);

    engine.PerformTurn();
    EXPECT_FALSE(engine.RoundFinnished());
    EXPECT_TRUE(testPoint({-3,0}, salesman));
    EXPECT_TRUE(testPoint({-4,0}, salesman2));

    Scoreboard& scoreboard = engine.GetScoreboard();
    EXPECT_EQ(1, scoreboard[&salesman]);
    EXPECT_EQ(0, scoreboard[&salesman2]);

    engine.PerformTurn();
    EXPECT_FALSE(engine.RoundFinnished());
    EXPECT_TRUE(testPoint({0,6}, salesman));
    EXPECT_TRUE(testPoint({-0.2789,5.58156}, salesman2));

    EXPECT_EQ(2, scoreboard[&salesman]);
    EXPECT_EQ(0, scoreboard[&salesman2]);

    engine.PerformTurn();
    EXPECT_TRUE(engine.RoundFinnished());
    EXPECT_TRUE(testPoint({4.94257,1.05742}, salesman));
    EXPECT_TRUE(testPoint({5,1}, salesman2));

    EXPECT_EQ(2, scoreboard[&salesman]);
    EXPECT_EQ(1, scoreboard[&salesman2]);   
}

TEST(EngineTest, PerformRound){
    Map map;

    map.AddCities({{0,6}, {-3,0}, {5,1}});
    map.AddSalesman({1,0});
    map.AddSalesman({-8,0});

    Engine engine{map};

    Salesman& salesman = *map.GetSalesman(0);
    Salesman& salesman2 = *map.GetSalesman(1);

    engine.AddSelector(std::unique_ptr<Selector>(new Closest()), 0);
    engine.AddSelector(std::unique_ptr<Selector>(new Closest()), 1);
    engine.PerformRound();
    Scoreboard& scoreboard = engine.GetScoreboard();

    EXPECT_EQ(2, scoreboard[&salesman]);
    EXPECT_EQ(1, scoreboard[&salesman2]);
    EXPECT_TRUE(engine.RoundFinnished());
}
