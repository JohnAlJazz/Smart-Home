#ifndef SUBCRIBERS_TRANSLATOR_HPP
#define SUBCRIBERS_TRANSLATOR_HPP

#include <string>

namespace observer {

class SubscribersTranslator {
public:
	SubscribersTranslator() = default;

	uint32_t TurnToID(std::string a_eventID);	
};

}	//observer

#endif /* SUBCRIBERS_TRANSLATOR_HPP */