#ifndef ABSTRACT_AGENTS_FACTORY_HPP
#define ABSTRACT_AGENTS_FACTORY_HPP

#include <memory>
#include <map>
#include <string>

#include "abstract_agent.hpp"
#include "app_db.hpp"

namespace agentsFactory {

class AbstractAgentsFactory {
protected:
    using AgentMap = std::map<std::string,std::shared_ptr<device::AbstractAgent>>;
    using AgentsMapPtr = std::shared_ptr<AgentMap>;
    
public:
    virtual AgentsMapPtr GenerateAgentsMap(device::AppDB a_dataBase) = 0;

    ~AbstractAgentsFactory() = default;
};

} //agentsFactory

#endif //ABSTRACT_AGENTS_FACTORY_HPP