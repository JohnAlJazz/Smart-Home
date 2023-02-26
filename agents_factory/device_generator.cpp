#include <fstream>

#include "device_generator.hpp"

namespace device {

DeviceDetails GenerateDevice(std::ifstream& a_sensors, DeviceConfigParser& a_parser) {

    std::string line;
    std::getline(a_sensors, line);
    std::string id = a_parser.ParseId(line);

    std::getline(a_sensors, line);
    std::string type = a_parser.ParseStringData(line);    

    std::getline(a_sensors, line);
    std::string room = a_parser.ParseStringData(line);

    std::getline(a_sensors, line);
    std::string floor = a_parser.ParseStringData(line);

    std::getline(a_sensors, line);
    std::string log = a_parser.ParseStringData(line);

    std::getline(a_sensors, line);
    std::string config = a_parser.ParseStringData(line);

    return {id, type, room, floor, log, config};
}
    
} //device
