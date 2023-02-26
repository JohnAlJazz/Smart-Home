#ifndef PACK_PROTOCOL_HPP
#define PACK_PROTOCOL_HPP

#include <vector>
#include <string>
#include <cstdint>  //uint32_t

namespace device {

    std::vector<unsigned char> Pack(std::string a_id, const std::string& a_payLoad);

} //device

#endif /* PACK_PROTOCOL_HPP */