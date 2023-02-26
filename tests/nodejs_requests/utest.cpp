#include "http_client.hpp"

int main()
{
    std::string uri {"http://localhost:8081"};
    std::string contentType {"application/json"};

    http::HttpCLient clientSender{uri,contentType};


    std::string eventType {"event type"};
    std::string eventLocation {"event location"};
    std::string eventPayload {"event payload"};
    uint16_t eventPriority  = 8;
    std::string eventLog {"fire"};

    event::Event event{eventType,eventLocation,eventPayload,eventPriority,eventLog};

    clientSender.Send(event);    
}