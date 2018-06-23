#ifndef MAP_H
#define MAP_H

#include <vector>
#include <algorithm>
#include <initializer_list>
#include <map>

#include "utility.h"
#include "point.h"
#include "salesman.h"

class Map{
 public:
  Map();
  Map(Cities cities, std::vector<Salesman> salesmen);
  unsigned int NrOfCities() const;
  unsigned int NrOfSalesman() const;

  const Cities& AllCities() const;

  Salesman* GetSalesman(unsigned int index);
  City& GetCity(unsigned int index);

  SalesmanDistanceMap MapSalesmanDistance();
  UnvisitedCities GetCities() const;
  std::vector<Salesman>& GetSalesmen();
  const std::vector<Salesman>& GetSalesmenConst() const;

 private:
  Cities cities_;
  std::vector<Salesman> salesmen_;
};
 
#endif /* MAP_H */
