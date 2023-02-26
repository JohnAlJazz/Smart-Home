#include "device_config_parser.hpp"

namespace device {
    
static void TrimSpaces(std::string& a_other) {

    size_t turtle = 0;
    size_t length = a_other.length();

    for (size_t i = 0; i < length; i++) {

        if (a_other[i] != ' ') {

            a_other[turtle] = a_other[i];
            ++turtle;
        }
    }

    a_other.resize(turtle);
}

static void SkipEqualSign(std::string::iterator& a_other) {

    while (*a_other != '=') { 

        ++a_other;
    }
    
    ++a_other;
}

static std::string getParsedString(std::string::iterator& a_iter, std::string& a_str) {

    std::string result;

    std::string::iterator end = a_str.end();

    while (a_iter != end) {

        result += *a_iter;
        ++a_iter;
    }
    
    return result;
}

std::string DeviceConfigParser::ParseId(std::string& a_id) {

    TrimSpaces(a_id);

    a_id.pop_back();

    a_id.erase(a_id.begin());

    return a_id;
}

std::string DeviceConfigParser::ParseStringData(std::string& a_type) {

    std::string::iterator curr = a_type.begin();
    
    TrimSpaces(a_type);

    SkipEqualSign(curr);

    return getParsedString(curr, a_type);
}

int DeviceConfigParser::ParseIntData(std::string& a_str) {

    std::string::iterator curr = a_str.begin();

    TrimSpaces(a_str);

    SkipEqualSign(curr);

    std::string stringParsed = getParsedString(curr, a_str);

    return std::stoi(stringParsed);
}
 
} //DeviceConfigParser