#ifndef HTT_PCLIENT_HPP
#define HTT_PCLIENT_HPP

#include "Poco/JSON/Object.h"
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

#include "event.hpp"

namespace http {

class HttpCLient {
public: 
    HttpCLient(std::string& a_uri, std::string& a_contentType);
    void Send(event::Event& a_event);

private:    
    Poco::Net::HTTPRequest ProtocolRequestBuilder(std::stringstream& ss,
                                                    Poco::Net::HTTPRequest& request);
    Poco::JSON::Object ProtocolBodyBulilder(event::Event& a_event);

private:
    Poco::URI m_uri;
    std::string m_contentType;
};
    
} //http

#endif /* HTT_PCLIENT_HPP */