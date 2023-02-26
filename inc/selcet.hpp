#ifndef SELECT_HPP
#define SELECT_HPP

#include <sys/select.h>

#include "event_detector.hpp"
#include "abstract_exeption.hpp"

namespace net {

class Select : public EventDetector{
public:
    Select(NetServer a_server, AppHandler a_handler, AcceptorHandler a_acceptor);
    Select(const Select&) = delete;
    Select& operator=(const Select&) = delete;
    ~Select() = default;    

    void Run() override;

private:
    void HandleIO();
    void AcceptConnections();    
    void GetData(int a_fd);
    void AddFdToFdSet(int a_fd);
    void AddClientToMap(int a_fd, Clientptr a_client);

private:
    fd_set m_readFd;
    fd_set m_temp;
};

struct SelectExceptions : public SMError {

    SelectExceptions(const char* func, const char* where);
};

} //net

#endif //SELECT_HPP