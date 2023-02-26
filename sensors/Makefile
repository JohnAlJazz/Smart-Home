CXX = g++
CC = $(CXX)

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

SRC_DIR = ../src/
INC_DIR = ../inc/

#dependencies:
DEPENDENCY1=tcp_client_socket
DEPENDENCY2=socket

DEPENDENCY3=badge_sensor
DEPENDENCY4=motion_sensor
DEPENDENCY5=temperature_sensor
DEPENDENCY6=sensors_facade

DEPENDENCY7=pack_protocol
DEPENDENCY8=app_db
DEPENDENCY9=dynamic_pack_protocol

#depencencies dirs:
NET_DIR= ../tcp_net_server/

#sensors source dirs:
SRC_SENSORS= ${SRC_DIR}/sensors/
SRC_DEVICE= ${SRC_DIR}/device/


TARGET = utest
OBJS = utest.o 	${NET_DIR}${DEPENDENCY1}.o ${NET_DIR}${DEPENDENCY2}.o \
				${SRC_SENSORS}${DEPENDENCY3}.o ${SRC_SENSORS}${DEPENDENCY4}.o \
				${SRC_SENSORS}${DEPENDENCY5}.o ${SRC_SENSORS}${DEPENDENCY6}.o \
				${SRC_DEVICE}${DEPENDENCY7}.o ${SRC_DEVICE}${DEPENDENCY8}.o \
				${SRC_DEVICE}${DEPENDENCY9}.o
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