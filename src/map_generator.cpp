#include "map_generator.h"

Map GenerateMap(unsigned int nr_of_cities, double size){
  Map map;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, size);
    for (int n = 0; n < nr_of_cities; ++n) {
        map.AddCities({{dis(gen), dis(gen)}});
    }
    return map;
}
