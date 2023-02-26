#include "room_temperature_controller.hpp"
#include "abstract_exeption.hpp"

namespace controllers {
    
RoomTemperatureController::RoomTemperatureController(const std::string& a_id)
: AbstractController(a_id)
{}

int RoomTemperatureController::HandleEvent(std::shared_ptr<event::Event> a_event) const {

    std::cout << "message arrived to room temperature controller" << "\n";

    if (a_event->GetType() != std::string("Temperature")) {

        throw SMError("handle event", "invalid event type");
    }
    
    std::string payLoad(a_event->GetPayLoad());
    
    int  temperature;

    try {

        temperature = std::stoi(a_event->GetPayLoad());
    }

    catch(...) {

        throw SMError("handle event", "invalid input");
    }
    
    if(temperature == LOW) {

        return HEAT;
    } 

    else if (temperature == HIGH) {

        return COOL;
    }
    
    return IGNORE;
}

} //controllers
