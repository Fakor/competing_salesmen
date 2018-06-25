#include "json_commands.h"

std::string NewMapGeneratedResponse(const Map& map){
  std::string ret = "{\"new_map\": {";
  ret += JsonMap(map) + "}}";

  return ret;
}

std::string TurnPerformedResponse(const Engine& engine){
  std::string ret = "{\"turn_performed\": {";
  ret += JsonPositions("salesmen", engine.GetSalesmanPositions()) + "}}";

  return ret;
}

std::string NoActionResponse(std::string message){
  std::string ret = "{\"no_action\": \"" + message + "\"}";
  return ret;
}

std::string UnknownCommandResponse(std::string command){
  std::string ret = "{\"unknown_command\": \"" + command + "\"}";
  return ret;
}
