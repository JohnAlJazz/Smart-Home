#include "connect_agents.hpp"

namespace server {

void ConnectAgents(AgentsMapPtr a_agentsMap, AbstractSubscriberPtr a_subscriber, EventHandlerPtr a_eventHandler) {
    
    auto begin = a_agentsMap->begin();
    auto end = a_agentsMap->end();

    while(begin != end) {
        
        a_agentsMap->at(begin->first)->Connect(a_eventHandler, a_subscriber);
        ++begin;
    }
}

} //server