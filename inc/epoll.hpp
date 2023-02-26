#ifndef EPOLL_HPP
#define EPOLL_HPP

#include <memory>

#include <sys/epoll.h>
#include "event_detector.hpp"
#include "abstract_exeption.hpp"

#define MAX_REQUESTS 100

namespace net {

class Epoll : public EventDetector {
public:
    Epoll(NetServer a_serverSocket, AppHandler a_handler, AcceptorHandler a_acceptor);
    ~Epoll();
    void Run() override;

private:
    void HandleIncomingEvents(int a_nfds); //remove file after tests.
    void DeleteFdFromEpoll(int a_fd);
    void AcceptConnections();
    void AddClientToEpoll(int a_fd);
    void AddClientToMap(int a_fd, Clientptr a_client);

private:
    struct epoll_event m_ev;
    struct epoll_event m_events[MAX_REQUESTS];
    int m_fd;
};

class EpollException : public SMError {
public:

    EpollException(const char* fn, const char* w) : SMError(fn , w){};
};

} //net

#endif //EPOLL_HPP