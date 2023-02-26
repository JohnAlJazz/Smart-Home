#ifndef CONFIG_STREAM_HPP
#define CONFIG_STREAM_HPP

#include <fstream>

namespace config {

class ConfigStreams {
private:
    using String = std::string&;

public:
    ConfigStreams(String a_serverConfig, String a_sensorsAgentConfig);
    ConfigStreams(const ConfigStreams& a_other) = default;
    ConfigStreams& operator=(const ConfigStreams& a_other) = default;

    std::ifstream& ServerConfig();
    std::ifstream& AgentConfig();
    
private:
    std::ifstream m_serverConfig;
    std::ifstream m_agentConfig;
};

} //server

#include "./inl/config_streams_inl.hxx"

#endif /* CONFIG_STREAM_HPP */