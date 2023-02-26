#include <vector>
#include <iostream>
#include <cstddef>
#include <bitset>

#include "tcp_client_socket.hpp"

namespace net {

    TcpClientSocket::TcpClientSocket(const char *a_ipAddress, uint16_t a_port)
    : m_socketManager()
    {
        struct sockaddr_in address;

        memset(&address, 0, sizeof(address));
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(a_ipAddress);
        address.sin_port = htons(a_port);

        if (connect(m_socketManager.GetFD(), (struct sockaddr *)&address, sizeof(address)) == -1) {

            throw TcpClientSocketErr("connect()", "connectin error: connection failed, server is not running", errno);
        }
    }

    TcpClientSocket::TcpClientSocket(int a_fd)
    : m_socketManager(a_fd)
    {}

    static void CheckBytes(int readBytes) {

        if (readBytes <= 0) {

            // printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
            throw TcpClientSocketErr("recieve()", "connection no longer exists", errno);
        }
    }

    void TcpClientSocket::Send(std::vector<unsigned char> &a_container) {

        size_t numOfBytes = a_container.size();
        size_t counter;

        int sentBytes = send(m_socketManager.GetFD(), a_container.data(), a_container.size() * sizeof(std::vector<uint8_t>::value_type), 0);
        CheckBytes(sentBytes);

        counter = sentBytes;

        while(counter < numOfBytes) {

            sentBytes = send(m_socketManager.GetFD(), a_container.data(), a_container.size() - counter, 0);
            CheckBytes(sentBytes);
            counter += sentBytes;
        }
    }

    ssize_t TcpClientSocket::Receive(unsigned char* a_containerPtr, int a_bytesToRead) {

        ssize_t readBytes = recv(m_socketManager.GetFD(), a_containerPtr, a_bytesToRead, 0);

        CheckBytes(readBytes);

        return readBytes;
    }    

} //net