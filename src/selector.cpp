#include "selector.h"

void Selector::SetCities(UnvisitedCities* cities){
  cities_ = cities;
}

void Selector::SetSalesman(Salesman* salesman){
  salesman_ = salesman;
}

bool Selector::LastTargetPresent() const{
  auto city_find = std::find(cities_->begin(), cities_->end(), salesman_->GetTarget());
  return city_find != cities_->end();
}

const Salesman *Selector::GetSalesman() const{
  return salesman_;
}

void Selector::SetTarget(const City* city){
  salesman_->SetTarget(city);
}

void Selector::AddWin(){
  ++wins_;
}

int Selector::Wins() const{
  return wins_;
}
