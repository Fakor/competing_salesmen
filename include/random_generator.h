#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>

#include "map_generator.h"

class RandomGenerator: public MapGenerator{
 public:
  RandomGenerator(unsigned int nr_of_cities, double size, unsigned int nr_of_salesmen, int seed);

  Map GenerateMap() override;

 private:
  unsigned int nr_of_cities_;
  double size_;
  unsigned int nr_of_salesmen_;
  std::mt19937 gen;
};



#endif
