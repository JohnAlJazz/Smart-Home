#ifndef PRIORITY_QUEUE_INL_HXX
#define PRIORITY_QUEUE_INL_HXX

#ifdef DEBUG_MODE
    int ingress = 0;
    int engress = 0;
#endif

namespace threads { 

template <typename Type,typename Cmp>
PriorityQueue<Type,Cmp>::PriorityQueue(unsigned int a_max, Cmp a_compare)
: m_mutex(),
m_queue(a_compare)
, m_max(a_max)
, m_notFull()
, m_notEmpty()
, m_exit()
, m_numOfThreads(0)
, m_hasToStop(false)
{    
}

template <typename Type,typename Cmp>
PriorityQueue<Type,Cmp>::Executer::Executer(std::function<void()> & a_func)
:   m_func(a_func)
{

}

template <typename Type,typename Cmp>
void PriorityQueue<Type,Cmp>::Executer::Execute()
{
    m_func();
}

template <typename Type,typename Cmp>
void PriorityQueue<Type,Cmp>::InternalEnqueue(Executer& a_executer)
{
    std::unique_lock lk(m_mutex);

    while (m_queue.size() == m_max && !m_hasToStop) {
        m_notFull.wait(lk);
    }

    if (!m_hasToStop) {
        a_executer.Execute();
        ++m_numOfThreads;
        m_notEmpty.notify_all();
    }

    else {
        --m_numOfThreads;
        m_exit.notify_one();
    }
}

template <typename Type,typename Cmp>
void PriorityQueue<Type,Cmp>::InternalDequeue(Executer& a_queue)
{
    std::unique_lock lk(m_mutex);

    while (m_queue.empty() && !m_hasToStop) {
        m_notEmpty.wait(lk);
    }

    if (!m_hasToStop) {
        a_queue.Execute();
        ++m_numOfThreads;
        m_notFull.notify_all();
    }

    else {  
        --m_numOfThreads;
        m_exit.notify_one();
    }
}

template <typename Type,typename Cmp>
void PriorityQueue<Type,Cmp>::Enqueue(const Type& a_element)
{
    auto &queue = this->m_queue;

    std::function<void()> func = [&queue,&a_element] () {
        queue.push(a_element);
        #ifdef DEBUG_MODE
            a_element.m_ingress = ingress++;
        #endif
    };

    Executer exec{func};

    InternalEnqueue(exec);
}



template <typename Type,typename Cmp>
void PriorityQueue<Type,Cmp>::Enqueue(Type&& a_element)
{
    auto &queue = this->m_queue;

    std::function<void()> func = [&queue,&a_element] () {
        queue.push(std::move(a_element));
        #ifdef DEBUG_MODE
            a_element.m_ingress = ingress++;
        #endif
    };

    Executer exec{func};

    InternalEnqueue(exec);
}


template <typename Type,typename Cmp>
void PriorityQueue<Type,Cmp>::Dequeue(Type& a_element)
{
    auto &queue = this->m_queue;

    std::function<void()> func = [&queue,&a_element] () {
        a_element = queue.top();
       #ifdef DEBUG_MODE
            a_element.m_egress = engress--;
        #endif
        queue.pop();
    };

    Executer exec{func};

    InternalDequeue(exec);
}


template <typename Type,typename Cmp>
void PriorityQueue<Type,Cmp>::Dequeue(Type&& a_element)
{
    auto &queue = this->m_queue;

    std::function<void()> func = [&queue,&a_element] () {
        a_element =  std::move(queue.top());
       #ifdef DEBUG_MODE
            a_element.m_egress = engress--;
        #endif
        queue.pop();
    };

    Executer exec{func};

    InternalDequeue(exec);
}

template <typename Type,typename Cmp>
void PriorityQueue<Type,Cmp>::ShutDown()
{
    std::unique_lock lk(m_mutex);

    m_hasToStop = true;

    m_notEmpty.notify_all();
    m_notFull.notify_all();

    while (m_numOfThreads > 0) {
        m_exit.wait(lk);
    }
}

} //threads

#endif /* PRIORITY_QUEUE_INL_HXX */