CXX = g++
CC = $(CXX)

#dependencies:
DEPENDENCY1=sensor_agent_creator_factory
DEPENDENCY2=device_details
DEPENDENCY3=device_key_id_translator
DEPENDENCY4=device_config_parser
DEPENDENCY5=device_details
DEPENDENCY6=device_generator


CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

SRC_DIR = ../../src
INC_DIR = ../../inc/

TARGET = utest
OBJS = utest.o ${SRC_DIR}/server_app/${DEPENDENCY1}.o ${SRC_DIR}/device/${DEPENDENCY2}.o \
				${SRC_DIR}/device/${DEPENDENCY3}.o ${SRC_DIR}/device/${DEPENDENCY4}.o \
				${SRC_DIR}/device/${DEPENDENCY5}.o ${SRC_DIR}/device/${DEPENDENCY6}.o
				

all: $(TARGET)

$(TARGET): $(OBJS)

check: $(TARGET)
	./$(TARGET) -v

utest.o: utest.cpp

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean

DEPENDS = $(OBJS:%.o=%.d)

-include ${DEPENDS}