#ifndef TEMPERATURE_SENSOR_AGENT_INL_HXX
#define TEMPERATURE_SENSOR_AGENT_INL_HXX

namespace sensors {
    
inline TemperatureSensorAgent::TemperatureSensorAgent(device::DeviceDetails& a_device) 
: device::AbstractAgent(a_device)
, m_eventHandler()
{

}

inline void TemperatureSensorAgent::Connect(AbsEventHandler a_eventHandler, AbsSubscribers a_subscribers) 
{
    m_eventHandler = a_eventHandler;
}

} //sensors

#endif //TEMPERATURE_SENSOR_AGENT_INL_HXX