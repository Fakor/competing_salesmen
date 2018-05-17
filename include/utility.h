#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <memory>
#include <map>

class Point;
class Salesman;

using Index = const unsigned int;

using City = Point;
using Cities = std::vector<std::unique_ptr<City>>;
using UnvisitedCities = std::vector<const City*>;
using Competers = std::vector<Salesman*>;
 
using SalesmanDistanceMap = std::map<double, Salesman*>;

#endif /* UTILITY_H */
