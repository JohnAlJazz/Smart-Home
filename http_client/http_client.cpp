#include <string>

#include "http_client.hpp"

namespace http {

HttpCLient::HttpCLient(std::string& a_uri, std::string& a_contentType)
: m_uri(a_uri)
, m_contentType(a_contentType)
{
}

void HttpCLient::Send(event::Event& a_event)
{
    using HTTPRequest = Poco::Net::HTTPRequest;
    using HTTPMessage = Poco::Net::HTTPMessage;

    std::stringstream ss;
    Poco::JSON::Object obj = ProtocolBodyBulilder(a_event);
    obj.stringify(ss);

    Poco::Net::HTTPClientSession session(m_uri.getHost(), m_uri.getPort());

    std::string path(m_uri.getPathAndQuery());
    if (path.empty()) {
        path = "/";
    }

    Poco::Net::HTTPRequest request(HTTPRequest::HTTP_POST, path, HTTPMessage::HTTP_1_1);
    request.setContentType(m_contentType);
    request.setContentLength(ss.str().size());

    Poco::Net::HTTPResponse response;

    session.setKeepAlive(true);
    std::ostream& stream = session.sendRequest(request);    

    obj.stringify(stream);
}

Poco::JSON::Object HttpCLient::ProtocolBodyBulilder(event::Event& a_event)
{
    Poco::JSON::Object obj;

    obj.set("type", a_event.GetType());
    obj.set("location", a_event.GetLocation());
    obj.set("payload", a_event.GetPayLoad());
    obj.set("id", a_event.GetEventId());
    obj.set("timeNew",a_event.GetTime());
    obj.set("priority",a_event.Priority());

    return obj;
}

} //http
