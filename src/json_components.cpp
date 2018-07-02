#include "json_components.h"

void to_json(json& j, const Map& map){
  j["cities"] = map.GetAllCities();
  j["salesmen"] = map.GetSalesmen();
}

void from_json(const json& j, Map& map){
}

void to_json(json& j, const Point& point){
  j.push_back(point.GetX());
  j.push_back(point.GetY());
}

void from_json(const json& j, Point& point){
}

void to_json(json& j, const Salesman& salesman){
  j["position"] = salesman.GetPosition();
  j["score"] = salesman.GetScore();
}

void from_json(const json& j, Salesman& salesman){
}
