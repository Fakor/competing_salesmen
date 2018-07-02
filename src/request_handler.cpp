#include "request_handler.h"

std::string handle_request(std::string request, Engine& engine){
  auto request_json = json::parse(request);
  json response;
  for(auto& element: request_json){
    if(auto found_element = element.find("generate_map"); found_element != element.end()){
      engine.GenerateNewMap();
      response.push_back(NewMapGeneratedResponse(engine.GetMap()));
    }
    else if(auto found_element = element.find("perform_turn"); found_element != element.end()){
      if(engine.PerformTurnSecure()){
	response.push_back(TurnPerformedResponse(engine));
      } else{
	response.push_back(NoActionResponse("no turn performed, round already finnished"));
      }
    }
    else if(auto found_element = element.find("map_generator_settings"); found_element != element.end()){
      engine.SetMapGenerator(map_generator_factory(*found_element));
      response.push_back(NoActionResponse("new settings for map generator"));
    } else {
      response["unknown_command"] = element;
    }
  }

  return response.dump();
}
