#include <unistd.h>

#include "badge_sensor.hpp"

namespace sensors {

BadgeSensor::BadgeSensor(const char* a_ip, uint16_t a_port, std::string a_type)
: m_facade(a_ip, a_port, a_type)
{}

void BadgeSensor::Send() {
    
    while(true) {

        srand(time(NULL)); 

        int badge = rand() % 3;

        if(badge == 0) {

            m_facade.Send("123456789");
        }  

        else if(badge == 1) {

            m_facade.Send("123456788");
        }

        else if(badge == 2) {

            m_facade.Send("123456787");
        }

        else if(badge == 3) {

            m_facade.Send("123456786");
        }

        sleep(3);
    }
}

} //sensors