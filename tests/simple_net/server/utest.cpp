#include "tcp_server_socket.hpp"

int main()
{
    net::TcpServerSocket server{8080};
    server.Listen();
    server.Accept();

    return 0;
}