CXX = g++
CC = $(CXX)

#dependencies:
DEPENDENCY1=tcp_client_socket
DEPENDENCY2=socket
DEPENDENCY4=badge_sensor
DEPENDENCY5=motion_sensor
DEPENDENCY6=temperature_sensor
DEPENDENCY7=sensors_facade
DEPENDENCY8=pack_protocol
DEPENDENCY9=app_db

CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

LDLIBS= -pthread -l sqlite3

# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

SRC_DIR = ../../../tcp_net_server/
INC_DIR = ../../../inc/

TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ${SRC_DIR}${DEPENDENCY2}.o \
				../../../src/sensors/${DEPENDENCY4}.o \
				../../../src/sensors/${DEPENDENCY5}.o ../../../src/sensors/${DEPENDENCY6}.o \
				../../../src/sensors/${DEPENDENCY7}.o ../../../src/device/${DEPENDENCY8}.o	\
				../../../src/device/${DEPENDENCY9}.o

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