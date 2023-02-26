#include "dynamic_pack_protocol.hpp"

namespace device {

template <typename T>
void InsertSize(T& a_message, std::vector<unsigned char>& packedData)
{
    size_t messageSize = a_message.size();

    unsigned char *byteSize = reinterpret_cast<unsigned char *>(&messageSize);

    for (size_t i = 0; i < sizeof(size_t) ; i++) {
        packedData.push_back(byteSize[i]);
    }
}

template <typename T>
void InsertPayload(T& a_message, std::vector<unsigned char>& packedData)
{
    typename T::iterator begin = a_message.begin();
    typename T::iterator end = a_message.end();

    while (begin != end)
    {
        packedData.push_back(*begin);
        ++begin;
    }
}

static void MakeMessage(std::vector<std::string>& a_payLoad,std::vector<unsigned char> packedData)
{
    InsertSize(a_payLoad[0],packedData);
    InsertPayload(a_payLoad[0],packedData);

    InsertSize(a_payLoad[1],packedData);
    InsertPayload(a_payLoad[1],packedData);

    InsertSize(a_payLoad[2],packedData);
    InsertPayload(a_payLoad[2],packedData);

    InsertSize(a_payLoad[3],packedData);
    InsertPayload(a_payLoad[3],packedData);

    InsertSize(a_payLoad[4],packedData);
    InsertPayload(a_payLoad[4],packedData);

    InsertSize(a_payLoad[5],packedData);
    InsertPayload(a_payLoad[5],packedData);

}

std::vector<unsigned char> DynamicPack(std::vector<std::string>& a_payLoad)
{
    if (a_payLoad.size() != 6) {
        throw;
    }

    std::vector<unsigned char> message;

    ssize_t type = -1;

    unsigned char *byteSize = reinterpret_cast<unsigned char *>(&type);
    
    for (size_t i = 0; i < sizeof(size_t) ; i++) {
        message.push_back(byteSize[i]);
    }
    
    MakeMessage(a_payLoad,message);

    std::vector<unsigned char> packedMessage;
    InsertSize(packedMessage,packedMessage);
    InsertPayload(message,packedMessage);
    
    return packedMessage;
}

} // device