#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

#include <string>

#include <nlohmann/json.hpp>

#include "engine.h"
#include "map_generator_factory.h"
#include "json_commands.h"

using json = nlohmann::json;

std::string handle_request(std::string request, Engine& engine);

#endif
