#include "device_details.hpp"

namespace device {

DeviceDetails::DeviceDetails(StrRef a_deviceId,
    StrRef a_type, StrRef a_room, StrRef a_floor, StrRef a_log,StrRef a_config)
:   m_deviceId(a_deviceId)
, m_type(a_type)
, m_room(a_room)
, m_floor(a_floor)
, m_log(a_log)
, m_config(a_config)
{
}

} //device
