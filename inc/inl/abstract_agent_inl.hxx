#ifndef ABSTRACT_AGENT_INL_HXX
#define ABSTRACT_AGENT_INL_HXX

namespace device {

inline AbstractAgent::AbstractAgent(device::DeviceDetails& a_device)
: m_device(a_device)
{
}

inline void AbstractAgent::IncomingMsg(std::string& a_msg)
{

}

inline void AbstractAgent::GetEvent(std::shared_ptr<event::Event> a_event)
{

}

inline void AbstractAgent::Connect(AbsEventHandler a_eventHandler, AbsSubscribers a_subscribers) 
{

}

} // namespace device

#endif /* ABSTRACT_AGENT_INL_HXX */