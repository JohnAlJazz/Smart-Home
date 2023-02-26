CXX = g++
CC = $(CXX)

# dependencies:
DEPENDENCY1=observable
DEPENDENCY2=event
DEPENDENCY3=device_key_id_translator
DEPENDENCY4=abstract_agent_controller

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
SRC_DIR = ../../src/observer/
SRC2_DIR = ../../src/event/
SRC3_DIR = ../../src/device/
SRC4_DIR = ../../src/controllers/

TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ${SRC2_DIR}${DEPENDENCY2}.o ${SRC3_DIR}${DEPENDENCY3}.o ${SRC4_DIR}${DEPENDENCY4}.o
OBJSD = utest.d ${SRC_DIR}${DEPENDENCY1}.d ${SRC2_DIR}${DEPENDENCY2}.d ${SRC3_DIR}${DEPENDENCY3}.d ${SRC4_DIR}${DEPENDENCY4}.d

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