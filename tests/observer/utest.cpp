#include "mu_test.h"

#include "observable.hpp"
#include "room_temperature_controller.hpp"

enum Eventkey {
    TEMPERATURE_1_a_1,
	TEMPERATURE_1_a_2
};

BEGIN_TEST(subscribe_and_notify)
	
	auto observable = std::make_shared<observer::Observable>();
	std::shared_ptr<observer::AbsSubscribers> sub = observable;
	std::shared_ptr<observer::AbsNotifier> notifier = observable;
	
	std::shared_ptr<controllers::AbstractAgentController> controller1;
	std::shared_ptr<controllers::AbstractAgentController> controller2;
	
	sub->Subscribe(TEMPERATURE_1_a_1, controller1);
	sub->Subscribe(TEMPERATURE_1_a_2, controller2);

	const std::string type("TEMPERATURE");
	const std::string location("1_a_1");
	const std::string payload("26");
	const std::string timeStr("3.11.22-10:47");

	event::Event hot(type, location, payload, timeStr, 1);	 	
	notifier->Notify(std::make_shared<event::Event>(hot));
	ASSERT_PASS();
END_TEST

BEGIN_SUITE(obs test)
	TEST(subscribe_and_notify)
END_SUITE
