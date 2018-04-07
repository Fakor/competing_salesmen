#include "map.h"

void Map::AddCities(std::initializer_list<Point> locations){
    for(auto city : locations) {
        cities_.emplace_back(city);
    }
}

const Point& Map::CityLocation(Index ind) const {
    return cities_[ind];
}

unsigned int Map::NrOfCities() const{
    return cities_.size();
}
