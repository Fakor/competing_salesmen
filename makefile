include build_targets

$(info $(SRC_OBJECTS))
$(info $(TEST_OBJECTS))

ifeq ($(MAKECMDGOALS), build)
MAIN=$(SRC_FOLDER)/main.cpp
EXECUTABLE=$(COMPETING_HOME)/main
OBJECTS=$(SRC_OBJECTS)
INCLUDE_PATHS=-I$(COMPETING_HOME)/include
endif

ifeq ($(MAKECMDGOALS), test)
MAIN=$(TEST_FOLDER)/gtest_main.cpp
EXECUTABLE=$(COMPETING_HOME)/test
OBJECTS=$(SRC_OBJECTS) $(TEST_OBJECTS)
INCLUDE_PATHS=-isystem $(GTEST_DIR)/include -I$(COMPETING_HOME)/include -I$(TEST_FOLDER)/include
LIBS=$(COMP_LIBS)/gtest/libgtest.a
endif

ifeq ($(MAKECMDGOALS), server)
MAIN=$(SRC_FOLDER)/server.cpp
EXECUTABLE=$(COMPETING_HOME)/server
OBJECTS=$(SRC_OBJECTS)
INCLUDE_PATHS=-I$(COMPETING_HOME)/include
LIBS=-lboost_system
endif

ifeq ($(MAKECMDGOALS), cruncher)
MAIN=$(SRC_FOLDER)/cruncher.cpp
EXECUTABLE=$(COMPETING_HOME)/cruncher
OBJECTS=$(SRC_OBJECTS)
INCLUDE_PATHS=-I$(COMPETING_HOME)/include
endif

TEST_LIBS=$(COMP_LIBS)/gtest/libgtest.a

CPP=g++ $(INCLUDE_PATHS) -pthread -std=c++17 -g

$(info CC $(CPP))

DEPENDENCY_FILES=$(patsubst %.o,%.d,$(OBJECTS))

build test server cruncher: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(MAIN)
	$(CPP) $(MAIN) $(OBJECTS) $(LIBS) -o $@

$(OBJ_FOLDER)%.o: $(COMPETING_HOME)%.cpp
	$(shell mkdir -p $(shell dirname $@))
	$(CPP) $< -MMD -c -o $@

clean:
	$(shell rm -rf $(OBJ_FOLDER))

-include $(DEPENDENCY_FILES)
