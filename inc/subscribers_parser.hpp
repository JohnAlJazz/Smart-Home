#ifndef SUBCRIBERS_PARSER_HPP
#define SUBCRIBERS_PARSER_HPP

#include <vector>
#include <string>

namespace observer {

class SubscribersParser {
public:
	SubscribersParser() = default;
	
	std::vector<std::string> SubscribersParsing(std::ifstream& a_subscribers);
};

}	//observer

#endif /* SUBCRIBERS_PARSER_HPP */