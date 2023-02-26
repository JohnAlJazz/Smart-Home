#include <iostream>

#include "thread_pool.hpp"

namespace threads {

ThreadPool::ThreadPool(unsigned int a_numOfThreads, Container a_queueContainer)
: m_numOfThreads(a_numOfThreads)
, m_queueContainer(std::move(a_queueContainer))
, m_isTerminate(false)
{
    Add(a_numOfThreads);
}

ThreadPool::~ThreadPool()
{
    const std::lock_guard<std::mutex> lock(m_mutex);
    size_t size = m_threads.size();
    for (size_t i = 0; i < size ; i++) {
        m_threads[i].join();
    }
}

void ThreadPool::AddTask(std::shared_ptr<AbstractTask> a_task)
{
    if (!m_isTerminate) {
        
        m_queueContainer->Enqueue(std::move(a_task));
    }

    else {
        std::cerr << "cannot add task, system is shut down\n";
    }
}

struct ThreadPoolExeption : public SMError {
    ThreadPoolExeption(const char* fn, const char* w) : SMError(fn , w){};
};

void ThreadPool::ExecuteThreads()
{
    while (true) {

        std::shared_ptr<AbstractTask> task;
        m_queueContainer->Dequeue(std::move(task));

        try {

            task->act();
        }
        
        catch(const ThreadPoolExeption & e) {

            std::cout << "breaked\n";
            break;
        }

        catch(...) {
            continue;
        }
    }
}

class TaskShutDown : public AbstractTask {
public:

    void act () override {

        throw ThreadPoolExeption{"",""};
    }
};

void ThreadPool::ShutDown() 
{
    std::cout << m_numOfThreads << "\n";
    std::shared_ptr<threads::AbstractTask> task = std::make_unique<TaskShutDown>();

    for (size_t i = 0; i < m_numOfThreads; i++) {

        AddTask(task);
    }

    m_isTerminate = true;
}

void ThreadPool::Add(unsigned int a_numOfThreads)
{
    for (unsigned int i = 0; i < a_numOfThreads; i++) {

        m_threads.push_back(std::thread{&ThreadPool::ExecuteThreads,this});
    }
}

} //threads