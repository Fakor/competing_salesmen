#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <memory>

class Point;
class Salesman;

using Index = const unsigned int;

using City = Point;
using Cities = std::vector<std::unique_ptr<City>>;
using Competers = std::vector<Salesman*>;
 
#endif /* UTILITY_H */
