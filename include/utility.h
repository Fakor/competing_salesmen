#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <memory>
#include <map>

class Point;
class Salesman;
class Selector;

using Index = const unsigned int;

using City = Point;
using Cities = std::vector<std::unique_ptr<City>>;
using UnvisitedCities = std::vector<const City*>;
using Competers = std::vector<Salesman*>;
 
using SalesmanDistanceMap = std::map<double, Salesman*>;

using Scoreboard = std::map<Salesman*, int>;
using SelectorType = std::unique_ptr<Selector>;

#endif /* UTILITY_H */
