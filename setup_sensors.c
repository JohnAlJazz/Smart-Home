#include <stdlib.h>

int main()
{
    const char *runSensors = "gnome-terminal -- bash -c \"cd ./sensors && make all && ./utest \
                        ; exec bash\" ";
    system(runSensors);
    
    return 0;
}