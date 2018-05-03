#include "basic_selectors.h"

void Closest::ChooseTarget() {
    std::map<double, City*> distance_map;
    auto add_dist = [this, &distance_map](City* city) {distance_map.emplace(std::make_pair(salesman_->DistanceTo(*city), city));};
    std::for_each(cities_->begin(), cities_->end(), add_dist);
    SetTarget(distance_map.begin()->second);
}
