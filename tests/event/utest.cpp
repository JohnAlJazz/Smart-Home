#include <stdio.h>
#include <chrono>
#include <time.h>
#include "mu_test.h"

#include <iostream>

#include "room_temperature_controller.hpp"
#include "event.hpp"
#include "abstract_agent_controller.hpp"


BEGIN_TEST(event_test)
    std::string type("Temperature");
    std::string location("room 2, floor 2");
    std::string payLoad("25");
    time_t t;
    time(&t);
    std::string t_ (ctime(&t));
    event::Event event("Temperature", "room 2, floor 2", "25", ctime(&t), 1);

    ASSERT_EQUAL(type + location + payLoad + event.GetTime(), event.GetType() + event.GetLocation() + event.GetPayLoad() + ctime(&t));  
END_TEST

BEGIN_TEST(event_copy_constructor)
    std::string type("Temperature");
    std::string location("room 2, floor 2");
    std::string payLoad("20");
    time_t t;
    time(&t);
    event::Event event(type, location, payLoad, ctime(&t), 1);
    event::Event event_copy(event);
    
    ASSERT_EQUAL(type + location + payLoad + ctime(&t), event_copy.GetType() + event_copy.GetLocation() + event_copy.GetPayLoad() + event_copy.GetTime());  
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(event_test)
    TEST(event_copy_constructor)
END_SUITE