#ifndef MAP_PERSPECTIVE_H
#define MAP_PERSPECTIVE_H

#include "map.h"
#include "salesman.h"

class MapPerspective{
    public:
        MapPerspective(Map& map, Salesman salesman);
    private:
        Salesman salesman_;
        const Map& map_;
};
 
#endif /* MAP_PERSPECTIVE_H */
