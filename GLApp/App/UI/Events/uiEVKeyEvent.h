#include <App/UI/Events/uiEVEvent.h>

namespace uiEV
{
	class KeyEvent;
}

class uiEV::KeyEvent : public uiEV::Event
{
private:
	KeyEvent(EEventType);
	KeyEvent(EEventType, EKeyCode);
	KeyEvent(EEventType, EKeyCode, EKeyModifiersMask);

	KeyEvent(const KeyEvent& other); // No Copy

public:
	KeyEvent* Create(EEventType _evType)
	{
		return new KeyEvent(_evType);
	}

	KeyEvent* Create(EEventType _evType, EKeyCode _keyCode)
	{
		return new KeyEvent(_evType, _keyCode);
	}

	KeyEvent* Create(EEventType _evType, EKeyCode _keyCode, EKeyModifiersMask _modifiersMask)
	{
		return new KeyEvent(_evType, _keyCode, _modifiersMask);
	}

	/*	Get Key Name
	*	Retrieves the stringified name associated with this event's key code
	*/
	inline const char* GetKeyName() const;

	/*	Get Key Code
	*	Retrieves the actual key code associated with this event - describing the button sending the event
	*/
	inline EKeyCode GetKeyCode() const;

	/*	Get Modifier Masks
	*	Retrieves the enum mask that indicates which modifier keys (Shift,Alt,Ctrl, etc) are currently pressed
	*/
	inline EKeyModifiersMask GetModifiersMask() const;

private:
	EKeyCode keyCode;
	EKeyModifiersMask modifiersMask;
};


inline const char* 
uiEV::KeyEvent::GetKeyName() const
{
	return AsString(keyCode);
}

inline uiEV::EKeyCode 
uiEV::KeyEvent::GetKeyCode() const
{
	return keyCode;
}

inline uiEV::EKeyModifiersMask 
uiEV::KeyEvent::GetModifiersMask() const
{
	return modifiersMask;
}