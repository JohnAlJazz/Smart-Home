#ifndef APP_SERVER_HPP
#define APP_SERVER_HPP

#include <fstream>
#include <map>
#include <memory>

#include "config_streams.hpp"
#include "app_detector_facade.hpp"
#include "abstract_agents_factory.hpp"

namespace server {

class AppServer {
private:
    using AgentsFactoryPtr = std::shared_ptr<agentsFactory::AbstractAgentsFactory>;
    
public:
    AppServer(std::ifstream& a_serverConfig, AgentsFactoryPtr a_agentsFactory);
    AppServer(const AppServer& a_other) = delete;
    AppServer operator=(const AppServer& a_other) = delete;
    ~AppServer() = default;

    void Run();

private:
    AppDetectorFacade m_detectorFacade;    
};

} //server

#endif /* APP_SERVER_HPP */