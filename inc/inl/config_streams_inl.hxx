#ifndef CONFIG_STREAM_INL_HXX
#define CONFIG_STREAM_INL_HXX

namespace config {

inline std::ifstream& ConfigStreams::ServerConfig()
{
    return m_serverConfig;
}

inline std::ifstream& ConfigStreams::AgentConfig()
{
    return m_agentConfig;
}

} //config

#endif /* CONFIG_STREAM_INL_HXX */