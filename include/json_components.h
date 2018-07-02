#ifndef JSON_COMPONENTS_H
#define JSON_COMPONENTS_H

#include <string>

#include <nlohmann/json.hpp>

#include "point.h"
#include "utility.h"
#include "map.h"
#include "engine.h"

using json = nlohmann::json;

void to_json(json& j, const Map& map);
void from_json(const json& j, Map& map);

void to_json(json& j, const Point& point);
void from_json(const json& j, Point& point);

void to_json(json& j, const Salesman& salesman);
void from_json(const json& j, Salesman& salesman);

#endif
