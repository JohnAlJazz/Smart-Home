#ifndef ABSTRACT_TASK_HPP
#define ABSTRACT_TASK_HPP

namespace threads {

class AbstractTask {
public:
    virtual ~AbstractTask() = default;
    virtual void act() = 0;
    
protected:
    AbstractTask() = default;
    AbstractTask(const AbstractTask& a_other) = default;
    AbstractTask& operator=(const AbstractTask& a_other) = default;
};

}//threads

#endif /* ABSTRACT_TASK_HPP */