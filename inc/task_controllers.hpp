#ifndef TASK_CONTROLLERS_HPP
#define TASK_CONTROLLERS_HPP

#include <memory>

#include "abstact_task.hpp"
#include "event.hpp"
#include "observable.hpp"

namespace controllers {

class TaskControllers : public threads::AbstractTask {
public:
    TaskControllers(event::Event m_event, std::shared_ptr<observer::Observable> a_observable);
    event::Event GetEvent();
    void act() override;
    
private:
    event::Event m_event;
    std::shared_ptr<observer::Observable> m_observable;
};

} //controllers

#endif /* TASK_CONTROLLERS_HPP */