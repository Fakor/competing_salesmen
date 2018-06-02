#include <gtest/gtest.h>

#include <map>
#include <initializer_list>

#include "test_tools.h"

#include "basic_selectors.h"
#include "custom_generator.h"
#include "salesman.h"
#include "map.h"
#include "engine.h"

TEST(EngineTest, PerformTurn){
  std::unique_ptr<CustomGenerator> generator(new CustomGenerator{{{0.0,6.0}, {-3.0,0.0}, {5.0,1.0}}, {{1.0,0.0}, {-8.0,0.0}}});

  Engine engine{std::move(generator)};
  Salesman& salesman = engine.GetSalesman(0);
  Salesman& salesman2 = engine.GetSalesman(1);

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
  std::unique_ptr<CustomGenerator> generator(new CustomGenerator{{{0.0,6.0}, {-3.0,0.0}, {5.0,1.0}}, {{1.0,0.0}, {-8.0,0.0}}});
  Engine engine{std::move(generator)};
  Salesman& salesman = engine.GetSalesman(0);
  Salesman& salesman2 = engine.GetSalesman(1);

  engine.AddSelector(std::unique_ptr<Selector>(new Closest()), 0);
  engine.AddSelector(std::unique_ptr<Selector>(new Closest()), 1);
  engine.PerformRound();
  Scoreboard& scoreboard = engine.GetScoreboard();

  EXPECT_EQ(2, scoreboard[&salesman]);
  EXPECT_EQ(1, scoreboard[&salesman2]);
  EXPECT_TRUE(engine.RoundFinnished());
}
