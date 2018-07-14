#include <iostream>
#include <string>
#include <random>
#include <memory>

#include "cxxopts.hpp"

#include "random_generator.h"
#include "basic_selectors.h"
#include "engine.h"
#include "log_tools.h"

int main(int argc, char **argv){
  cxxopts::Options options("Competing Salesman", "Command line version");
  options.add_options()
    ("s,seed", "Start seed number", cxxopts::value<int>())
    ("r,rounds", "Number of rounds", cxxopts::value<int>()->default_value("1"))
    ("c,cities", "Number of cities", cxxopts::value<int>()->default_value("51"));

  auto result = options.parse(argc, argv);
  int seed;
  if(result.count("seed") == 0){
    std::random_device rd;
    seed=rd();
  } else{
    seed=result["seed"].as<int>();
  }
  int rounds = result["rounds"].as<int>();
  int cities = result["cities"].as<int>();

  std::cout << "Seed: " << seed << std::endl;
  std::cout << "Rounds: " << rounds << std::endl;

  std::unique_ptr<RandomGenerator> generator(new RandomGenerator(cities,3,2,seed));
  Engine engine(std::move(generator));

  engine.AddSelector(std::unique_ptr<Selector>(new Closest()));
  engine.AddSelector(std::unique_ptr<Selector>(new Closest()));

  for(int i = 0; i < rounds; ++i){
    engine.SetupNewRound();
    engine.PerformRound();
  }

  int i = 1;
  for(auto& selector: engine.GetSelectors()){
    int wins = selector->Wins();
    double percentage = 100 * static_cast<double>(wins) / rounds;
    std::cout << "Selector " << i << ": " << selector->Wins() << " (" << percentage << " %)" << std::endl;
    ++i;
  }
  return 0;
}
