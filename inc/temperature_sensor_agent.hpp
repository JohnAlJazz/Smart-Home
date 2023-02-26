#ifndef TEMPERATURE_SENSOR_AGENT_HPP
#define TEMPERATURE_SENSOR_AGENT_HPP

#include <memory>

#include "event.hpp"
#include "event_handler.hpp"
#include "abstract_agent.hpp"
#include "abs_subscribers.hpp"
#include "device_details.hpp"

namespace sensors {

class TemperatureSensorAgent : public device::AbstractAgent {
public:
    TemperatureSensorAgent(device::DeviceDetails& a_device);    
    void Connect(AbsEventHandler a_eventHandler, AbsSubscribers a_subscribers) override;
    void IncomingMsg(std::string& a_msg) override;

private:
    event::Event CreateEvent(const std::string& a_data);
    
private:
    AbsEventHandler m_eventHandler;
};

} //sensors

#include "inl/temperature_sensor_agent_inl.hxx"

#endif //TEMPERATURE_SENSOR_AGENT_HPP