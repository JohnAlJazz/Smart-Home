#ifndef DEVICE_GENERATOR_HPP
#define DEVICE_GENERATOR_HPP

#include "device_details.hpp"
#include "device_config_parser.hpp"

namespace device {

DeviceDetails GenerateDevice(std::ifstream& a_sensors, DeviceConfigParser& a_parser);

} //device

#endif /* DEVICE_GENERATOR_HPP */