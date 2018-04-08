#include "map.h"

void Map::AddCities(std::initializer_list<Point> locations){
    for(auto city : locations) {
        cities_.emplace_back(city);
    }
}

void Map::AddSalesman(std::initializer_list<Salesman> salesmen){
    for(auto salesman : salesmen) {
        cities_.emplace_back(salesman);
    }
}

unsigned int Map::NrOfCities() const{
    return cities_.size();
}

unsigned int Map::NrOfSalesman() const{
    return cities_.size();
}
