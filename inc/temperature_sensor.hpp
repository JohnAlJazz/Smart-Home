#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP

#include "abstract_sensor.hpp"
#include "sensors_facade.hpp"

namespace sensors {

class TemperatureSensor : public AbstractSensors { 
public:  
    TemperatureSensor(const char* a_ip, uint16_t a_port, std::string a_type);
    
    void Send();

private: 
    SensorsFacade m_facade;
    float m_temperature;        
};

} //sensors

#endif /* TEMPERATURE_SENSOR_HPP */