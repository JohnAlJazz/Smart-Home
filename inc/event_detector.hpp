#ifndef EVENT_DETECTOR_HPP
#define EVENT_DETECTOR_HPP

#include "tcp_client_socket.hpp"
#include "abstract_handler.hpp"
#include "tcp_server_socket.hpp"
#include "tcp_client_socket.hpp"
#include "iacceptor.hpp"

#include <map>

namespace net {

class EventDetector {
public:
    virtual ~EventDetector() = default;
    
    virtual void Run() = 0;

protected:
    using NetServer = std::shared_ptr<TcpServerSocket>;
    using AppHandler = std::shared_ptr<AbstractHandler>;
    using AcceptorHandler = std::shared_ptr<Iacceptor>;
    using Clientptr = std::unique_ptr<TcpClientSocket>;

    EventDetector(NetServer a_serverSocket, AppHandler a_handler, AcceptorHandler a_acceptor);
    EventDetector(EventDetector& a_other) = delete;
    EventDetector& operator=(EventDetector& a_other) = delete;
    
protected:
    NetServer m_serverSocket;
    AppHandler m_handler;
    AcceptorHandler m_acceptor;
    std::map<int,Clientptr> m_clients;    
};

} //net

#include "./inl/event_detector_inl.hxx"

#endif //EVENT_DETECTOR_HPP