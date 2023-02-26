#include <memory>
#include <time.h>
#include <unistd.h>

#include "temperature_sensor.hpp"

namespace sensors {

TemperatureSensor::TemperatureSensor(const char* a_ip, uint16_t a_port, std::string a_type)
: m_facade(a_ip, a_port, a_type)
, m_temperature(18)
{
}

void TemperatureSensor::Send() {

    while(true) {

        srand(time(NULL));

        if(m_temperature == 30) {

            m_temperature = 18;
        }        

        float random = rand() % 2;
        
        if(random == 1) {

            m_facade.Send(std::to_string(m_temperature));
            m_temperature += 0.5;
        }  

        sleep(3);
    }
}

} //sensors