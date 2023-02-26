#include <chrono>

#include "temperature_sensor_agent.hpp"

namespace sensors {

event::Event TemperatureSensorAgent::CreateEvent(const std::string& a_data)
{    
    return{m_device.Type(), m_device.Floor() + '_'
    + m_device.Room(), a_data, TEMPERATURE,m_device.Log()};    
}

void TemperatureSensorAgent::IncomingMsg(std::string& a_msg)
{
    event::Event event = CreateEvent(a_msg);
    m_eventHandler->AddEvent(event);
}

} //sensors