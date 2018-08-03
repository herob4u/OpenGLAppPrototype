#include <App/UI/Events/uiEVConstants.h>

namespace uiEV
{
	class EventTranslator;

}

class uiEV::EventTranslator
{
public:
	EventTranslator();
	~EventTranslator();

	void SetUseHashedMapping(bool);
	EEventType TranslateEventType(uint8_t _glfwAction);

private:
	bool bUseHashedMapping;
};