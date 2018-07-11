#ifndef SELECTOR_H
#define SELECTOR_H 

#include <algorithm>

#include "utility.h"
#include "salesman.h"

class Selector{
 public:
  virtual void ChooseTarget() = 0;

  void SetCities(UnvisitedCities* cities);
  void SetSalesman(Salesman* salesman);
  void SetTarget(const City* city);
  bool LastTargetPresent() const;
  const Salesman* GetSalesman() const;

  void AddWin();
  int Wins() const;
 protected:
  Salesman* salesman_;

  UnvisitedCities* cities_;
  int wins_{0};
};
 
#endif 
