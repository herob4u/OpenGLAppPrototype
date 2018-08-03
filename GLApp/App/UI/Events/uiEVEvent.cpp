#include "uiEVEvent.h"
#include <assert.h>

using namespace uiEV;

Event::Event(EEventType _eventType)
	:eventType(_eventType)
{
}

Event::~Event()
{
}

EEventType Event::GetEventType() const
{
	return eventType;
}
