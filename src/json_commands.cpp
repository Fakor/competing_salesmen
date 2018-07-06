#include "json_commands.h"

json NewMapGeneratedResponse(const Map& map){
  json ret = map;
  ret["response"] = "new_map";
  return ret;
}

json TurnPerformedResponse(const Engine& engine){
  json ret;
  ret["salesmen"] = engine.GetSalesmen();
  ret["response"] = "turn_performed";
  return ret;
}

json NoActionResponse(std::string message){
  json ret;
  ret["message"] = message;
  ret["response"] = "no_action";
  return ret;
}

json UnknownCommandResponse(json command){
  json ret;
  ret["command"] = command.dump();
  ret["response"] = "unknown_command";
  return ret;
}
