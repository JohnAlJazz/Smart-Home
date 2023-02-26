#ifndef DEVICE_DETAILS_INL_HXX
#define DEVICE_DETAILS_INL_HXX

namespace device {

inline DeviceDetails::StrRef DeviceDetails::DeviceId()
{
    return m_deviceId;
}

inline DeviceDetails::StrRef DeviceDetails::Type()
{
    return m_type;
}

inline DeviceDetails::StrRef DeviceDetails::Room()
{
    return m_room;
}

inline DeviceDetails::StrRef DeviceDetails::Floor()
{
    return m_floor;
}

inline DeviceDetails::StrRef DeviceDetails::Log()
{
    return m_log;
}


inline DeviceDetails::StrRef DeviceDetails::Config()
{
    return m_config;
}

} //device

#endif /* DEVICE_DETAILS_INL_HXX */
