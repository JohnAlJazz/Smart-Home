#include <iostream>

#include "sensors_facade.hpp"
#include "pack_protocol.hpp"

namespace sensors {

SensorsFacade::SensorsFacade(const char* a_ip, uint16_t a_port, std::string a_type)
: m_type(a_type)
, m_client(a_ip, a_port)
{}

void SensorsFacade::Send(const std::string& a_msg) {    
    
    std::vector<unsigned char> data = device::Pack(m_type, a_msg);
    
    try {

        m_client.Send(data);
    }

    catch(...) {
        
        printf("%s\n", strerror(errno));
        close(m_client.GetFD());
        throw;
    }
}

} // sensors