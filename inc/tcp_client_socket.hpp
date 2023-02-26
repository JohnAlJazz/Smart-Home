#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <vector>

#include "socket.hpp"
#include "abstract_exeption.hpp"

namespace net {

class TcpClientSocket {
public:
    TcpClientSocket(const char* a_ipAddress, uint16_t a_port);
    TcpClientSocket(int a_fd);

    void Send(std::vector<unsigned char>& a_container);

    ssize_t Receive(unsigned char* a_containerPtr, int a_bytesToRead);
    int GetFD();

private:
    Socket m_socketManager;
    friend class Epoll;
};

class TcpClientSocketErr : public SMError {
public:
    TcpClientSocketErr(const char* fn, const char* w, int a_errno)
    : SMError(fn , w)
    , m_errno(a_errno)
    {}

    int m_errno;
};

} //net

#include "./inl/tcp_client_socket_inl.hxx"

#endif //CLIENT_HPP