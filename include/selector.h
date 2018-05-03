#ifndef SELECTOR_H
#define SELECTOR_H 

#include "utility.h"
#include "salesman.h"

class Selector{
    public:
        virtual void ChooseTarget() = 0;

        void SetCities(UnvisitedCities* cities);
        void SetSalesman(Salesman* salesman);
        void SetTarget(City* city);

    protected:
        Salesman* salesman_;

        UnvisitedCities* cities_;
};
 
#endif 
