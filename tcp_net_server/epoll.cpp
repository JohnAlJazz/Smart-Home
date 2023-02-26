#include <fcntl.h>
#include <fstream>
#include <ostream>

#include "epoll.hpp"

int global = 1;

namespace net {

Epoll::Epoll(NetServer a_serverSocket, AppHandler a_handler, AcceptorHandler a_acceptor)
: EventDetector(a_serverSocket, a_handler, a_acceptor)
, m_ev()
, m_events()
, m_fd(epoll_create1(0))
{
    if (m_fd == -1) {

        throw EpollException("Epoll()", "fail to create async server");
    }

    AddClientToEpoll(m_serverSocket->GetFD());   

    m_serverSocket->Listen();
}

Epoll::~Epoll() {

    close(m_fd);
}

void Epoll::Run() {

    while(true) {

        int nfds = epoll_wait(m_fd, m_events, MAX_REQUESTS, -1);

        if (nfds == -1) {

            throw EpollException("Run()", "fail to wait for epoll");
        }

        HandleIncomingEvents(nfds);
    }
}

bool IsEpollEventErr(uint32_t a_event) {

    return a_event & EPOLLERR || a_event & EPOLLHUP || !(a_event & EPOLLIN);
}

void Epoll::DeleteFdFromEpoll(int a_fd) {

    epoll_ctl(m_fd, EPOLL_CTL_DEL, a_fd, NULL);
    close(a_fd);

    //event detector's member
    m_clients.erase(a_fd);
}

void Epoll::AddClientToEpoll(int a_fd) {

    m_ev.events = EPOLLIN;
    m_ev.data.fd = a_fd;

    if(epoll_ctl(m_fd, EPOLL_CTL_ADD, a_fd, &m_ev) == -1) {

        close(a_fd);
        throw EpollException("Epoll()", "epoll control fail");
    }
}

void Epoll::AddClientToMap(int a_fd, Clientptr a_client) {

    m_clients[a_fd] = std::move(a_client);
}

void Epoll::AcceptConnections() {

    Clientptr clientSocket;

    try {

        clientSocket = m_serverSocket->Accept();
    }

    catch(TcpClientSocketErr &e) {

        std::cerr << e.what() << "\n";

        return;
    }

    int clientFd = clientSocket->GetFD();

    //check if this client is acceptable
    if(!m_acceptor->DoAccept(&clientSocket)) {

        std::cout << "client fd: " << clientFd << " is not accepted\n";
        close(clientFd);

        return;
    }

    AddClientToEpoll(clientFd);  

    AddClientToMap(clientFd, std::move(clientSocket));  
}

void Epoll::HandleIncomingEvents(int a_nfds) {

    for (int i = 0; i < a_nfds; i++) {

        if(IsEpollEventErr(m_events[i].events)) {

            printf("[+] connection closed\n");
            DeleteFdFromEpoll(m_events[i].events);
        }

        //someone wants to connect
        else if(m_events[i].data.fd == m_serverSocket->GetFD()) {

            AcceptConnections();
        }

        //a registered client sent data
        else {

            try {

                m_handler->HandleIncoming(&m_clients[m_events[i].data.fd]);
            }

            catch(const TcpClientSocketErr &e) {

                DeleteFdFromEpoll(m_events[i].data.fd);
            }
        }
    }
}

} // net