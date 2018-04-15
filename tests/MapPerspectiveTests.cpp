#include <gtest/gtest.h>

#include "map_perspective.h"

TEST(MapPerspectiveTest, Construction){
    Map map;
    
    EXPECT_EQ(0, map.NrOfSalesman());
    MapPerspective perspective{map, {1,2}};
    EXPECT_EQ(1, map.NrOfSalesman());
}
