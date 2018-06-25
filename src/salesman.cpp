#include "salesman.h"

Salesman::Salesman(double init_x, double init_y)
  : position_{init_x, init_y}
{}

void Salesman::SetTarget(const Point *target){
  target_ = target;
}

void Salesman::MoveToTarget(){
  if(target_ != nullptr){
    position_.MoveTo(*target_);
  }
}

void Salesman::MoveTowardsTarget(double distance){
  if(target_ != nullptr){
    position_.MoveTowards(*target_, distance);
  }
}

std::optional<double> Salesman::DistanceToTarget() const{
  if(target_ != nullptr){
    return DistanceTo(*target_);
  }
  return std::nullopt;
}

double Salesman::DistanceTo(const Point& other_point) const{
  return position_.DistanceTo(other_point);
}

const Point* Salesman::GetTarget() const{
  return target_;
}

Point Salesman::GetPosition() const{
  return position_;
}

void Salesman::AddScore(){
  ++score_;
}

int Salesman::GetScore() const {
  return score_;
}
