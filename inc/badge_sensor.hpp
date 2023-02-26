#ifndef BADGE_SENSOR_HPP
#define BADGE_SENSOR_HPP

#include "abstract_sensor.hpp"
#include "sensors_facade.hpp"

namespace sensors {

class BadgeSensor : public AbstractSensors {
public:     
    BadgeSensor(const char* a_ip, uint16_t a_port, std::string a_type);

    void Send();

private:
    SensorsFacade m_facade;
};

} //sensors

#endif //BADGE_SENSOR_HPP 