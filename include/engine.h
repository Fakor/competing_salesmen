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

  void Init();

  void SelectTargets();
  void PerformTurn();
  bool PerformTurnSecure();
  void PerformRound();

  void GenerateNewMap();

  void VisitCity(const Point* city);

  Scoreboard GetScoreboard() const;
  bool RoundFinnished() const;

  UnvisitedCities GetCities() const;
  std::vector<Salesman>& GetSalesmen();

  const Map& GetMap() const;
 private:
  std::unique_ptr<MapGenerator> generator_;
  Map map_;
  std::vector<SelectorType> selectors_;

  UnvisitedCities cities_;

  Salesman* NextSalesman();

  int current_salesman_index{0};
};
 
#endif /* ENGINE_H */
