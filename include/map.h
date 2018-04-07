#ifndef MAP_H
#define MAP_H

#include <vector>
#include <initializer_list>

#include "utility.h"
#include "point.h"

class Map{
    public:

        void AddCities(std::initializer_list<Point> locations);

        const Point& CityLocation(Index ind) const;

        unsigned int NrOfCities() const;
    private:
        std::vector<Point> cities_;
};
 
#endif /* MAP_H */
