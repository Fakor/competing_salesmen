#include "engine.h"

Engine::Engine(std::unique_ptr<MapGenerator> generator)
  : generator_{std::move(generator)}
{
}

void Engine::AddSelector(SelectorType selector){
  selectors_.emplace_back(std::move(selector));
}

void Engine::SetupNewRound(){
  round_finnished_ = false;
  map_ = generator_->GenerateMap();
  cities_ = map_.GetCities();

  std::vector<Salesman>& salesmen = map_.GetSalesmen();
  if(selectors_.size() != map_.GetSalesmen().size()){
    throw "Number of selectors and salesmen mismatch!";
  }
  auto selector = selectors_.begin();
  auto salesman = salesmen.begin();
  for(; selector != selectors_.end(); ++selector, ++salesman){
    (*selector)->SetCities(&cities_);
    (*selector)->SetSalesman(&(*salesman));
  }
}

void Engine::VisitCity(const Point* city){
    auto city_it = std::find(cities_.begin(), cities_.end(), city);
    cities_.erase(city_it);
}

void Engine::SetMapGenerator(std::unique_ptr<MapGenerator> generator){
  generator_ = std::move(generator);
}

void Engine::SelectTargets(){
    std::for_each(selectors_.begin(), selectors_.end(), [](std::unique_ptr<Selector>& s){s->ChooseTarget();});
}

bool Engine::PerformTurn(){
  if(round_finnished_){
    return false;
  }
  SelectTargets();
  auto mapped_salesmen = map_.MapSalesmanDistance();
  if(!mapped_salesmen.empty()){
    auto mapped_salesmen_iterator = mapped_salesmen.begin();
    double distance = mapped_salesmen_iterator->first;
    mapped_salesmen_iterator->second->MoveToTarget();
    VisitCity(mapped_salesmen_iterator->second->GetTarget());
    mapped_salesmen_iterator->second->AddScore();
    while(++mapped_salesmen_iterator != mapped_salesmen.end()){
      mapped_salesmen_iterator->second->MoveTowardsTarget(distance);
    }
  }
  if(cities_.empty()){
    DetermineWinner();
    round_finnished_ = true;
  }
  return true;
}

void Engine::PerformRound(){
  while(!RoundFinnished()){
    PerformTurn();
  }
}

Salesman* Engine::NextSalesman(){
    return map_.GetSalesman(current_salesman_index++);
}

Scoreboard Engine::GetScoreboard() const{
  Scoreboard scoreboard;
  for(auto& salesman: map_.GetSalesmen()){
    scoreboard.push_back(salesman.GetScore());
  }
  return scoreboard;
}

Wins Engine::GetWins() const{
  std::vector<int> wins;
  for(auto& selector: selectors_){
    wins.push_back(selector->Wins());
  }
  return wins;
}

bool Engine::RoundFinnished() const{
  return round_finnished_;
}

void Engine::DetermineWinner(){
  int highest_score = 0;
  Selector* leader = nullptr;
  for(auto& selector: selectors_){
    int score = selector->GetSalesman()->GetScore();
    if(score > highest_score){
      highest_score = score;
      leader = selector.get();
    }
  }
  leader->AddWin();
}

UnvisitedCities Engine::GetCities() const{
  return map_.GetCities();
}

const std::vector<Salesman>& Engine::GetSalesmen() const{
  return map_.GetSalesmen();
}

std::vector<Point> Engine::GetSalesmanPositions() const{
  return map_.GetSalesmanPositions();
}

const Map& Engine::GetMap() const{
  return map_;
}
