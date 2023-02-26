#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <vector>
#include <memory>

#include "observable.hpp"
#include "event.hpp"
#include "priority_queue.hpp"
#include "thread_pool.hpp"
#include "observable.hpp"
#include "abstract_event_handler.hpp"
#include "http_client.hpp"

namespace event {

class EventsHandler : public AbstractEventHandler {
private:
    using ThreadPoolPtr = std::shared_ptr<threads::ThreadPool>;
    using ObservablePtr = std::shared_ptr<observer::Observable>;
    using HttpClientPtr = std::shared_ptr<http::HttpCLient>;
    
public:
    EventsHandler(ThreadPoolPtr a_threadPool, ObservablePtr a_observable, HttpClientPtr a_httpClient);
    EventsHandler(const EventsHandler& a_other) = delete;
    EventsHandler& operator=(const EventsHandler& a_other) = delete;
    
    void AddEvent(event::Event& a_event) override;

private:
    ThreadPoolPtr m_threadPool;
    ObservablePtr m_observable;
    HttpClientPtr m_httpClient;
};

} //event

#endif /* EVENT_HANDLER_HPP */