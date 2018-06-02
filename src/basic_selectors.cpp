#include "basic_selectors.h"

void Closest::ChooseTarget() {
  std::map<double, const City*> distance_map;
  auto add_dist = [this, &distance_map](const City* city) {distance_map.emplace(std::make_pair(salesman_->DistanceTo(*city), city));};
  std::for_each(cities_->begin(), cities_->end(), add_dist);
  SetTarget(distance_map.begin()->second);
}

RandomSelector::RandomSelector(int seed)
  :gen{seed}
{

}

void RandomSelector::ChooseTarget() {
  std::map<double, const City*> random_map;
  std::uniform_real_distribution<> dis(0.0,1);
  auto add_rand = [this, &random_map, &dis](const City* city) {random_map.emplace(std::make_pair(dis(gen), city));};
  std::for_each(cities_->begin(), cities_->end(), add_rand);
  SetTarget(random_map.begin()->second);

}
