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

const std::vector<Point>& Map::AllCities() const{
    return cities_;
}

void Map::MoveSalesmen() {
    double distance = GetSalesmanMovement();
    std::for_each(salesmen_.begin(), salesmen_.end(), [distance](Salesman* s) {s->MoveTowardsTarget(distance);});
}

double Map::GetSalesmanMovement() const{
    double distance;
    bool distance_found{false};
    for(auto& s: salesmen_){
        std::optional<double> salesman_distance = s->DistanceToTarget();
        if(salesman_distance.has_value()){
            if(distance_found){
                distance = std::min(distance, salesman_distance.value());
            }
            else{
                distance = salesman_distance.value();
                distance_found = true;
            }
        }
    }
    if(distance_found){
        return distance;
    }
    else{
        return 0;
    }
}
