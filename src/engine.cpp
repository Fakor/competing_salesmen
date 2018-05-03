#include "engine.h"

Engine::Engine(Map& map)
:map_{map}
{
}

void Engine::AddSelector(SelectorType selector, unsigned int salesman_index){
    selector->SetCities(map_.GetUnvisitedCities());
    selector->SetSalesman(map_.GetSalesman(salesman_index));
    selectors_.emplace_back(std::move(selector));
}

void Engine::SelectTargets(){
    for(auto& selector: selectors_){
        selector->ChooseTarget();
    }
}

void Engine::PerformTurn(){
    SelectTargets();
    auto mapped_salesmen = map_.MapSalesmanDistance();
    if(!mapped_salesmen.empty()){
        auto mapped_salesmen_iterator = mapped_salesmen.begin();
        double distance = mapped_salesmen_iterator->first;
        mapped_salesmen_iterator->second->MoveToTarget();
        map_.VisitCity(mapped_salesmen_iterator->second->GetTarget());
    }
}

Salesman* Engine::NextSalesman(){
    return map_.GetSalesman(current_salesman_index++);
}
