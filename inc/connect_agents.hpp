#ifndef CONNECT_AGENTS_HPP
#define CONNECT_AGENTS_HPP

#include <memory>
#include <map>
#include <string>

#include "abstract_agent.hpp"
#include "abstract_event_handler.hpp"
#include "abs_subscribers.hpp"

namespace server {

using AgentsMapPtr = std::shared_ptr<std::map<std::string, std::shared_ptr<device::AbstractAgent>>>;
using EventHandlerPtr = std::shared_ptr<event::AbstractEventHandler>;
using AbstractSubscriberPtr = std::shared_ptr<observer::AbstractSubscribers>;

void ConnectAgents(AgentsMapPtr a_agentsMap, AbstractSubscriberPtr a_subscriber, EventHandlerPtr a_eventHandler);

} //server

#endif //CONNECT_AGENTS_HPP