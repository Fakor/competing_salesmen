#include <iostream>
#include <string>
#include <random>
#include <memory>

#include "cxxopts.hpp"

int main(int argc, char **argv){
  cxxopts::Options options("Competing Salesman", "Command line version");
  options.add_options()
    ("s,seed", "Start seed number", cxxopts::value<int>())
    ("r,rounds", "Number of rounds", cxxopts::value<int>()->default_value("1"));

  auto result = options.parse(argc, argv);
  int seed;
  if(result.count("seed") == 0){
    std::random_device rd;
    seed=rd();
  } else{
    seed=result["seed"].as<int>();
  }
  int rounds = result["rounds"].as<int>();

  std::cout << "Seed: " << seed << std::endl;
  std::cout << "Rounds: " << rounds << std::endl;


  return 0;
}
