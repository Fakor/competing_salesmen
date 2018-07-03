#include "map_generator_factory.h"

std::unique_ptr<MapGenerator> map_generator_factory(json j){
  if(j["type"] == "random"){
    return std::unique_ptr<MapGenerator>(new RandomGenerator(j["nr_of_cities"].get<int>(), 2.0, 2, j["seed"].get<int>()));
  } else{
    return nullptr;
  }
}
