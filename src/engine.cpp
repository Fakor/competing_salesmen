#include "engine.h"

Engine::Engine(std::unique_ptr<MapGenerator> generator)
  : generator_{std::move(generator)}
{
  map_ = generator_->GenerateMap();
  cities_ = map_.GetCities();
}

void Engine::AddSelector(SelectorType selector){
  selectors_.emplace_back(std::move(selector));
}

void Engine::Init(){
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

void Engine::GenerateNewMap(){
  map_ = generator_->GenerateMap();
  cities_ = map_.GetCities();
  Init();
}

void Engine::SelectTargets(){
    std::for_each(selectors_.begin(), selectors_.end(), [](std::unique_ptr<Selector>& s){s->ChooseTarget();});
}

void Engine::PerformTurn(){
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
}

bool Engine::PerformTurnSecure(){
  if(!RoundFinnished()){
    PerformTurn();
    return true;
  } else {
    return false;
  }
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
  for(auto& salesman: map_.GetSalesmenConst()){
    scoreboard.push_back(salesman.GetScore());
  }
  return scoreboard;
}

bool Engine::RoundFinnished() const{
  return cities_.empty();
}

UnvisitedCities Engine::GetCities() const{
  return map_.GetCities();
}

std::vector<Salesman>& Engine::GetSalesmen(){
  return map_.GetSalesmen();
}

const std::vector<Salesman>& Engine::GetSalesmenConst() const{
  return map_.GetSalesmenConst();
}

const Map& Engine::GetMap() const{
  return map_;
}
