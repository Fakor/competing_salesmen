#include <iostream>
#include <cstdlib>
#include <random>

#include "map.h"
#include "map_generator.h"
#include "log_tools.h"

int main(int argc, char **argv){
  int seed;
  if(argc==2){
    seed=atoi(argv[1]);
  }
  else{
    std::random_device rd;
    seed=rd();
  }
  printf("SEED: %d\n", seed);
  Map map = GenerateMap(4, 3, seed);

  print_cities(map.GetCities());

    return 0;
}
