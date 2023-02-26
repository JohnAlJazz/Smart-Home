#ifndef BADGE_SENSOR_AGENT_HPP
#define BADGE_SENSOR_AGENT_HPP

#include <memory>

#include "event.hpp"
#include "event_handler.hpp"
#include "abstract_agent.hpp"
#include "abs_subscribers.hpp"
#include "device_details.hpp"

namespace sensors {

class BadgeSensorAgent : public device::AbstractAgent {
public:
    explicit BadgeSensorAgent(device::DeviceDetails& a_device);
    
    void IncomingMsg(std::string& a_msg) override;
    void Connect(AbsEventHandler a_eventHandler, AbsSubscribers a_subscribers) override;

private:
    event::Event CreateEvent(const std::string& a_data);
    
private:
    AbsEventHandler m_eventHandler;
};

} //sensors

#endif /* BADGE_SENSOR_AGENT_HPP */