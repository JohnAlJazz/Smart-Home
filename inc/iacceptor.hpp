#ifndef IACCEPTOR_HPP
#define IACCEPTOR_HPP

#include <memory>
#include "tcp_client_socket.hpp"

namespace net {
    
class Iacceptor {
public:
    virtual bool DoAccept(std::unique_ptr<TcpClientSocket>*a_client) = 0;
};

} //net

#endif //IACCEPTOR_HPP