#ifndef SOCKET_INL_HXX
#define SOCKET_INL_HXX

namespace net {

inline int Socket::GetFD() {
    
    return m_socket;
}

} //net

#endif /* SOCKET_INL_HXX */