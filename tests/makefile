INCLUDE_PATHS=

TEST_FOLDER=$(COMPETING_HOME)/tests
TEST_OBJECTS_FOLDER=$(TEST_FOLDER)/objects

CPP=g++ $(INCLUDE_PATHS) -std=c++17 -g
CPP_TEST=g++ -isystem $(GTEST_DIR)/include -pthread -std=c++17 -g
TEST_MAIN=$(TEST_FOLDER)/gtest_main.cpp 
TEST_LIBS=$(COMP_LIBS)/gtest/libgtest.a

test: $(TEST_OBJECTS_FOLDER)/LocationTests.o
	$(CPP_TEST) $(TEST_MAIN) $< $(TEST_LIBS) -o $@

$(TEST_OBJECTS_FOLDER)%.o: $(TEST_FOLDER)%.cpp
	$(shell mkdir -p $(TEST_OBJECTS_FOLDER))
	$(CPP_TEST) $@ $(LIB_TEST) -MMD -c -o $<

clean:
	$(shell rm -rf $(OBJECTS_FOLDER))
