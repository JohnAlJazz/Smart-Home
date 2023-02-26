#include <stdio.h>
#include <chrono>
#include <time.h>
#include "mu_test.h"

#include "room_temperature_controller.hpp"
#include "event.hpp"
#include "abstract_agent_controller.hpp"
#include "abstract_exeption.hpp"
#include "room_temperature_agent_controller.hpp"


#include <iostream>


BEGIN_TEST(room_controller_cool)
    time_t t;
    time(&t);
    event::Event event("Temperature", "room 2, floor 2", "25", ctime(&t),1);
    controllers::RoomTemperatureController c("12345");
    int result = c.HandleEvent(std::make_shared<event::Event>(event));
    ASSERT_EQUAL(result, controllers::COOL);
  
END_TEST

BEGIN_TEST(room_controller_heat)
    time_t t;
    time(&t);
    event::Event event("Temperature", "room 2, floor 2", "18", ctime(&t),1);
    controllers::RoomTemperatureController c("12345");
    int result = c.HandleEvent(std::make_shared<event::Event>(event));
    ASSERT_EQUAL(result, controllers::HEAT);
  
END_TEST

BEGIN_TEST(room_controller_ignore)
    time_t t;
    time(&t);
    event::Event event("Temperature", "room 2, floor 2", "20", ctime(&t), 1);
    controllers::RoomTemperatureController c("12345");
    int result = c.HandleEvent(std::make_shared<event::Event>(event));
    ASSERT_EQUAL(result, controllers::IGNORE);
  
END_TEST

BEGIN_TEST(room_controller_invalid_type)
    time_t t;
    time(&t);
    event::Event event("Smoke", "room 2, floor 2", "18 rise", ctime(&t), 1);
    controllers::RoomTemperatureController c("12345");
    std::string what;
    try{
        c.HandleEvent(std::make_shared<event::Event>(event));
    }
    catch(const SMError& e){
        ASSERT_PASS();
    }
    
END_TEST

BEGIN_TEST(room_controller_invalid_payload)
    time_t t;
    time(&t);
    event::Event event("Temperature", "room 2, floor 2", "bla bla bla", ctime(&t), 1);
    controllers::RoomTemperatureController c("12345");
    std::string what;
    try{
        c.HandleEvent(std::make_shared<event::Event>(event));
    }
    catch(const SMError& e){
        ASSERT_PASS();
    }
    
END_TEST


// BEGIN_TEST(agent_controller)
//     time_t t;
//     time(&t);
//     event::Event event("Temperature", "room 2, floor 2", "18", ctime(&t), 1);
//     controllers::RoomTemperatureController controller(12345);
//     std::string what;
//     controllers::RoomTemperatureAgentController agent(12345);
//     int result = agent.GetEvent(std::make_shared<event::Event>(event));
//     ASSERT_EQUAL(result, controllers::HEAT);
// END_TEST


// BEGIN_TEST(agent_factory)
//     time_t t;
//     time(&t);
//     event::Event event("Temperature", "room 2, floor 2", "18", ctime(&t), 1);
//     controllers::AgentControllerFactory f;
//     auto agent = f.GetAgent("Temperature" , 12345);
//     int result = agent->GetEvent(std::make_shared<event::Event>(event));
//     ASSERT_EQUAL(result, controllers::HEAT);
// END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)
	
    TEST(room_controller_cool)
    TEST(room_controller_heat)
    TEST(room_controller_ignore)
    TEST(room_controller_invalid_type)
    TEST(room_controller_invalid_payload)
    // TEST(agent_controller)
    // TEST(agent_factory)
END_SUITE


    

