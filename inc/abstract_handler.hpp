#ifndef ABSTRACT_HANDLER_HPP
#define ABSTRACT_HANDLER_HPP

#include <memory>

#include "tcp_client_socket.hpp"

namespace net {

struct AbstractHandler {

    virtual ~AbstractHandler() = default;
    
    virtual void HandleIncoming(std::unique_ptr<TcpClientSocket>* a_client) = 0;
};

} //net

#endif //ABSTRACT_HANDLER_HPP