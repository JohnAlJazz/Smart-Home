#ifndef ABS_NOTIFIER_HXX
#define ABS_NOTIFIER_HXX

#include "device_key_id_translator.hpp"
#include "event.hpp"

namespace observer {

class AbsNotifier {
public:
	~AbsNotifier() = default;
	
	virtual void Notify(std::shared_ptr<event::Event> a_event) = 0;
};

}	//observer

#endif //ABS_NOTIFIER_HXX