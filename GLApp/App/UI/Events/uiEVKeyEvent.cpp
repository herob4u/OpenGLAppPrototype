#include <App/UI/Events/uiEVKeyEvent.h>
#include <assert.h>

using namespace uiEV;

KeyEvent::KeyEvent(EEventType _evType)
	: Event(_evType)
	, keyCode(EKeyCode::KeyNone)
	, modifiersMask(EKeyModifiersMask::ModifierNone)
{
}

KeyEvent::KeyEvent(EEventType _evType, EKeyCode _keyCode)
	: Event(_evType)
	, keyCode(_keyCode)
	, modifiersMask(EKeyModifiersMask::ModifierNone)
{
}

KeyEvent::KeyEvent(EEventType _evType, EKeyCode _keyCode, EKeyModifiersMask _modifiersMask)
	: Event(_evType)
	, keyCode(_keyCode)
	, modifiersMask(_modifiersMask)
{
}

KeyEvent::KeyEvent(const KeyEvent& other)
	: Event(other.GetEventType())
	, keyCode(other.GetKeyCode())
	, modifiersMask(other.GetModifiersMask())
{
	assert(false);
}