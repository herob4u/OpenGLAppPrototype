#include "uiEVConstants.h"

// Maps EventTypes to a corresponding name. Order is essential and must follow the order
// the event types were defined in uiEVConstants.h.
static const char* EventTypeNames[] =
{
	"Unknown",

	"MouseButtonPress",
	"MouseButtonRelease",
	"MouseMove",
	"MouseWheel",

	"KeyPress",
	"KeyRelease",
	"KeyRepeat"
};

static const char* MouseMaskNames[] =
{
	"Unknown",
	"MouseLeftClick",
	"MouseRightClick",
	"MouseMiddleClick"
};

static const char* KeyModifiersMaskNames[] =
{
	"Unknown",
	"Shift",
	"Ctrl",
	"Alt",
	"Cmd"
};

// Maps KeyCodes to a corresponding name. Order is essential and must follow the order
// the codes were defined in uiEVConstants.h.
static const char* KeyCodeNames[] =
{
	"Unknown",
	"Space",
	"Escape",
	"Tab",

	"Insert",
	"PageUp",
	"PageDown",
	"Delete",
	"Backspace",
	"Home",
	"Return",

	"Up",
	"Down",
	"Left",
	"Right",

	"A",
	"B",
	"C",
	"D",
	"E",
	"F",
	"G",
	"H",
	"I",
	"J",
	"K",
	"L",
	"M",
	"N",
	"O",
	"P",
	"Q",
	"R",
	"S",
	"T",
	"U",
	"V",
	"W",
	"X",
	"Y",
	"Z",

	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	
	"F1",
	"F2",
	"F3",
	"F4",
	"F5",
	"F6",
	"F7",
	"F8",
	"F9",
	"F10",
	"F11",
	"F12"
};


const char* uiEV::AsString(const EKeyCode& keyCode)
{
	return KeyCodeNames [ static_cast<uint8_t>(keyCode) ];
}

const char* uiEV::AsString(const EEventType& evType)
{
	return EventTypeNames [ static_cast<uint8_t>(evType) ];
}

const char* uiEV::AsString(const EMouseMask& mouseMask)
{
	return MouseMaskNames[static_cast<uint8_t>(mouseMask)];
}

const char* uiEV::AsString(const EKeyModifiersMask& keyMod)
{
	return KeyModifiersMaskNames[static_cast<uint8_t>(keyMod)];
}