#ifndef SERVER_H
#define SERVER_H

#include <memory>

#include "socket.hpp"
#include "tcp_client_socket.hpp"

namespace net {

class TcpServerSocket {
public:
    TcpServerSocket(uint16_t a_port);
    void Listen();
    std::unique_ptr<TcpClientSocket> Accept();
    
private:
    Socket m_socketManager;
    struct sockaddr_in m_address;
    friend class Epoll;
    friend class Select;
    int GetFD();

private:
    void SetServer(uint16_t a_port);
};

} //net

class TcpServerSocketExeption : public SMError {
public:
    TcpServerSocketExeption(const char* fn, const char* w) : SMError(fn , w){};
};

#include "./inl/tcp_server_socket_inl.hxx"

#endif //SERVER_H