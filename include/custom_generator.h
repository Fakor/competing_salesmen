#ifndef CUSTOM_GENERATOR_H
#define CUSTOM_GENERATOR_H

#include <initializer_list>

#include "utility.h"
#include "map_generator.h"

class CustomGenerator: public MapGenerator{
public:
  CustomGenerator(std::initializer_list<Point>, std::initializer_list<Salesman>);

  
  Map GenerateMap() override;

private:
  Cities cities_;
  std::vector<Salesman> salesmen_;
};


#endif
