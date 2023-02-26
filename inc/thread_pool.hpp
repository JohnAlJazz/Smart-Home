#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include <thread>
#include <vector>
#include <memory>
#include <mutex>
#include <atomic>

#include "abstact_task.hpp"
#include "priority_queue.hpp"
#include "abstract_queue_adapter.hpp"

namespace threads {

class ThreadPool {
private:
    using Container = std::shared_ptr<ds::AbstractQueueAdapter>;

public:
    ThreadPool(unsigned int a_numOfThreads, Container a_queueContainer);
    ThreadPool(const ThreadPool& a_other) = delete;
    ThreadPool& operator=(const ThreadPool& a_other) = delete;
    ~ThreadPool();

    void AddTask(std::shared_ptr<AbstractTask> a_task);
    void ShutDown(); 

private:
    void Add(unsigned int a_numOfThreads);
    void ExecuteThreads();
    void RemoveThreads(unsigned int a_numOfThreads,bool isFront);
    void changeNumOfThreads(unsigned int a_numOfThreads);
    
private:
    unsigned int m_numOfThreads;
    Container m_queueContainer;
    std::vector<std::thread> m_threads;
    std::atomic<bool>m_isTerminate;
    std::mutex m_mutex;
};

} //threads

#endif /* THREAD_POOL_HPP */