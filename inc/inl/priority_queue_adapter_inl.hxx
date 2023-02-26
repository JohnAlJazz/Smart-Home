#ifndef PRIORITY_QUEUE_ADAPTER_INL_HXX
#define PRIORITY_QUEUE_ADAPTER_INL_HXX

namespace ds {

inline priorityQueueAdapter::priorityQueueAdapter(unsigned int a_queueSize)
: m_queue(a_queueSize, details::Cmp{})
{
}

inline void priorityQueueAdapter::Enqueue(std::shared_ptr<threads::AbstractTask> a_task)
{
    return m_queue.Enqueue(a_task);
}

inline void priorityQueueAdapter::Dequeue(std::shared_ptr<threads::AbstractTask>&& a_task)
{
    return m_queue.Dequeue(a_task);
}

inline bool details::Cmp::operator()(std::shared_ptr<threads::AbstractTask> a_first,
                std::shared_ptr<threads::AbstractTask> a_second)
{
    using Task = controllers::TaskControllers;

    //be carful, unsafe conversion !
    Task *task1 = dynamic_cast<Task*>(a_first.get());
    Task *task2 = dynamic_cast<Task*>(a_second.get());

    return task1->GetEvent().Priority() < task2->GetEvent().Priority();
}

} //ds

#endif /* PRIORITY_QUEUE_ADAPTER_INL_HXX */