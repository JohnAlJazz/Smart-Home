#include <thread>

#include "temperature_sensor.hpp"
#include "badge_sensor.hpp"
#include "motion_sensor.hpp"

#define IP "127.0.0.1"
#define PORT 8080

int main()
{
    std::string typeTemp {"temperature_1_a_1"};
    std::string typeBadge {"badge_sensor"};
    std::string typeMotion {"motion_sensor"};

    std::thread temperature([&typeTemp]() {sensors::TemperatureSensor temperatureSensor(IP, PORT, typeTemp);
    temperatureSensor.Send();});

    std::thread badge([&typeBadge](){sensors::BadgeSensor badgeSensor(IP, PORT, typeBadge);
    badgeSensor.Send();});

    std::thread motion([&typeMotion](){sensors::MotionSensor motionSensor(IP, PORT, typeMotion);
    motionSensor.Send();});

    temperature.join();
    badge.join();
    motion.join(); 
    
    return 0;
}