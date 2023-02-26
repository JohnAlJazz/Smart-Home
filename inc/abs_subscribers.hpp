#ifndef ABS_SUBSCRIBERS_HPP
#define ABS_SUBSCRIBERS_HPP

#include <memory>
#include <string>

#include "abstract_agent.hpp"

namespace observer {

class AbstractSubscribers {
private:
	using String = const std::string&;
	using AbsAgent = std::shared_ptr<device::AbstractAgent>;

public:
	virtual ~AbstractSubscribers() = default;

	virtual void Subscribe(String a_eventID, AbsAgent a_controller) = 0;
	virtual void UnSubscribe(String a_eventID, AbsAgent a_controller) = 0;
};

} //observer

#endif //ABS_SUBSCRIBERS_HPP