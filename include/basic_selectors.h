#ifndef BASIC_SELECTORS_H
#define BASIC_SELECTORS_H

#include <algorithm>
#include <random>

#include "selector.h"

class Closest: public Selector{
 public:
  void ChooseTarget() override;
};

class RandomSelector: public Selector{
 public:
  RandomSelector(int seed);
  void ChooseTarget() override;

 private:
  std::mt19937 gen;
};
 
#endif /* BASIC_SELECTOS_H */
