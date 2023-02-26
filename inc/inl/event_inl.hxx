#ifndef EVENT_INL_HXX
#define EVENT_INL_HXX

namespace event {

inline const std::string& Event::GetType() const {

    return m_type;
}

inline const std::string& Event::GetLocation() const {

    return m_location;
}

inline const std::string& Event::GetPayLoad() const {

    return m_payLoad;
}

inline time_t Event::GetTime() const {

    return m_time;
}

inline const std::string& Event::GetLog() const {

    return m_log;
}

inline uint16_t Event::Priority() const {

    return m_priority;
}

inline const std::string& Event::GetEventId() const {
    
    return m_id;
}

} //event

#endif /* EVENT_HXX */