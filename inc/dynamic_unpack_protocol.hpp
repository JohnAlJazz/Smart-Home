#ifndef DYNAMIC_UNPACK_PROTOCOL_HPP
#define DYNAMIC_UNPACK_PROTOCOL_HPP

#include <vector>
#include <string>

namespace device {
    std::vector<std::string> DynamicUnPack(std::vector<unsigned char>& a_data);
} // device


#endif /* DYNAMIC_UNPACK_PROTOCOL_HPP */