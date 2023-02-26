CXX = g++
CC = $(CXX)

# dependencies:
DEPENDENCY1=sensor_pack_protocol
DEPENDENCY2=sensor_agent_unpack_protocol
DEPENDENCY3=thread_pool
DEPENDENCY4=task_controllers
DEPENDENCY5=event

CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic -Werror
CXXFLAGS+= -g3
CXXFLAGS+= -pthread

LDLIBS= -pthread

INC_DIR = ../../inc/
SRC_DIR = ../../src/sensors/
DS_DIR = ../../ds/
CONTROLLERS_DIR=../../src/controllers/
EVENT_DIR=../../src/event/

TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ${SRC_DIR}${DEPENDENCY2}.o \
				 ${DS_DIR}${DEPENDENCY3}.o ${CONTROLLERS_DIR}${DEPENDENCY4}.o \
				 ${EVENT_DIR}${DEPENDENCY5}.o



OBJSD = utest.d ${SRC_DIR}${DEPENDENCY1}.d ${SRC_DIR}${DEPENDENCY2}.d

all: $(TARGET)

$(TARGET): $(OBJS)

check: $(TARGET)
	./$(TARGET) -v

utest.o: utest.cpp

clean:
	@$(RM) $(TARGET) $(OBJS) $(OBJSD)

.PHONY: all check clean 

DEPENDS = $(OBJS:%.o=%.d)

-include ${DEPENDS}