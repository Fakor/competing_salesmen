#ifndef MAP_H
#define MAP_H

#include <vector>
#include <initializer_list>

#include "utility.h"
#include "point.h"
#include "salesman.h"

class Map{
    public:

        void AddCities(std::initializer_list<Point> locations);
        void AddSalesman(Salesman* salesmen);

        unsigned int NrOfCities() const;
        unsigned int NrOfSalesman() const;
    private:
        std::vector<Point> cities_;
        std::vector<Salesman*> salesmen_;
};
 
#endif /* MAP_H */
