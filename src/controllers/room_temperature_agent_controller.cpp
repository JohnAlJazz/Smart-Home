#include "room_temperature_agent_controller.hpp"

namespace controllers {

RoomTemperatureAgentController::RoomTemperatureAgentController(device::DeviceDetails& a_device)
: AbstractAgent(a_device)
, m_controller(std::make_shared<RoomTemperatureController>(m_device.DeviceId()))
{}

void RoomTemperatureAgentController::GetEvent(std::shared_ptr<event::Event> a_event) {

    m_controller->HandleEvent(a_event);
}

void RoomTemperatureAgentController::Connect(AbsEventHandler a_eventHandler, AbsSubscribers a_subscribers) {

    const std::string eventOfInterest = m_device.Log() + "_" + m_device.Floor() + "_" + m_device.Room();

    a_subscribers->Subscribe(eventOfInterest, std::make_shared<RoomTemperatureAgentController>(*this));
}

} //controllers