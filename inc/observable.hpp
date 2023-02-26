#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <vector>
#include <string>
#include <cstdint>  //uint32_t
#include <memory>	//shared memory
#include <string>

#include "safeHashTable.hpp"
#include "abs_notifier.hpp"
#include "abstract_agent.hpp"

namespace observer {

class Observable : public AbsNotifier, public AbstractSubscribers {
private:
	using AgentPtr = std::shared_ptr<device::AbstractAgent>;

private:
	void Subscribe(const std::string& a_eventID, AgentPtr a_controller) override;
	void UnSubscribe(const std::string& a_eventID, AgentPtr a_controller) override;

	void Notify(std::shared_ptr<event::Event> a_event) override;

private:
	threads::SafeHashTable<std::string, std::vector<AgentPtr>> m_observableMap;
};

} //observer

#endif //OBSERVABLE_HPP