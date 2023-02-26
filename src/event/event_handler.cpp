#include <thread>

#include "event_handler.hpp"
#include "abs_notifier.hpp"
#include "task_controllers.hpp"

namespace event {

EventsHandler::EventsHandler(ThreadPoolPtr a_threadPool, ObservablePtr a_observable, HttpClientPtr a_httpClient)                            
: m_threadPool(a_threadPool)
, m_observable(a_observable)
, m_httpClient(a_httpClient)
{}

void EventsHandler::AddEvent(event::Event& a_event) {

    try {

        m_httpClient->Send(a_event);
    }

    catch(...) {

        std::cout << "cant connect to nodejs server\n";
    }   

    controllers::TaskControllers taskWrapper(a_event, m_observable);
    
    m_threadPool->AddTask(std::make_shared<controllers::TaskControllers>(taskWrapper));
}

} //event