#ifndef UNPACK_PROTOCOL_HPP
#define UNPACK_PROTOCOL_HPP

#include <vector>
#include <string>
#include <utility>  //pair
#include <cstdint>  //uint32_t

namespace device {

    std::pair<std::string, std::string> Unpack(std::vector<unsigned char> a_vec);

}   //device

#endif /* UNPACK_PROTOCOL_HPP */