#ifndef APP_DETECTOR_FACADE_HPP
#define APP_DETECTOR_FACADE_HPP

#include <fstream>

#include "abstract_handler.hpp"
#include "config_streams.hpp"
#include "event_detector.hpp"
#include "abstract_agents_factory.hpp"

namespace server {

class AppDetectorFacade {
private:
    using AgentsFactoryPtr = std::shared_ptr<agentsFactory::AbstractAgentsFactory>;

public:
    AppDetectorFacade(std::ifstream& a_serverConfig, AgentsFactoryPtr a_agentsFactory);
    AppDetectorFacade(const AppDetectorFacade& a_other) = default;
    AppDetectorFacade& operator=(const AppDetectorFacade& a_other) = default;

    std::shared_ptr<net::EventDetector> GetAppHandler();

private:
    std::ifstream& m_serverConfig;
    AgentsFactoryPtr m_agentsFactory;
};

class DefaultAcceptor : public net::Iacceptor {

    bool DoAccept(std::unique_ptr<net::TcpClientSocket>* a_client);    
};

} // server

#endif //APP_DETECTOR_FACADE_HPP 