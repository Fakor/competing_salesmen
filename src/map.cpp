#include "map.h"

void Map::AddCities(std::initializer_list<City> locations){
    for(auto city : locations) {
        cities_.emplace_back(new City(city));
        unvisited_cities_.emplace_back(cities_.back().get());
    }
}

void Map::AddSalesman(Salesman salesman){
    salesmen_.emplace_back(salesman);
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

City* Map::GetCity(unsigned int index){
    return cities_[index].get();
}

void Map::SetSalesmanTarget(unsigned int salesman_index, unsigned int city_index){
    salesmen_[salesman_index].SetTarget(cities_[city_index].get());
}

void Map::VisitCity(Point* const city){
    for(auto city_it = unvisited_cities_.begin(); city_it != unvisited_cities_.end(); ++city_it){
        if(*city_it == city){
            unvisited_cities_.erase(city_it);
            return;
        }
    }
    throw 50;
}

SalesmanDistanceMap Map::MapSalesmanDistance(){
    SalesmanDistanceMap mapped_salesmen{};
    for(auto& s: salesmen_){
        std::optional<double> salesman_distance = s.DistanceToTarget();
        if(salesman_distance.has_value()){
            double distance = salesman_distance.value();
            if(mapped_salesmen.find(distance) != mapped_salesmen.end()){
                throw 1;
            }
            mapped_salesmen.emplace(std::make_pair(distance, &s));
        }
    }
    return mapped_salesmen;
}

UnvisitedCities* Map::GetUnvisitedCities(){
    return &unvisited_cities_;
}
