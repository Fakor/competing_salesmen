#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include <map>

#include "selector.h"
#include "map.h"

#include "utility.h"

using SelectorType = std::unique_ptr<Selector>;

class Engine{
    public:
        Engine(Map& map);

        void Setup();

        void AddSelector(SelectorType selector, unsigned int salesman_index);

        void SelectTargets();
        void PerformTurn();
	void PerformRound();

	void VisitCity(const Point* city);

        Scoreboard& GetScoreboard();
	bool RoundFinnished() const;
    private:
        Map& map_;
        std::vector<SelectorType> selectors_;

	UnvisitedCities cities_;

        Salesman* NextSalesman();

        int current_salesman_index{0};

        Scoreboard scoreboard_;
};
 
#endif /* ENGINE_H */
