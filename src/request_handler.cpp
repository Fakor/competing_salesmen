#include "request_handler.h"

std::string handle_request(std::string request, Engine& engine){
  auto request_json = json::parse(request);
  json response;
  for(auto& element: request_json){
    std::string command = element["command"];
    if(command == "generate_map"){
      engine.SetupNewRound();
      response.push_back(NewMapGeneratedResponse(engine.GetMap()));
    }
    else if(command == "perform_turn"){
      if(engine.PerformTurn()){
	response.push_back(TurnPerformedResponse(engine));
      } else{
	response.push_back(NoActionResponse("no turn performed, round already finnished"));
      }
    }
    else if(command == "finnish_round"){
      while(engine.PerformTurn()){
	response.push_back(TurnPerformedResponse(engine));
      }
    }
    else if(command == "map_generator_settings"){
      engine.SetMapGenerator(map_generator_factory(element));
      response.push_back(NoActionResponse("new settings for map generator"));
    } else {
      response.push_back(UnknownCommandResponse(element));
    }
  }

  return response.dump();
}
