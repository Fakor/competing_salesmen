#include "selector.h"

Selector::Selector(Map& map, Salesman salesman)
: map_{map}, salesman_{salesman}
{
    map.AddSalesman(&salesman);
}
