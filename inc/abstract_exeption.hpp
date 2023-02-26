#ifndef MACHINE_EXCEPTIONS_HPP
#define MACHINE_EXCEPTIONS_HPP

#include <exception>
#include <string>
#include <iostream>

class SMError : public std::exception {
public:
    SMError(const char* fn, const char* w)
    : m_func(fn)
    , m_what(w)
    {}

    virtual ~SMError(){}

    virtual void Print() const {
        std::cout << m_func << " : " << m_what << std::endl;
    }
    
    virtual const char* what() const throw() { return m_what.c_str(); }

private:
    std::string m_func;
    std::string m_what;
};

#endif //MACHINE_EXCEPTIONS_HPP