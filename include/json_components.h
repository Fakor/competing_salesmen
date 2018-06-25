#ifndef JSON_COMPONENTS_H
#define JSON_COMPONENTS_H

#include <string>

#include "point.h"
#include "utility.h"
#include "map.h"

std::string JsonPositions(std::string label, const std::vector<Point> positions);
std::string JsonMap(const Map &map);


#endif
