#include <gtest/gtest.h>

#include "utility.h"
#include "salesman.h"
#include "basic_selectors.h"

TEST(SelectorTest, LastTargetNotPresent){
  Closest selector;

  City city1{1,0};
  City city2{2,0};

  Salesman salesman{0,0};
  
  UnvisitedCities cities{&city1, &city2};

  selector.SetCities(&cities);
  selector.SetSalesman(&salesman);
  selector.SetTarget(&city1);

  cities.erase(cities.begin());

  EXPECT_FALSE(selector.LastTargetPresent());
}

TEST(SelectorTest, LastTargetPresent){
  Closest selector;

  City city1{1,0};
  City city2{2,0};

  Salesman salesman{0,0};
  
  UnvisitedCities cities{&city1, &city2};

  selector.SetCities(&cities);
  selector.SetSalesman(&salesman);
  selector.SetTarget(&city2);

  cities.erase(cities.begin());

  EXPECT_TRUE(selector.LastTargetPresent());
}
