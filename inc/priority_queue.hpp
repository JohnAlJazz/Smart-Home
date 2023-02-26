#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <mutex>
#include <queue>
#include <condition_variable>
#include <functional>

#include "abstract_exeption.hpp"

#ifdef DEBUG_MODE
    #include <iostream>
#endif


#include "task_controllers.hpp"

namespace threads {

template <typename Type, typename Cmp>
class PriorityQueue {
private:
class Executer;
public:
    explicit PriorityQueue(unsigned int a_max,Cmp a_compare);
    PriorityQueue(const PriorityQueue& a_other) = delete;
    PriorityQueue& operator=(const PriorityQueue& a_other) = delete;

    void Enqueue(const Type& a_element);
    void Enqueue(Type&& a_element);

    void EnqueueProtection(const Type& a_element);
    void EnqueueProtection(Type&& a_element);

    void Dequeue(Type& a_element);
    void Dequeue(Type&& a_element);

    void ShutDown();

private:
    void InternalEnqueue(Executer& a_executer);
    void InternalDequeue(Executer& a_executer);

private:
    std::mutex m_mutex;
    std::priority_queue<Type,std::vector<Type>,Cmp> m_queue;
    unsigned int m_max;
    std::condition_variable m_notFull;
    std::condition_variable m_notEmpty;
    std::condition_variable m_exit;
    int m_numOfThreads;
    bool m_hasToStop;
};

template <typename Type, typename Cmp>
class PriorityQueue<Type,Cmp>::Executer {
public:
    Executer(std::function<void()> &a_func);
    Executer(const Executer& a_other) = default;
    void Execute();
    
private:
    std::function<void()> & m_func;
};

class PqExeption : public SMError {
public:
    PqExeption(const char* fn, const char* w) : SMError(fn , w){};
};

} //threads

#include "./inl/priority_queue_inl.hxx"

#endif /* PRIORITY_QUEUE_H */