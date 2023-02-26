#ifndef PRIORITY_QUEUE_ADAPTER_HPP
#define PRIORITY_QUEUE_ADAPTER_HPP

#include <memory>

#include "abstract_queue_adapter.hpp"
#include "priority_queue.hpp"
#include "event.hpp"
#include "task_controllers.hpp"

namespace ds {

namespace details {

struct Cmp {
    
    bool operator()(std::shared_ptr<threads::AbstractTask> a_first,
                std::shared_ptr<threads::AbstractTask> a_second);
};

} //details

class priorityQueueAdapter : public AbstractQueueAdapter {
public:
    priorityQueueAdapter(unsigned int a_queueSize);
    
    void Enqueue(std::shared_ptr<threads::AbstractTask> a_task) override;
    void Dequeue(std::shared_ptr<threads::AbstractTask>&& a_task) override;

private:
    threads::PriorityQueue<std::shared_ptr<threads::AbstractTask>,details::Cmp> m_queue;
};

} //threads

#include "./inl/priority_queue_adapter_inl.hxx"

#endif /* PRIORITY_QUEUE_ADAPTER_HPP */