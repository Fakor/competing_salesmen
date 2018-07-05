#include "json_commands.h"

json NewMapGeneratedResponse(const Map& map){
  json ret;
  ret["new_map"] = map;
  return ret;
}

json TurnPerformedResponse(const Engine& engine){
  json ret;
  ret["turn_performed"] = engine.GetSalesmen();
  return ret;
}

json NoActionResponse(std::string message){
  json ret;
  ret["no_action"] = message;
  return ret;
}

json UnknownCommandResponse(json command){
  json ret;
  ret["unknown_command"] = command.dump();
  return ret;
}
