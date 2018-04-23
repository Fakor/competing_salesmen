#include <gtest/gtest.h>

#include "selector.h"

TEST(SelectorTest, Construction){
    Map map;
    
    EXPECT_EQ(0, map.NrOfSalesman());
    Selector perspective{map, {1,2}};
    EXPECT_EQ(1, map.NrOfSalesman());
}
