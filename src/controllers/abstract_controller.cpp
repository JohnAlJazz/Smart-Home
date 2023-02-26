#include "abstract_controller.hpp"

namespace controllers {

AbstractController::AbstractController(const std::string& a_id)
: m_id(a_id)
{
}

const std::string& AbstractController::GetID()
{
    return m_id;
}

} //controllers