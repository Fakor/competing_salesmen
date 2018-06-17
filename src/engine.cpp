#include "engine.h"

Engine::Engine(std::unique_ptr<MapGenerator> generator)
  : generator_{std::move(generator)}
{
  map_ = generator_->GenerateMap();
  cities_ = map_.GetCities();
}

void Engine::AddSelector(SelectorType selector, unsigned int salesman_index){
    selector->SetCities(&cities_);
    selector->SetSalesman(map_.GetSalesman(salesman_index));
    selectors_.emplace_back(std::move(selector));
}

void Engine::VisitCity(const Point* city){
    auto city_it = std::find(cities_.begin(), cities_.end(), city);
    cities_.erase(city_it);
}

void Engine::GenerateNewMap(){
  map_ = generator_->GenerateMap();
}

Salesman& Engine::GetSalesman(int index){
  return *map_.GetSalesman(index);
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
	++scoreboard_[mapped_salesmen_iterator->second];
        while(++mapped_salesmen_iterator != mapped_salesmen.end()){
            mapped_salesmen_iterator->second->MoveTowardsTarget(distance);
        }
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

Scoreboard& Engine::GetScoreboard(){
    return scoreboard_;
}

bool Engine::RoundFinnished() const{
  return cities_.empty();
}

UnvisitedCities Engine::GetCities() const{
  return map_.GetCities();
}

const std::vector<Salesman> Engine::GetSalesmen() const{
  return map_.GetSalesmen();
}

const Map& Engine::GetMap() const{
  return map_;
}
