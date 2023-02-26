CXX = g++
CC = $(CXX)

# dependencies:
DEPENDENCY1=http_client
DEPENDENCY2=event

CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic -Werror
CXXFLAGS+= -g3
CXXFLAGS+= -pthread

LDLIBS= -pthread -lPocoFoundation  -lPocoNet  -lPocoNetSSL -lPocoUtil -lPocoXML -lPocoJSON

INC_DIR = ../../inc/
SRC_DIR = ../../http_client/
DS_DIR = ../../ds/
CONTROLLERS_DIR=../../src/controllers/
EVENT_DIR=../../src/event/

#event:


TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ../../src/event/event.o

OBJSD = utest.d ${SRC_DIR}${DEPENDENCY1}.d

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