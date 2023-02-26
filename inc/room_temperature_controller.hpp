#ifndef ROOM_TEMPERATURE_CONTROLLER_HPP
#define ROOM_TEMPERATURE_CONTROLLER_HPP

#include "abstract_controller.hpp"

namespace controllers {

enum TemperatureLimits {
    LOW = 18,
    HIGH = 25
};

enum HandleResult {
    HEAT,
    COOL,
    IGNORE
};

class RoomTemperatureController : public AbstractController {
public:
    explicit RoomTemperatureController(const std::string& a_id);
    int HandleEvent(std::shared_ptr<event::Event> a_event) const override;
};

} //controllers

#endif /* ROOM_TEMPERATURE_CONTROLLER_HPP */