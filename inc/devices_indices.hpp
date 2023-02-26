#ifndef DEVICES_INDICE_HPP
#define DEVICES_INDICE_HPP

#include <unordered_map>
#include <string>
#include <cstdint>  //uint32_t

namespace device {

struct DevicesIndices {
	std::unordered_map<uint32_t, std::string> m_sensorsByInt;
	std::unordered_map<uint32_t, std::string> m_controllersByInt;
};

} //device

#endif //DEVICES_INDICE_HPP