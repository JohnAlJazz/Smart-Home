#ifndef KEY_ID_TRANSLATOR_HPP
#define KEY_ID_TRANSLATOR_HPP

#include <map>
#include <string>

namespace device {

class DeviceTranslator {
public:
    DeviceTranslator();
    DeviceTranslator(const DeviceTranslator& a_other) = delete;
    DeviceTranslator& operator=(const DeviceTranslator& a_other) = delete;
    
    uint32_t translate(const std::string& a_id);
    
private:
    std::map<std::string,uint32_t> InitTranslator();
    std::map<std::string,uint32_t> m_translator;
};

}//device

#endif /* KEY_ID_TRANSLATOR_HPP  */