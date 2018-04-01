TEST_FOLDER=$(COMPETING_HOME)/tests
SRC_FOLDER=$(COMPETING_HOME)/src

INCLUDE_PATHS=-isystem $(GTEST_DIR)/include -I$(COMPETING_HOME)/include -I$(TEST_FOLDER)/include

OBJ_FOLDER=$(TEST_FOLDER)/objects

TST_OBJ=$(OBJ_FOLDER)/tests
SRC_OBJ=$(OBJ_FOLDER)/src

OPT_LEVEL=o0
LIBS=$(COMP_LIBS)/gtest/libgtest.a

#CPP=g++ $(INCLUDE_PATHS) -std=c++17 -g $(OPT_LEVEL)
CPP=g++ $(INCLUDE_PATHS) -pthread -std=c++17 -g

TEST_MAIN=$(TEST_FOLDER)/gtest_main.cpp 

define TEST_OBJECTS =
$(SRC_OBJ)/point.o \
$(SRC_OBJ)/salesman.o \
$(TST_OBJ)/PointTests.o \
$(TST_OBJ)/SalesmanTest.o
endef


test: $(TEST_OBJECTS)
	$(CPP) $(TEST_MAIN) $(TEST_OBJECTS) $(LIBS) -o $@

$(OBJ_FOLDER)%.o: $(COMPETING_HOME)%.cpp
	$(shell mkdir -p $(shell dirname $@))
	$(CPP) $< -MMD -c -o $@

clean:
	$(shell rm -rf $(OBJ_FOLDER))
