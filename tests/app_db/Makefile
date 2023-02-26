CXX = g++
CC = $(CXX)

# dependencies:
DEPENDENCY1=app_db

CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
# CXXFLAGS+= -Wall -pedantic -Werror
CXXFLAGS+= -g3

LDLIBS+= -l sqlite3

INC_DIR = ../../inc/
SRC_DIR = ../../src/device/

TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o
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