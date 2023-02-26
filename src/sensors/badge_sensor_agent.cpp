#include <chrono>

#include "badge_sensor_agent.hpp"

namespace sensors {

BadgeSensorAgent::BadgeSensorAgent(device::DeviceDetails& a_device) 
: device::AbstractAgent(a_device)
, m_eventHandler()
{}

void BadgeSensorAgent::Connect(AbsEventHandler a_eventHandler, AbsSubscribers a_subscribers) {

    //needed fo IncomingMsg()
    m_eventHandler = a_eventHandler;
}

void BadgeSensorAgent::IncomingMsg(std::string& a_msg) {

    event::Event event = CreateEvent(a_msg);
    m_eventHandler->AddEvent(event);
}

event::Event BadgeSensorAgent::CreateEvent(const std::string& a_data) {

    return{m_device.Type(), m_device.Floor() + '_' + m_device.Room(), a_data, BADGE, m_device.Log()};       
}

} //sensors