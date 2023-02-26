#ifndef MOTION_SENSOR_HPP
#define MOTION_SENSOR_HPP

#include "abstract_sensor.hpp"
#include "sensors_facade.hpp"

namespace sensors {

class MotionSensor : public AbstractSensors {
public:  
    MotionSensor(const char* a_ip, uint16_t a_port, std::string& a_type);
    void Send();
    
private:
    SensorsFacade m_facade;
};

} //sensors

#endif /* MOTION_SENSOR_HPP */