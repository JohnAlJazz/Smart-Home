#ifndef SERVER_CONFIG_PARSER_INL_HXX
#define SERVER_CONFIG_PARSER_INL_HXX

namespace config {

inline uint16_t ServerConfigParser::Port()
{
    return m_port;
}

inline unsigned int ServerConfigParser::QueueSize()
{
    return m_queueSize;
}

inline unsigned int ServerConfigParser::ThreadsNum()
{
    return m_numOfThreads;
}

//
inline std::string ServerConfigParser::Uri()
{
    return m_uri;
}

inline std::string ServerConfigParser::ContentType()
{
    return m_contentType;
}

} //server

#endif /* SERVER_CONFIG_PARSER_INL_HXX */