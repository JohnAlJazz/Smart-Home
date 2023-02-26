#ifndef TCP_CLIENT_SOCKET_INL_HXX
#define TCP_CLIENT_SOCKET_INL_HXX

namespace net {

inline int TcpClientSocket::GetFD(){return m_socketManager.GetFD();}

} //net

#endif /* TCP_CLIENT_SOCKET_INL_HXX */
