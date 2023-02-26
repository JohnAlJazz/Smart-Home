#include "selcet.hpp"

namespace net {

Select::Select(NetServer a_server, AppHandler a_handler, AcceptorHandler a_acceptor)
: EventDetector(a_server, a_handler, a_acceptor)
, m_readFd()
, m_temp()
{
    FD_ZERO(&m_readFd); 

    AddFdToFdSet(m_serverSocket->GetFD());

    m_serverSocket->Listen();
}

static void HandleErrors(int a_nfds) {

    if (a_nfds == -1) {

        throw SelectExceptions("select()", "select failed");
    }
}

void Select::Run() {       

    while(true) {

        m_temp = m_readFd;  

        HandleErrors(select(FD_SETSIZE, &m_temp, NULL, NULL, NULL));

        HandleIO();        
    }
}

void Select::AcceptConnections() {

    auto client = m_serverSocket->Accept();
    int clientFd = client->GetFD();

    if(!m_acceptor->DoAccept(&client)) {

        std::cout << "client fd: " << clientFd << " is not accepted\n";

        close(clientFd);

        return;
    }    

    AddFdToFdSet(clientFd); 

    AddClientToMap(clientFd, std::move(client));         
}

void Select::GetData(int a_fd) {

    try {

        m_handler->HandleIncoming(&m_clients[a_fd]);
    }

    catch(const TcpClientSocketErr& e) {

        std::cout << e.what() << '\n';

        FD_CLR(a_fd, &m_readFd);
    }
}

void Select::HandleIO() {

    int serverFd = m_serverSocket->GetFD();

    for(int i = 0; i < FD_SETSIZE; ++i) {
        
        if(FD_ISSET(i, &m_temp)) {

            //someone wants to connect
            if(i == serverFd) {

                AcceptConnections();
            }

            //someone sent data
            else {

                GetData(i);
            }
        }
    }
}

void Select::AddFdToFdSet(int a_fd) {

    FD_SET(a_fd, &m_readFd);
}

void Select::AddClientToMap(int a_fd, Clientptr a_client) {

    m_clients[a_fd] = std::move(a_client);
}

SelectExceptions::SelectExceptions(const char* func, const char* what) 
: SMError(func, what)
{}

} //net