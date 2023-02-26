#ifndef EVENT_DETECTOR_INL_HXX
#define EVENT_DETECTOR_INL_HXX

namespace net {

inline EventDetector::EventDetector(NetServer a_serverSocket, AppHandler a_handler,AcceptorHandler a_acceptor)
: m_serverSocket(a_serverSocket)
, m_handler(a_handler)
, m_acceptor(a_acceptor)
, m_clients()
{}

} //net

#endif /* EVENT_DETECTOR_INL_HXX */