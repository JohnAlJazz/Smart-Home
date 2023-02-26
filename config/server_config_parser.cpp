#include <string>

#include "server_config_parser.hpp"

namespace config { 

ServerConfigParser::ServerConfigParser(std::ifstream& a_serverConfigFile)
: m_port(ParsePort(a_serverConfigFile))
, m_queueSize(ParseQueueSize(a_serverConfigFile))
, m_numOfThreads(ParseNumOfThreads(a_serverConfigFile))
, m_uri(ParseUri(a_serverConfigFile))
, m_contentType(ParseContentType(a_serverConfigFile))
{}

uint16_t ServerConfigParser::ParsePort(std::ifstream& a_serverConfigFile) {

    unsigned int port;

    a_serverConfigFile >> port;

    return port;
}

unsigned int ServerConfigParser::ParseQueueSize(std::ifstream& a_serverConfigFile) {

    unsigned int queueSize;

    a_serverConfigFile >> queueSize;

    return queueSize;
}

unsigned int ServerConfigParser::ParseNumOfThreads(std::ifstream& a_serverConfigFile) {

    unsigned int numOfThreads;

    a_serverConfigFile >> numOfThreads;

    return numOfThreads;
}

std::string ServerConfigParser::ParseUri(std::ifstream& a_serverConfigFile) {
    
    std::string uri;

    a_serverConfigFile >> uri;

    return uri;
}

std::string ServerConfigParser::ParseContentType(std::ifstream& a_serverConfigFile) {

    std::string contentType;

    a_serverConfigFile >> contentType;

    return contentType;
}

} //server