#include "custom_generator.h"

CustomGenerator::CustomGenerator(std::initializer_list<City> cities, std::initializer_list<Salesman> salesmen){
  for(auto city: cities){
    cities_.push_back(city);
  }
  for(auto salesman: salesmen){
    salesmen_.push_back(salesman);
  }
}

Map CustomGenerator::GenerateMap(){
  Map map{cities_, salesmen_};
    return map;
}
