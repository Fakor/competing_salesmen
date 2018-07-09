#include <gtest/gtest.h>

#include <map>
#include <initializer_list>

#include "test_tools.h"

#include "basic_selectors.h"
#include "custom_generator.h"
#include "salesman.h"
#include "map.h"
#include "engine.h"

TEST(EngineTest, NotEnoughSelectors){
  std::unique_ptr<CustomGenerator> generator(new CustomGenerator{{{0.0,6.0}, {-3.0,0.0}, {5.0,1.0}}, {{1.0,0.0}, {-8.0,0.0}}});

  Engine engine{std::move(generator)};

  engine.AddSelector(std::unique_ptr<Selector>(new Closest()));

  ASSERT_ANY_THROW(engine.SetupNewRound());
}

TEST(EngineTest, PerformTurn){
  std::unique_ptr<CustomGenerator> generator(new CustomGenerator{{{0.0,6.0}, {-3.0,0.0}, {5.0,1.0}}, {{1.0,0.0}, {-8.0,0.0}}});

  Engine engine{std::move(generator)};

  engine.AddSelector(std::unique_ptr<Selector>(new Closest()));
  engine.AddSelector(std::unique_ptr<Selector>(new Closest()));

  engine.SetupNewRound();

  const std::vector<Salesman>& salesmen = engine.GetSalesmen();
  const Salesman& salesman1 = salesmen.at(0);
  const Salesman& salesman2 = salesmen.at(1);

  engine.PerformTurn();
  EXPECT_FALSE(engine.RoundFinnished());
  EXPECT_TRUE(testPoint({-3,0}, salesman1));
  EXPECT_TRUE(testPoint({-4,0}, salesman2));

  EXPECT_EQ(Scoreboard({1,0}), engine.GetScoreboard());

  engine.PerformTurn();
  EXPECT_FALSE(engine.RoundFinnished());
  EXPECT_TRUE(testPoint({0,6}, salesman1));
  EXPECT_TRUE(testPoint({-0.2789,5.58156}, salesman2));

  EXPECT_EQ(Wins({0,0}), engine.GetWins());

  EXPECT_EQ(Scoreboard({2,0}), engine.GetScoreboard());

  engine.PerformTurn();
  EXPECT_TRUE(engine.RoundFinnished());
  EXPECT_TRUE(testPoint({4.94257,1.05742}, salesman1));
  EXPECT_TRUE(testPoint({5,1}, salesman2));

  EXPECT_EQ(Scoreboard({2,1}), engine.GetScoreboard());
  EXPECT_EQ(Wins({1,0}), engine.GetWins());
}

TEST(EngineTest, PerformRound){
  std::unique_ptr<CustomGenerator> generator(new CustomGenerator{{{0.0,6.0}, {-3.0,0.0}, {5.0,1.0}}, {{1.0,0.0}, {-8.0,0.0}}});

  Engine engine{std::move(generator)};
  const Salesman& salesman = engine.GetSalesmen()[0];
  const Salesman& salesman2 = engine.GetSalesmen()[1];

  engine.AddSelector(std::unique_ptr<Selector>(new Closest()));
  engine.AddSelector(std::unique_ptr<Selector>(new Closest()));

  engine.SetupNewRound();
  engine.PerformRound();

  EXPECT_EQ(Scoreboard({2,1}), engine.GetScoreboard());
  EXPECT_TRUE(engine.RoundFinnished());

  engine.SetupNewRound();
  EXPECT_EQ(Wins({1,0}), engine.GetWins());
  engine.PerformRound();

  EXPECT_EQ(Scoreboard({2,1}), engine.GetScoreboard());
  EXPECT_TRUE(engine.RoundFinnished());
  EXPECT_EQ(Wins({2,0}), engine.GetWins());
}

TEST(EngineTest, PerformTurnSecure){
  std::unique_ptr<CustomGenerator> generator(new CustomGenerator{{{0.0,6.0}, {-3.0,0.0}, {5.0,1.0}}, {{1.0,0.0}, {-8.0,0.0}}});

  Engine engine{std::move(generator)};

  engine.AddSelector(std::unique_ptr<Selector>(new Closest()));
  engine.AddSelector(std::unique_ptr<Selector>(new Closest()));

  engine.SetupNewRound();
  ASSERT_TRUE(engine.PerformTurn());
  engine.PerformRound();
  ASSERT_FALSE(engine.PerformTurn());
}

TEST(EngineTest, SameDistance){
  std::unique_ptr<CustomGenerator> generator(new CustomGenerator{{{0.0,6.0}}, {{1.0,0.0}, {1.0,0.0}}});

  Engine engine{std::move(generator)};

  engine.AddSelector(std::unique_ptr<Selector>(new Closest()));
  engine.AddSelector(std::unique_ptr<Selector>(new Closest()));
  engine.SetupNewRound();
  ASSERT_TRUE(engine.PerformTurn());

  const std::vector<Salesman>& salesmen = engine.GetSalesmen();
  const Salesman& salesman1 = salesmen.at(0);
  const Salesman& salesman2 = salesmen.at(1);

  EXPECT_TRUE(testPoint({0,6}, salesman1));
  EXPECT_TRUE(testPoint({0,6}, salesman2));
}
