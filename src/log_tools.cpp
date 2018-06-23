#include "log_tools.h"

void print_city(const City &city){
  std::cout << "City location: (" << city.X() << ", " << city.Y() << ")\n";
}

void print_cities(const UnvisitedCities &cities){
  for(auto city: cities){
    print_city(*city);
  }
}

void print_scoreboard(const Scoreboard &scoreboard){
  for(auto it: scoreboard){
    std::cout << it << "\n";
  }
}
