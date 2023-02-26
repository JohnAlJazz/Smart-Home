#include <iostream>

#include "task_controllers.hpp"
#include "abs_notifier.hpp"

namespace controllers {

TaskControllers::TaskControllers(event::Event a_event, std::shared_ptr<observer::Observable> a_observable)
: m_event(a_event)
, m_observable(a_observable)
{}

event::Event TaskControllers::GetEvent() {

    return m_event;
}

void TaskControllers::act() {

    std::shared_ptr<observer::AbsNotifier> notifier = m_observable;
    notifier->Notify(std::make_shared<event::Event>(m_event));
}

} //controllers