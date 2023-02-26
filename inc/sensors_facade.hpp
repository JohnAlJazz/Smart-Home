#ifndef SENSORS_FACADE_HPP
#define SENSORS_FACADE_HPP

#include <memory>
#include <string>

#include "tcp_client_socket.hpp"

namespace sensors {

class SensorsFacade {
public:
    SensorsFacade(const char* a_ip, uint16_t a_port, std::string a_type);

    void Send(const std::string& a_msg);

private:           
    std::string m_type;
    net::TcpClientSocket m_client;
};

} //sensors

#endif //SENSORS_FACADE_HPP
