CXX = g++
CC = $(CXX)

CPPFLAGS = -I$(INC_DIR)
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3
CXXFLAGS+= -pthread


LDFLAGS =
LDLIBS = 

INC_DIR = ../../inc
SRC_DIR = ../../src

TARGET = utest
OBJS = utest.o abstract_controller.o room_temperature_controller.o abstract_agent_controller.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(INC_DIR)/abstract_controller.hpp  $(INC_DIR)/abstract_agent_controller.hpp $(INC_DIR)/room_temperature_agent_controller.hpp $(INC_DIR)/abstract_agent_controller.hpp $(INC_DIR)/room_temperature_controller.hpp $(INC_DIR)/event.hpp $(SRC_DIR)/event/event.cpp $(SRC_DIR)/controllers/room_temperature_controller.cpp $(SRC_DIR)/controllers/room_temperature_agent_controller.cpp $(SRC_DIR)/controllers/abstract_agent_controller.cpp $(SRC_DIR)/controllers/abstract_controller.cpp 
clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean