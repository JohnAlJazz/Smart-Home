#ifndef DEVICE_PARSER_HPP
#define DEVICE_PARSER_HPP

#include <string>

namespace device {

class DeviceConfigParser {
public:
    DeviceConfigParser() = default;
    std::string ParseId(std::string& a_other);
    std::string ParseStringData(std::string& a_other);
    int ParseIntData(std::string& a_other);
};

} //device

#endif /* DEVICE_PARSER_HPP */