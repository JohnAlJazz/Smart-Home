#include "dynamic_unpack_protocol.hpp"

namespace device {

using IterData = std::vector<unsigned char>::iterator;

void PushMsg(IterData& a_vecIter, std::vector<std::string>& a_data)
{
    size_t *size = reinterpret_cast<size_t *>(&a_vecIter);

    a_vecIter += sizeof(size_t);

    std::string msg;

    for (size_t i = 0; i < *size; i++) {
        msg += *a_vecIter;
        ++a_vecIter;
    }
    
    a_data.push_back(msg);
}

std::vector<std::string> DynamicUnPack(std::vector<unsigned char>& a_data)
{
    std::vector<std::string> data;

    IterData vecIter = a_data.begin();

    vecIter += sizeof(size_t) * 2;

    PushMsg(vecIter,data);
    PushMsg(vecIter,data);
    PushMsg(vecIter,data);
    PushMsg(vecIter,data);
    PushMsg(vecIter,data);
    PushMsg(vecIter,data);

    return data;
}
} // device