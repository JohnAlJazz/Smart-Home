#ifndef DYNAMIC_PACK_PROTOCOL_HPP
#define DYNAMIC_PACK_PROTOCOL_HPP

#include <vector>
#include <string>

namespace device {
    std::vector<unsigned char> DynamicPack(std::vector<std::string>& a_payLoad);
} // device


#endif /* DYNAMIC_PACK_PROTOCOL_HPP */