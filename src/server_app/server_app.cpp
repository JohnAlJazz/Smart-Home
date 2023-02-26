#include <memory>

#include "app_server.hpp"
#include "event_detector.hpp"
#include "app_detector_facade.hpp"

namespace server {
    
AppServer::AppServer(std::ifstream& a_serverConfig, AgentsFactoryPtr a_agentsFactory)
: m_detectorFacade(a_serverConfig, a_agentsFactory)
{}

void AppServer::Run() {

    auto detector = m_detectorFacade.GetAppHandler();
    
    detector->Run();
}

} //server