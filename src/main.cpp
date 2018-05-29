#include <iostream>
#include <cstdlib>
#include <random>

#include "map.h"
#include "map_generator.h"
#include "log_tools.h"
#include "engine.h"
#include "basic_selectors.h"

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
  map.AddSalesman({1,1});
  map.AddSalesman({3,3});
  Engine engine(map);

  engine.AddSelector(std::unique_ptr<Selector>(new Closest()), 0);
  engine.AddSelector(std::unique_ptr<Selector>(new Closest()), 1);
  engine.PerformRound();
  print_cities(map.GetCities());
  print_scoreboard(engine.GetScoreboard());
    return 0;
}
