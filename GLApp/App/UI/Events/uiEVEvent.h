#include <App/UI/Events/uiEVConstants.h>

#ifndef UI_EV_EVENT_H
#define UI_EV_EVENT_H

namespace uiEV
{
	class Event;
}

class uiEV::Event
{
protected:
	/*	Construct a event of a specific type
	*	Derived classes must call this upon construction
	*	to properly define what type of event is being dealt with.
	*
	*	The EventType provides means for the dispatch and translation system
	*	to handle events generically.
	*/
	Event(EEventType);
	virtual ~Event();

	/*	Cannot copy an Event object
	*/
	Event(const Event& other);

public:
	/*	Get Event Type
	*
	*	Returns the EventType enum associated with this event object.
	*/
	EEventType GetEventType() const;

private:
	EEventType eventType;
};

#endif // UI_EV_EVENT_H