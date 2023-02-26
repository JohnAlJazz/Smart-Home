#include "recv_messages.hpp"
#include "tcp_client_socket.hpp"

namespace net {

std::vector<unsigned char> Recv(std::unique_ptr<net::TcpClientSocket>* a_client) {

    //initiate a 8 bytes vec to store the size of the msg
    std::vector<unsigned char> msg(sizeof(uint64_t));

    //ptr to 1st byte of the vector
    auto responsePtr = msg.data();

    //read 8 bytes from client to get the msg size
    unsigned long total = 0;
    
    while (total < sizeof(double)) {

        int readBytes;

        try {
            
            readBytes = (*a_client)->Receive(responsePtr, sizeof(double) - total);
            responsePtr += readBytes;
            total += readBytes;
        }

        catch(...) {

            throw;
        }    
    }

    //ptr to first 8 bytes
    uint64_t *temp = reinterpret_cast<uint64_t*>(&msg[0]);       
    //value in first 8 bytes -> msg size 
    uint64_t msgLen = *temp;

    msg.resize(sizeof(double) + *temp);
    
    auto msgPtr = msg.data();
    //increment ptr to 9th byte - where msg starts
    msgPtr += sizeof(double);

    //read msg byte by byte
    size_t counter = 0;
    while (counter < msgLen) {

        ssize_t readBytes;

        try {

            readBytes = (*a_client)->Receive(msgPtr ,msgLen - counter);
            msgPtr += readBytes;
            counter += readBytes;
        }

        catch(const TcpClientSocketErr& e) {    

           throw;
        }
    }
        
    return msg;
}

} //net