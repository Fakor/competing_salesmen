#include "request_handler.h"

std::string handle_request(std::string request, Engine& engine){
  auto request_json = json::parse(request);
  std::string response = "";
  for(auto& element: request_json){
    std::string part_response = "";
    if(auto found_element = element.find("generate_map"); found_element != element.end()){
      engine.GenerateNewMap();
      part_response += NewMapGeneratedResponse(engine.GetMap());
    }
    if(auto found_element = element.find("perform_turn"); found_element != element.end()){
      if(engine.PerformTurnSecure()){
	part_response +=TurnPerformedResponse(engine);
      } else{
	part_response += NoActionResponse("no turn performed, round already finnished");
      }
    }

    
    if(part_response == ""){
      response += "{\"unknown_command\": " + element.dump() + "}";
    }else{
      response += part_response;
    }
  }

  return response;
}
