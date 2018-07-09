#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include <map>

#include "map_generator.h"
#include "selector.h"
#include "map.h"

#include "utility.h"

using SelectorType = std::unique_ptr<Selector>;

class Engine{
 public:
  Engine(std::unique_ptr<MapGenerator>);

  void AddSelector(SelectorType selector);

  void SetupNewRound();

  void SelectTargets();
  bool PerformTurn();
  void PerformRound();

  void SetMapGenerator(std::unique_ptr<MapGenerator> generator);

  void VisitCity(const Point* city);

  Scoreboard GetScoreboard() const;
  Wins GetWins() const;
  bool RoundFinnished() const;
  void DetermineWinner();

  UnvisitedCities GetCities() const;
  const std::vector<Salesman>& GetSalesmen() const;
  std::vector<Point> GetSalesmanPositions() const;

  const Map& GetMap() const;

  const std::vector<SelectorType>& GetSelectors() const;
 private:
  std::unique_ptr<MapGenerator> generator_;
  Map map_;
  std::vector<SelectorType> selectors_;

  UnvisitedCities cities_;

  Salesman* NextSalesman();

  int current_salesman_index{0};
  bool round_finnished_ = false;
};
 
#endif /* ENGINE_H */
