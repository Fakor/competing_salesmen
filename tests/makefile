INCLUDE_PATHS=-isystem $(GTEST_DIR)/include -I$(COMPETING_HOME)/include -I$(TEST_FOLDER)/include

OPT_LEVEL=o0
LIBS=$(COMP_LIBS)/gtest/libgtest.a

CPP=g++ $(INCLUDE_PATHS) -pthread -std=c++17 -g

TEST_MAIN=$(TEST_FOLDER)/gtest_main.cpp 

ALL_OBJECTS=$(TEST_OBJECTS) $(SRC_OBJECTS)

DEPENDENCY_FILES=$(patsubst %.o,%.d,$(ALL_OBJECTS))

test: $(ALL_OBJECTS)
	$(CPP) $(TEST_MAIN) $(ALL_OBJECTS) $(LIBS) -o $@

$(OBJ_FOLDER)%.o: $(COMPETING_HOME)%.cpp
	$(shell mkdir -p $(shell dirname $@))
	$(CPP) $< -MMD -c -o $@

clean:
	$(shell rm -rf $(OBJ_FOLDER))

-include $(DEPENDENCY_FILES)
