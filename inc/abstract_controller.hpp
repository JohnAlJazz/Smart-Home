#ifndef ABSTRACT_CONTROLLER_HPP
#define ABSTRACT_CONTROLLER_HPP

#include <memory>

#include "tcp_client_socket.hpp"
#include "event.hpp"

namespace controllers {

class AbstractController {
public:
    virtual int HandleEvent(std::shared_ptr<event::Event> a_event) const = 0;
    const std::string& GetID();

protected:
    explicit AbstractController(const std::string& a_id);
    
protected:
    const std::string m_id;
};

} //controllers

#endif /* ABSTRACT_CONTROLLER_HPP */