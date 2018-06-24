#include "json_components.h"

std::string JsonCities(const UnvisitedCities &cities){
  std::string ret = "\"cities\": [";
  bool first = true;
  for(auto& city: cities){
    if(first){
      first = false;
    }
    else{
      ret += ",";
    }
    ret += "[" + std::to_string(city->X()) + ", " + std::to_string(city->Y()) + "]";
  }
  ret += "]";
  return ret;
}

std::string JsonSalesmen(const std::vector<Salesman> salesmen){
  std::string ret = "\"salesmen\": [";
  bool first = true;
  for(auto& salesman: salesmen){
    if(first){
      first = false;
    } else{
      ret += ",";
    }
    ret  += "[" + std::to_string(salesman.X()) + ", " + std::to_string(salesman.Y()) + "]";
  }
  ret += "]";
  return ret;
}

std::string JsonMap(const Map &map){
  std::string ret = "\"map\": {";
  ret += JsonCities(map.GetCities()) + ", ";
  ret += JsonSalesmen(map.GetSalesmenConst());
  ret += "}";
  return ret;
}
