#ifndef ABSTRACT_QUEUE_ADAPTER_HPP
#define ABSTRACT_QUEUE_ADAPTER_HPP

#include <memory>

#include "abstact_task.hpp"

namespace ds {

class AbstractQueueAdapter {
public:
    virtual ~AbstractQueueAdapter () = default;
    virtual void Enqueue(std::shared_ptr<threads::AbstractTask>) = 0;
    virtual void Dequeue(std::shared_ptr<threads::AbstractTask>&& ) = 0;
    
protected:
    AbstractQueueAdapter () = default;
    AbstractQueueAdapter (const AbstractQueueAdapter& a_other) = delete;
    AbstractQueueAdapter& operator=(const AbstractQueueAdapter& a_other) = delete;
};

} //ds

#endif /* ABSTRACT_QUEUE_ADAPTER_HPP */