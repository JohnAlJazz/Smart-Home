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
OBJS = utest.o event.o

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

utest : utest.cpp $(INC_DIR)/event.hpp $(SRC_DIR)/event/event.cpp 
clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean