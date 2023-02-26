#ifndef SENSOR_AGENT_CREATOR_FACTORY_HPP
#define SENSOR_AGENT_CREATOR_FACTORY_HPP

#include <map>
#include <memory>
#include <fstream>

#include "abstract_agent.hpp"
#include "abs_subscribers.hpp"
#include "abstract_event_handler.hpp"
#include "abstract_agents_factory.hpp"

namespace agentsFactory {

class AgentsFactory : public AbstractAgentsFactory {
private:
    using ConfigFile = std::ifstream&;
    using SubPtr = std::shared_ptr<observer::AbstractSubscribers>;
    using EventHandlerPtr = std::shared_ptr<event::AbstractEventHandler>;
    using DbHandler = device::AppDB&;    

public:
    AgentsFactory(std::string& a_filePath);
    AgentsMapPtr GenerateAgentsMap(device::AppDB a_dataBase) override;

private:
    std::ifstream m_configFile;
};

} //agentsFactory

#endif /* SENSORAGENTCREATORFACTORY_HPP */

