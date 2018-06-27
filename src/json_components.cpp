#include "json_components.h"

std::string JsonPositions(std::string label, const std::vector<Point> positions){
  std::string ret = "\"" + label + "\": [";
  bool first = true;
  for(auto& position: positions){
    if(first){
      first = false;
    } else{
      ret += ",";
    }
    ret  += "[" + std::to_string(position.GetX()) + ", " + std::to_string(position.GetY()) + "]";
  }
  ret += "]";
  return ret;
}

std::string JsonMap(const Map &map){
  std::string ret = "\"map\": {";
  ret += JsonPositions("cities", map.GetAllCities());
  ret += ", " + JsonSalesmen(map.GetSalesmen());
  ret += "}";
  return ret;
}

std::string JsonSalesmen(const std::vector<Salesman> &salesmen){
  std::string ret = "\"salesmen\": [";
  bool first = true;

  for(auto& salesman: salesmen){
    if(first){
      first = false;
    } else {
      ret += ",";
    }
    ret += "{" + JsonSalesman(salesman) + "}";
  }
  ret += "]";
  return ret;
}

std::string JsonSalesman(const Salesman& salesman){
  std::string ret = "\"x\": " + std::to_string(salesman.GetPosition().GetX());
  ret += ",\"y\": " + std::to_string(salesman.GetPosition().GetY());
  ret += ",\"score\": " + std::to_string(salesman.GetScore());
  return ret;
}

std::string JsonScoreboard(const Scoreboard &scoreboard){
  std::string ret = "\"score\": [";
  bool first = true;
  for(auto score: scoreboard){
    if(first){
      first = false;
    } else{
      ret += ",";
    }
    ret += std::to_string(score);
  }
  ret += "]";
  return ret;
}
