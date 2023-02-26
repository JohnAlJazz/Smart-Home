#include "tcp_server_socket.hpp"

namespace net {

TcpServerSocket::TcpServerSocket(uint16_t a_port)
: m_socketManager()
, m_address()
{
    SetServer(a_port);
}

void TcpServerSocket::Listen()
{
    if (listen(m_socketManager.GetFD(), 1021) == -1) {
        
        throw TcpServerSocketExeption("listen()", "listen fail");
    }
    
    std::cout << "server is listening...\n";
}

std::unique_ptr<TcpClientSocket> TcpServerSocket::Accept()
{
    int length = sizeof(m_address);
    
    int clientSocket = accept(m_socketManager.GetFD(), (struct sockaddr *)&m_address, (socklen_t *)&length);
    
    if (clientSocket < 0) {

        throw TcpServerSocketExeption("accept()", "client socket fail");
    }

    return std::make_unique<TcpClientSocket>(clientSocket);
}

void TcpServerSocket::SetServer(uint16_t a_port) {

    memset(&m_address, 0, sizeof(m_address));
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = INADDR_ANY;
    m_address.sin_port = htons(a_port);

    int a_optval = 1;

    if (setsockopt(m_socketManager.GetFD(), SOL_SOCKET, SO_REUSEADDR, &a_optval, sizeof(a_optval)) < 0) {

        throw TcpServerSocketExeption("setsockopt()", "port reuse fail");
    }

    if (bind(m_socketManager.GetFD(),(struct sockaddr *)&m_address, sizeof(m_address)) < 0) {

        throw TcpServerSocketExeption("bind()", "bind failed");
    }
}

} //net
