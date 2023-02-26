#ifndef APP_HANDLER_HPP
#define APP_HANDLER_HPP

#include <map>
#include <memory>

#include "abstract_agent.hpp"
#include "abstract_handler.hpp"
#include "abstract_event_handler.hpp"

namespace net {

class AppHandler : public AbstractHandler {
private:
    using AgentsMap = std::shared_ptr<std::map<std::string,std::shared_ptr<device::AbstractAgent>>>;

public:
    AppHandler(AgentsMap a_agentsMap);
    
    void HandleIncoming(std::unique_ptr<TcpClientSocket>* a_client) override;

private:
    AgentsMap m_agents;
};

} //net

#endif /* APP_HANDLER_HPP */