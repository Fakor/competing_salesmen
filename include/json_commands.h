#ifndef JSON_COMMANDS_H
#define JSON_COMMANDS_H

#include <string>

#include "json_components.h"

#include "map.h"
#include "engine.h"

std::string NewMapGeneratedResponse(const Map& map);
std::string TurnPerformedResponse(const Engine& engine);
std::string NoActionResponse(std::string message);
std::string UnknownCommandResponse(std::string command);


#endif
