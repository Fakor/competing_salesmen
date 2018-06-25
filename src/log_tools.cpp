#include "log_tools.h"

void print_city(const City &city){
  std::cout << "City location: (" << city.GetX() << ", " << city.GetY() << ")\n";
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
