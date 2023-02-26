#ifndef TCP_SERVER_SOCKET_INL_HXX
#define TCP_SERVER_SOCKET_INL_HXX

namespace net {

inline int TcpServerSocket::GetFD(){return m_socketManager.GetFD();}

} //net

#endif /* TCP_SERVER_SOCKET_INL_HXX */
