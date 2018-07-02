#ifndef MAP_GENERATOR_FACTORY_H
#define MAP_GENERATOR_FACTORY_H

#include <memory>

#include <nlohmann/json.hpp>

#include "random_generator.h"

using json = nlohmann::json;

std::unique_ptr<MapGenerator> map_generator_factory(json j);

#endif
