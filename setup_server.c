#include <stdlib.h>
#include <unistd.h>

int main()
{
    const char *cmdNode = "gnome-terminal -- bash -c \"cd ./nodejs_server && npm install \
                             && npm run dev \
                        ; exec bash\" ";
    
    const char *runDb = "gnome-terminal -- bash -c \"mongod ; exec bash\" ";

    const char *cmdReact = "gnome-terminal -- bash -c \"cd ./web_app && npm install && npm start \
                        ; exec bash\" ";
                        
    const char *runServer = "gnome-terminal -- bash -c \"cd ./server_app && make all && ./utest \
                        ; exec bash\" ";

    system(runDb);
    system(cmdNode);
    system(cmdReact);
    system(runServer);

    return 0;
}

    //system(runSensors);

    