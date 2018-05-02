#ifndef MAP_H
#define MAP_H

#include <vector>
#include <algorithm>
#include <initializer_list>
#include <map>

#include "utility.h"
#include "point.h"
#include "salesman.h"

using SalesmanDistanceMap = std::map<double, Salesman*>;

class Map{
    public:
        void AddCities(std::initializer_list<City> locations);
        void AddSalesman(Salesman salesmen);

        unsigned int NrOfCities() const;
        unsigned int NrOfSalesman() const;

        const Cities& AllCities() const;

        Salesman* GetSalesman(unsigned int index);
        City* GetCity(unsigned int index);

        void SetSalesmanTarget(unsigned int salesman_index, unsigned int city_index);

        SalesmanDistanceMap MapSalesmanDistance();
    private:
        Cities cities_;
        std::vector<Salesman> salesmen_;
};
 
#endif /* MAP_H */
