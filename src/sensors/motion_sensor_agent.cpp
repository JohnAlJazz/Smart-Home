#include <chrono>

#include "motion_sensor_agent.hpp"

namespace sensors {

MotionSensorAgent::MotionSensorAgent(device::DeviceDetails& a_device) 
: device::AbstractAgent(a_device)
, m_eventHandler()
{
}

void MotionSensorAgent::Connect(AbsEventHandler a_eventHandler, AbsSubscribers a_subscribers) {
    
    m_eventHandler = a_eventHandler;
}

event::Event MotionSensorAgent::CreateEvent(const std::string& a_data) 
{
    return{m_device.Type(), m_device.Floor() + '_'
    + m_device.Room(), a_data, MOTION, m_device.Log()};      
}

void MotionSensorAgent::IncomingMsg(std::string& a_msg) 
{
    event::Event event = CreateEvent(a_msg);
    m_eventHandler->AddEvent(event);
}

} //sensors