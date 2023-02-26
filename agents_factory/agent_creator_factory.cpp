#include "agent_creator_factory.hpp"
#include "device_config_parser.hpp"
#include "agents_catalog.hpp"
#include "temperature_sensor_agent.hpp"
#include "device_generator.hpp"
#include "device_key_id_translator.hpp"
#include "room_temperature_agent_controller.hpp"
#include "badge_sensor_agent.hpp"
#include "motion_sensor_agent.hpp"

namespace agentsFactory {

typedef std::shared_ptr<device::AbstractAgent> (*func_ptr)(device::DeviceDetails);

AgentsFactory::AgentsFactory(std::string &a_filePath)
: m_configFile(a_filePath)
{}

std::shared_ptr<device::AbstractAgent> TemperatureAgentSensor(device::DeviceDetails a_details) {

    return std::make_shared<sensors::TemperatureSensorAgent>(a_details);
}

std::shared_ptr<device::AbstractAgent> BadgeSensorAgent(device::DeviceDetails a_details) {

    return std::make_shared<sensors::BadgeSensorAgent>(a_details);
}

std::shared_ptr<device::AbstractAgent> MotionSensorAgent(device::DeviceDetails a_details) {

    return std::make_shared<sensors::MotionSensorAgent>(a_details);
}

std::shared_ptr<device::AbstractAgent> TemperatureAgentController(device::DeviceDetails a_details) {

    return std::make_unique<controllers::RoomTemperatureAgentController>(a_details);
}

//hard coded map
std::map<uint32_t, func_ptr> AgentDecider() {

    std::map<uint32_t, func_ptr> decider;

    decider[TEMPERATURE_SENSOR] = TemperatureAgentSensor;
    decider[BADGE_SENSOR] = BadgeSensorAgent;
    decider[MOTION_SENSOR] = MotionSensorAgent;
    decider[TEMPERATURE_CONTROLLER] = TemperatureAgentController;

    return decider;
}

AgentsFactory::AgentsMapPtr AgentsFactory::GenerateAgentsMap(device::AppDB a_dataBase) {

    AgentMap agentsMap;
    device::DeviceConfigParser parser;
    device::DeviceTranslator translator;
    std::map<uint32_t, func_ptr> sensorDecider = AgentDecider();


    while (!m_configFile.eof()) {

        device::DeviceDetails device = GenerateDevice(m_configFile, parser);

        std::string deviceId = device.DeviceId();
        uint32_t key = translator.translate(deviceId);

        func_ptr func = sensorDecider[key];
        agentsMap[deviceId] = func(device);
        a_dataBase.InsertDevice(deviceId);
    }

    return std::make_shared<AgentMap>(agentsMap);
}

} // agentsFactory