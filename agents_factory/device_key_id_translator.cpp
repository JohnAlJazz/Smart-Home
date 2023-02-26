#include "device_key_id_translator.hpp"
#include "agents_catalog.hpp"
#include "devices_id.hpp"

namespace device {

DeviceTranslator::DeviceTranslator()
: m_translator(InitTranslator())
{}

uint32_t DeviceTranslator::translate(const std::string& a_id) {

    return m_translator[a_id];
}

std::map<std::string,uint32_t> DeviceTranslator::InitTranslator() {
    
    std::map<std::string,uint32_t> translator;

    translator["temperature_1_a_1"] = TEMPERATURE_SENSOR;
    translator["temperature_controller"] = TEMPERATURE_CONTROLLER;
    translator["badge_sensor"] = BADGE_SENSOR;
    translator["motion_sensor"] = MOTION_SENSOR;

    return translator;
}

} // device