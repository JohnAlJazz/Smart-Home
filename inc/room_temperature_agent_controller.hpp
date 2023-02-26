#ifndef ROOM_TEMPERATURE_AGENT_CONTROLLER_HPP
#define ROOM_TEMPERATURE_AGENT_CONTROLLER_HPP

#include "abstract_agent.hpp"
#include "room_temperature_controller.hpp"
#include "device_details.hpp"

namespace controllers {

class RoomTemperatureAgentController: public device::AbstractAgent {
public:
    RoomTemperatureAgentController(device::DeviceDetails& a_device);
    RoomTemperatureAgentController(const RoomTemperatureAgentController& a_other) = default;
    RoomTemperatureAgentController& operator=(const RoomTemperatureAgentController& a_other) = default;
    
    void GetEvent(std::shared_ptr<event::Event> a_event) override;
    void Connect(AbsEventHandler a_eventHandler, AbsSubscribers a_subscribers) override;
    
private:
    std::shared_ptr<RoomTemperatureController> m_controller;
};

} //controllers

#endif  /* TEMPERATURE_AGENT_CONTROLLER_HPP */