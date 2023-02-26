#ifndef SERVER_CONFIG_PARSER_HPP
#define SERVER_CONFIG_PARSER_HPP

#include <fstream>

namespace config {

class ServerConfigParser {
public:
    ServerConfigParser(std::ifstream& a_serverConfigFile);
    ServerConfigParser(const ServerConfigParser& a_other) = default;
    ServerConfigParser& operator=(const ServerConfigParser& a_other) = default;
    ~ServerConfigParser() = default;

    uint16_t Port();
    unsigned int QueueSize();
    unsigned int ThreadsNum();
    std::string Uri();
    std::string ContentType();

private:
    uint16_t ParsePort(std::ifstream& a_serverConfigFile);
    unsigned int ParseQueueSize(std::ifstream& a_serverConfigFile);
    unsigned int ParseNumOfThreads(std::ifstream& a_serverConfigFile);
    std::string ParseUri(std::ifstream& a_serverConfigFile);
    std::string ParseContentType(std::ifstream& a_serverConfigFile);

private:
    uint16_t m_port;
    unsigned int m_queueSize;
    unsigned int m_numOfThreads;
    std::string m_uri;
    std::string m_contentType;
};

} //server

#include "./inl/server_config_parser_inl.hxx"

#endif //SERVER_CONFIG_PARSER_HPP