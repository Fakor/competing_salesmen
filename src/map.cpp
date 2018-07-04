#include "map.h"

Map::Map(){}

Map::Map(Cities cities, std::vector<Salesman> salesmen)
  : cities_{cities}, salesmen_{salesmen}
{
}

unsigned int Map::NrOfCities() const{
  return cities_.size();
}

unsigned int Map::NrOfSalesman() const{
  return salesmen_.size();
}

const Cities& Map::AllCities() const{
  return cities_;
}

Salesman* Map::GetSalesman(unsigned int index) {
  return &salesmen_[index];
}

City& Map::GetCity(unsigned int index){
  return cities_[index];
}

SalesmanDistanceMap Map::MapSalesmanDistance(){
  SalesmanDistanceMap mapped_salesmen{};
  for(auto& s: salesmen_){
    std::optional<double> salesman_distance = s.DistanceToTarget();
    if(salesman_distance.has_value()){
      double distance = salesman_distance.value();
      mapped_salesmen.emplace(std::make_pair(distance, &s));
    }
  }
  return mapped_salesmen;
}

UnvisitedCities Map::GetCities() const{
  UnvisitedCities cities_copy;
  for(auto& city: cities_){
    cities_copy.emplace_back(&city);
  }
  return cities_copy;
}

const Cities& Map::GetAllCities() const{
  return cities_;
}

std::vector<Salesman>& Map::GetSalesmen(){
  return salesmen_;
}

const std::vector<Salesman>& Map::GetSalesmen() const{
  return salesmen_;
}

std::vector<Point> Map::GetSalesmanPositions() const{
  std::vector<Point> positions{};
  for(auto& salesman: salesmen_){
    positions.emplace_back(salesman.GetPosition());
  }
  return positions;
}
