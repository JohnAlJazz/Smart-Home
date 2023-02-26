#include "temperature_sensor.hpp"
#include "badge_sensor.hpp"
#include "motion_sensor.hpp"

#include <thread>

int main() {
    std::string type {"temperature_1_a_1"};
    sensors::TemperatureSensor temprature {"127.0.0.1",8080,type};
    temprature.Send();



   /*  std::thread temperature([]() {sensors::TemperatureSensor temperatureSensor("127.0.0.1", 8080, 0);
                                    temperatureSensor.Send();});

    std::thread badge([]()       {sensors::BadgeSensor badgeSensor("127.0.0.1", 8080, 1);
                                    badgeSensor.Send();});

    std::thread motion([]()      {sensors::MotionSensor motionSensor("127.0.0.1", 8080, 2);
                                    motionSensor.Send();});

    temperature.join();
    badge.join();
    motion.join(); */
    
    return 0;
}