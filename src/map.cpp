#include "map.h"

void Map::AddCities(std::initializer_list<Point> locations){
    for(auto city : locations) {
        cities_.emplace_back(city);
    }
}

void Map::AddSalesman(Salesman* salesman){
    salesmen_.emplace_back(salesman);
}

unsigned int Map::NrOfCities() const{
    return cities_.size();
}

unsigned int Map::NrOfSalesman() const{
    return salesmen_.size();
}
