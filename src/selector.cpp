#include "selector.h"

void Selector::SetCities(UnvisitedCities* cities){
    cities_ = cities;
}

void Selector::SetSalesman(Salesman* salesman){
    salesman_ = salesman;
}

void Selector::SetTarget(const City* city){
    salesman_->SetTarget(city);
}
