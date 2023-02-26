#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>
#include <ctime>
#include <chrono>

enum Priority {
    
    TEMPERATURE, 
    BADGE,
    MOTION,
    FIRE
};

namespace event {

class Event {
public:
    Event(const std::string& a_type, const std::string& a_location, const std::string& a_payLoad, 
                    uint16_t m_priority, const std::string& a_log);
    
    Event(const Event& a_other) = default;
    Event& operator=(const Event& a_other) = default;
    ~Event() = default;

    const std::string& GetType() const;
    const std::string& GetLocation() const;
    const std::string& GetPayLoad() const;
    time_t GetTime() const;
    const std::string& GetLog() const;
    uint16_t Priority() const;
    const std::string& GetEventId() const;

private:
    std::string GenerateId(time_t a_time, const std::string& a_type, const std::string& m_location);
    
private:
    std::string m_type;
    std::string m_location;
    std::string m_payLoad;
    time_t m_time;
    uint16_t m_priority;
    std::string m_log;
    std::string m_id;
};

} //event

#include "./inl/event_inl.hxx"

#endif /* ABSTRACT_EVENT_HPP */