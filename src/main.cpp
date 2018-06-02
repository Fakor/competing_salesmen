#include <iostream>
#include <cstdlib>
#include <random>

#include "map.h"
#include "random_generator.h"
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
  std::unique_ptr<RandomGenerator> generator(new RandomGenerator(4,3,2,seed));

  Engine engine(std::move(generator));

  engine.AddSelector(std::unique_ptr<Selector>(new Closest()), 0);
  engine.AddSelector(std::unique_ptr<Selector>(new Closest()), 1);
  engine.PerformRound();
  print_cities(engine.GetCities());
  print_scoreboard(engine.GetScoreboard());
    return 0;
}
