#include <sstream>

#include "event.hpp"

namespace event {

Event::Event(const std::string& a_type, const std::string& a_location, const std::string& a_payLoad, 
                    uint16_t a_priority, const std::string& a_log)
: m_type(a_type)
, m_location(a_location)
, m_payLoad(a_payLoad)
, m_time(time(nullptr))
, m_priority(a_priority)
, m_log(a_log)
, m_id(GenerateId(m_time,a_type,a_location))
{
}

std::string Event::GenerateId(time_t a_time, const std::string& a_type, const std::string& m_location)
{
    std::stringstream ss;
    ss << a_time;
    std::string ts = ss.str();

    return ts + a_type + m_location;
}

} //event