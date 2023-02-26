#include <iostream>

#include "app_handler.hpp"
#include "recv_messages.hpp"
#include "tcp_client_socket.hpp"
#include "unpack_protocol.hpp"

namespace net {

AppHandler::AppHandler(AgentsMap a_agentsMap)
: m_agents(a_agentsMap)   
{}

void AppHandler::HandleIncoming(std::unique_ptr<TcpClientSocket>* a_client) {

    std::vector<unsigned char> msg;

    try {

        msg = Recv(a_client);
    }

    catch(const TcpClientSocketErr& e) {
        
        throw;
    }

    std::pair<std::string,std::string> unpackedData = device::Unpack(msg);

    std::cout << "id = " << unpackedData.first << "\n";
    std::cout << "data = " << unpackedData.second << "\n";
    
    std::shared_ptr<device::AbstractAgent> agent = m_agents.get()->at(unpackedData.first);
    
    agent->IncomingMsg(unpackedData.second);
}

} //server