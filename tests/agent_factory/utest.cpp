#include <fstream>
#include <iostream>

#include "sensor_agent_creator_factory.hpp"

int main()
{
    std::ifstream file{"config.ini"};

    auto foo =  server::GenerareSensorAgents(file);

    std::cout << "bye\n";
    
    return 0;
}