#include <iostream>

#include "map.h"
#include "map_generator.h"
#include "log_tools.h"

int main(int argc, char **argv){
  Map map = GenerateMap(4, 3);

  print_cities(map.GetCities());

    return 0;
}
