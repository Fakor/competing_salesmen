#ifndef JSON_CONVERSION_H
#define JSON_CONVERSION_H

#include <string>

#include "point.h"
#include "utility.h"
#include "map.h"

std::string JsonCities(const UnvisitedCities &cities);
std::string JsonSalesmen(const std::vector<Salesman> salesmen);
std::string JsonMap(const Map &map);


#endif
