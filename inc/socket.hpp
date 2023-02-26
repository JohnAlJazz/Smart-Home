#ifndef SOCKET_H
#define SOCKET_H

#include <arpa/inet.h>
#include <sys/socket.h> /* socket */
#include <unistd.h> /* close  */
#include <cstring>
#include <cstdio>

namespace net {

class Socket {
public:
    Socket();
    Socket(int a_socket);

    Socket(const Socket& a_other) = delete;
    Socket& operator=(const Socket& a_other) = delete;
    ~Socket();
    
private:
    int m_socket;
    friend class TcpClientSocket;
    friend class TcpServerSocket;
    int GetFD();
};

}//net

#include "./inl/socket_inl.hxx"

#endif //SOCKET_H