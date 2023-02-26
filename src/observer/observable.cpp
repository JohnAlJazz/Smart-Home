#include <iostream>
#include <algorithm> //find

#include "observable.hpp"

namespace observer {
	
void Observable::Subscribe(const std::string& a_eventID, AgentPtr a_controller) {

	std::string k(a_eventID);

	if (m_observableMap.IsContained(a_eventID)) {

		auto vec = m_observableMap.getValue(a_eventID);
		vec.push_back(a_controller);
		
		m_observableMap.Update(k, vec);
	}

	else {

		std::vector<std::shared_ptr<device::AbstractAgent>> subscriberVec;

		subscriberVec.push_back(a_controller);
		m_observableMap.Insert(k, subscriberVec);
	}
}

void Observable::UnSubscribe(const std::string& a_eventID, AgentPtr a_controller) {

	auto vec = m_observableMap.getValue(a_eventID);
	vec.erase(std::find(vec.begin(), vec.end(), a_controller));
	
	m_observableMap.Update(a_eventID, vec);
}

static std::string ExtractKey(std::shared_ptr<event::Event>& a_event) {

	std::string key = a_event->GetLog() + "_" + a_event->GetLocation();	

	return key;
}

void Observable::Notify(std::shared_ptr<event::Event> a_event) {

	auto key = ExtractKey(a_event);
	auto subscribersVec = m_observableMap.getValue(key);

	for (const auto &e : subscribersVec) {

		e->GetEvent(a_event);
	}
}

} //observer
