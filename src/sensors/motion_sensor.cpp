#include "unistd.h"

#include "motion_sensor.hpp"

namespace sensors {

MotionSensor::MotionSensor(const char* a_ip, uint16_t a_port, std::string& a_type) 
: m_facade(a_ip, a_port, a_type)
{}

void MotionSensor::Send() {

    while(true) {

        srand(time(NULL)); 

        int movement = rand() % 10;

        if(movement == 1) {

            m_facade.Send("movement detected\n");
        }        

        sleep(2);
    }
}
    
} //sensors