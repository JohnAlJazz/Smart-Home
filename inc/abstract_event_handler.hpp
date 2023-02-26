#ifndef ABSTRACT_EVENT_HANDLER_HPP
#define ABSTRACT_EVENT_HANDLER_HPP

#include "event.hpp"

namespace event {

class AbstractEventHandler {
public:
    virtual ~AbstractEventHandler() = default;
    virtual void AddEvent(event::Event& a_event) = 0;
};

} //event

#endif /* ABSTRACT_EVENT_HANDLER_HPP */