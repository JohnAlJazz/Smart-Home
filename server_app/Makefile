CXX = g++
CC = $(CXX)

#dependencies:
DEPENDENCY1=tcp_client_socket
DEPENDENCY2=socket
DEPENDENCY3=server_app
DEPENDENCY4=epoll
DEPENDENCY5=tcp_server_socket
DEPENDENCY6=recv_messages
DEPENDENCY7=app_handler
DEPENDENCY8=agent_creator_factory
DEPENDENCY9=device_details
DEPENDENCY10=device_key_id_translator
DEPENDENCY11=device_config_parser
DEPENDENCY12=device_details
DEPENDENCY13=device_generator
DEPENDENCY14=pack_protocol
DEPENDENCY15=event
DEPENDENCY16=event_handler
DEPENDENCY17=thread_pool
DEPENDENCY18=task_controllers
DEPENDENCY19=unpack_protocol
DEPENDENCY20=server_config_parser
DEPENDENCY21=app_detector_facade
DEPENDENCY22=config_streams
DEPENDENCY25=temperature_sensor
DEPENDENCY26=sensors_facade
DEPENDENCY27=temperature_sensor_agent
DEPENDENCY28=observable
DEPENDENCY29=app_db
DEPENDENCY30=room_temperature_agent_controller
DEPENDENCY31=room_temperature_controller
DEPENDENCY32=abstract_controller
DEPENDENCY33=http_client
DEPENDENCY34=connect_agents

DEPENDENCY35=badge_sensor_agent
DEPENDENCY36=motion_sensor_agent

DEPENDENCY37=select

CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

LDLIBS = -pthread -lPocoFoundation  -lPocoNet  -lPocoNetSSL -lPocoUtil -lPocoXML -lPocoJSON \
		-l sqlite3

#src
SRC_DIR = ../src

INC_DIR = ../inc/

#net server
SRC_DIR_NET=../tcp_net_server/

#project src
SRC_DIR_SERVER=${SRC_DIR}/server_app/
SRC_DIR_DEVICE=${SRC_DIR}/device/
SRC_DIR_SENSORS=${SRC_DIR}/sensors/
SRC_DIR_EVENT=${SRC_DIR}/event/
SRC_DIR_CONTROLLERS=${SRC_DIR}/controllers/
SRC_DIR_OBSERVABLE=${SRC_DIR}/observer/

#config
CONFIG_DIR = ../config/

#http client dir
HTTP_CLIENT_DIR= ../http_client/

#agent factory
AGENT_FACTORY = ../agents_factory/

DS_DIR=../ds/

D_FILES= ${SRC_DIR_NET}*.d ${SRC_DIR_SERVER}*.d ${SRC_DIR_DEVICE}*.d \
			${SRC_DIR_SENSORS}*.d ${SRC_DIR_EVENT}*.d ${SRC_DIR_CONTROLLERS}*.d \
			${SRC_DIR_OBSERVABLE}*.d

TARGET = utest
OBJS = utest.o ${SRC_DIR_NET}${DEPENDENCY1}.o ${SRC_DIR_NET}${DEPENDENCY2}.o \
				${SRC_DIR_SERVER}${DEPENDENCY3}.o ${SRC_DIR_NET}${DEPENDENCY4}.o \
				${SRC_DIR_NET}${DEPENDENCY5}.o ${SRC_DIR_NET}${DEPENDENCY6}.o \
				${SRC_DIR_SERVER}${DEPENDENCY7}.o ${AGENT_FACTORY}${DEPENDENCY8}.o \
				${SRC_DIR_DEVICE}${DEPENDENCY9}.o ${AGENT_FACTORY}${DEPENDENCY10}.o \
				${AGENT_FACTORY}${DEPENDENCY11}.o ${SRC_DIR_DEVICE}${DEPENDENCY12}.o \
				${AGENT_FACTORY}${DEPENDENCY13}.o ${SRC_DIR_DEVICE}${DEPENDENCY14}.o \
				${SRC_DIR_EVENT}${DEPENDENCY15}.o  ${SRC_DIR_EVENT}${DEPENDENCY16}.o \
				${DS_DIR}${DEPENDENCY17}.o  ${SRC_DIR_CONTROLLERS}${DEPENDENCY18}.o \
				${SRC_DIR_DEVICE}${DEPENDENCY19}.o ${CONFIG_DIR}${DEPENDENCY20}.o \
				${SRC_DIR_SERVER}${DEPENDENCY21}.o ${CONFIG_DIR}${DEPENDENCY22}.o \
				${SRC_DIR_SENSORS}${DEPENDENCY25}.o ${SRC_DIR_SENSORS}${DEPENDENCY26}.o \
				${SRC_DIR_SENSORS}${DEPENDENCY27}.o ${SRC_DIR_OBSERVABLE}${DEPENDENCY28}.o \
				${SRC_DIR_DEVICE}${DEPENDENCY29}.o  ${SRC_DIR_CONTROLLERS}${DEPENDENCY30}.o \
				${SRC_DIR_CONTROLLERS}${DEPENDENCY31}.o \
				${SRC_DIR_CONTROLLERS}${DEPENDENCY32}.o ${HTTP_CLIENT_DIR}${DEPENDENCY33}.o \
				${SRC_DIR_SERVER}${DEPENDENCY34}.o ${SRC_DIR_SENSORS}${DEPENDENCY35}.o \
				${SRC_DIR_SENSORS}${DEPENDENCY36}.o ${SRC_DIR_NET}${DEPENDENCY37}.o				

all: $(TARGET)

$(TARGET): $(OBJS)

check: $(TARGET)
	./$(TARGET) -v

utest.o: utest.cpp

foo:
	echo ${D_FILES}

clean:
	@$(RM) $(TARGET) $(OBJS)
	rm ${OBJS} ${DEPENDS}
	

.PHONY: all check clean

DEPENDS = $(OBJS:%.o=%.d)

-include ${DEPENDS}