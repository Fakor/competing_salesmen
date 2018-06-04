#include "json_conversion.h"

std::string JsonCities(const UnvisitedCities &cities){
  std::string ret = "{\"cities\": [";
  bool first = true;
  for(auto& city: cities){
    if(first){
      first = false;
    }
    else{
      ret += ",";
    }
    ret += "{\"x\":" + std::to_string(city->X()) + ", \"y\":" + std::to_string(city->Y()) + "}";
  }
  ret += "]}";
  return ret;
}
