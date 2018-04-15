#include "map_perspective.h"

MapPerspective::MapPerspective(Map& map, Salesman salesman)
: map_{map}, salesman_{salesman}
{
    map.AddSalesman(&salesman);
}
