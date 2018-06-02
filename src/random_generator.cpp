#include "random_generator.h"

RandomGenerator::RandomGenerator(unsigned int nr_of_cities, double size, unsigned int nr_of_salesmen, int seed)
  : nr_of_cities_{nr_of_cities}, size_{size}, nr_of_salesmen_{nr_of_salesmen}, gen{seed}
{
  
}

Map RandomGenerator::GenerateMap(){
  std::uniform_real_distribution<> dis(0.0, size_);
  Cities cities;
  for(int i = 0; i < nr_of_cities_; ++i){
    cities.emplace_back(dis(gen), dis(gen));
  }
  std::vector<Salesman> salesmen;
  for(int i = 0; i < nr_of_salesmen_; ++i){
    salesmen.emplace_back(dis(gen), dis(gen));
  }
  return {cities, salesmen};
}
