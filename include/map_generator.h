#ifndef MAP_GENERATOR_H
#define MAP_GENERATOR_H

#include "map.h"

class MapGenerator{
public:
  virtual Map GenerateMap() = 0;
};

#endif
