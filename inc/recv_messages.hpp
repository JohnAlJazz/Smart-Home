#ifndef RECV_MESSAGES_HPP
#define RECV_MESSAGES_HPP

#include <vector>
#include <memory>

#include "tcp_client_socket.hpp"

namespace net {

std::vector<unsigned char> Recv(std::unique_ptr<net::TcpClientSocket>* a_client);

} // namespace 

#endif /* RECV_MESSAGES_HPP */