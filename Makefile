prep:
	sudo apt install libpoco-dev && sudo apt-get install npm \
	&& sudo apt update \
	&& sudo apt install curl \
	&& curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.38.0/install.sh | bash \
	&& source ~/.bashrc \
	&& nvm install 16.14.2 \
	&& sudo apt update \
	&& sudo apt upgrade \
	&& sudo apt install sqlite3 \
	&& sudo apt-get install mongodb \
	&& sudo apt-get update \
	&& sudo service mongodb start \

#run server
EXEC_SERVER=setup_server.out
runserver: build_server run_server_execute

run_server_execute:
	./${EXEC_SERVER}

build_server: ${EXEC_SERVER}
${EXEC_SERVER}: setup_server.o
	gcc -o ${EXEC_SERVER} setup_server.c

setup_server.o: setup_server.c
	gcc -c setup_server.c


#################run sensors#############################
EXEC_SENSORS=setup_sensors.out
runsensors: build_sensors run_sensors_execute

run_sensors_execute:
	./${EXEC_SENSORS}

build_sensors: ${EXEC_SENSORS}
${EXEC_SENSORS}: setup_sensors.o
	gcc -o ${EXEC_SENSORS} setup_sensors.c

setup_sensors.o: setup_sensors.c
	gcc -c setup_sensors.c