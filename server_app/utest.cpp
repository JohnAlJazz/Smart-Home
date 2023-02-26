#include <memory>

#include "app_server.hpp"
#include "config_streams.hpp"
#include "agent_creator_factory.hpp"

int main() {

    std::string sensorsAgentsConfig{"sensor_agents.ini"};    
    std::ifstream serverConfig("server.config");

    auto agentsFactory = std::make_shared<agentsFactory::AgentsFactory>(sensorsAgentsConfig);

    server::AppServer server{serverConfig, agentsFactory};

    server.Run();
    
    return 0;
}