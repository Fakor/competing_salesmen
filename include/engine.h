#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

#include "selector.h"
#include "map.h"

using SelectorType = std::unique_ptr<Selector>;

class Engine{
    public:
        Engine(Map& map);

        void Setup();

        void AddSelector(SelectorType selector, unsigned int salesman_index);

        void SelectTargets();
        void PerformTurn();

    private:
        Map& map_;
        std::vector<SelectorType> selectors_;

        Salesman* NextSalesman();

        int current_salesman_index{0};
};
 
#endif /* ENGINE_H */
