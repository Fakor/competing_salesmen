#ifndef JSON_COMMANDS_H
#define JSON_COMMANDS_H

#include <string>

#include <nlohmann/json.hpp>

#include "json_components.h"

#include "map.h"
#include "engine.h"

using json = nlohmann::json;

json NewMapGeneratedResponse(const Map& map);
json TurnPerformedResponse(const Engine& engine);
json NoActionResponse(std::string message);
json UnknownCommandResponse(std::string command);

#endif
