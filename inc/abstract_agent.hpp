#ifndef ABSTRACT_AGENT_HPP
#define ABSTRACT_AGENT_HPP

#include <memory>
#include <string>

#include "event.hpp"
#include "device_details.hpp"
#include "abstract_event_handler.hpp"

namespace observer {
    class AbstractSubscribers;
}

namespace event {
    class EventsHandler;
}

namespace device {

class AbstractAgent {
protected:
    using AbsEventHandler = std::shared_ptr<event::AbstractEventHandler>;
    using AbsSubscribers = std::shared_ptr<observer::AbstractSubscribers>;
    
public:
    virtual ~AbstractAgent() = default;
    
    virtual void IncomingMsg(std::string& a_msg);
    virtual void GetEvent(std::shared_ptr<event::Event> a_event);
    virtual void Connect(AbsEventHandler a_eventHandler, AbsSubscribers a_subscribers);

protected:
    AbstractAgent(device::DeviceDetails& a_device);

protected:
    device::DeviceDetails m_device;
};

} // namespace device

#include "inl/abstract_agent_inl.hxx"
#include "abs_subscribers.hpp"

#endif /* ABSTRACT_AGENT_HPP */