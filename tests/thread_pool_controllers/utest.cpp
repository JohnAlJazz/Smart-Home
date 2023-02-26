#include <iostream>
#include <memory>

#include "abstract_queue_adapter.hpp"
#include "priority_queue_adapter.hpp"
#include "task_controllers.hpp"

#include "abstact_task.hpp"

#include "event.hpp"

#include "thread_pool.hpp"

#include "unistd.h"

int main()
{
    unsigned int queueSize = 10;
    
    std::shared_ptr<ds::AbstractQueueAdapter> queueAdapter =
                            std::make_shared<ds::priorityQueueAdapter>(queueSize);

    threads::ThreadPool pool{1,queueAdapter};

    event::Event event {"1","room5","payload",1,"log"};
    
    event::Event event{"1","room5","fire(first priority)","sat PM",2};
    std::shared_ptr<threads::AbstractTask>task1 = 
            std::make_shared<controllers::TaskControllers>(event);

    event::Event event2{"1","room5","fire(first priority)","sat PM",2};
        std::shared_ptr<threads::AbstractTask>task2 = 
        std::make_shared<controllers::TaskControllers>(event2);
    

    pool.AddTask(task2);
    pool.AddTask(task1);

    return 0;
}