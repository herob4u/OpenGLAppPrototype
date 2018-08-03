#include <cstdint>
#include <App/Utils/EnumMacros.h>

namespace uiEV
{
	/*	NOTICE:
	*	Ensure the corresponding string tables in the cpp are 
	*	modified if any of these enums are edited.
	*/

	enum class EEventType : uint8_t
	{
		EventTypeNone = 0,

		MouseButtonPress,
		MouseButtonRelease,
		MouseMove,
		MouseWheel,

		KeyPress,
		KeyRelease,
	};

	enum class EMouseMask : uint8_t
	{
		MouseNone	= 0x0,
		MouseLeft	= 0x1,
		MouseRight	= 0x2,
		MouseMiddle = 0x4
	};

	enum class EKeyModifiersMask : uint8_t
	{
		ModifierNone	= 0x0,
		ModifierShift	= 0x1,
		ModifierCtrl	= 0x2,
		ModifierAlt		= 0x4,
		ModifierCmd		= 0x8
	};

	enum class EKeyCode : uint8_t
	{
		KeyNone = 0,
		KeySpace,
		KeyEscape,
		KeyTab,

		KeyInsert,
		KeyPageUp,
		KeyPageDown,
		KeyDelete,
		KeyBackspace,
		KeyHome,
		KeyReturn,

		KeyUp,
		KeyDown,
		KeyLeft,
		KeyRight,

		KeyA,
		KeyB,
		KeyC,
		KeyD,
		KeyE,
		KeyF,
		KeyG,
		KeyH,
		KeyI,
		KeyJ,
		KeyK,
		KeyL,
		KeyM,
		KeyN,
		KeyO,
		KeyP,
		KeyQ,
		KeyR,
		KeyS,
		KeyT,
		KeyU,
		KeyV,
		KeyW,
		KeyX,
		KeyY,
		KeyZ,

		Key0,
		Key1,
		Key2,
		Key3,
		Key4,
		Key5,
		Key6,
		Key7,
		Key8,
		Key9,

		KeyF1,
		KeyF2,
		KeyF3,
		KeyF4,
		KeyF5,
		KeyF6,
		KeyF7,
		KeyF8,
		KeyF9,
		KeyF10,
		KeyF11,
		KeyF12
	};

	const char* AsString(const EKeyCode& keyCode);
	const char* AsString(const EEventType& evType);
	const char* AsString(const EMouseMask& mouseMask);
	const char* AsString(const EKeyModifiersMask& keyMod);

	inline EMouseMask operator | (EMouseMask lhs, EMouseMask rhs);
	inline EMouseMask operator & (EMouseMask lhs, EMouseMask rhs);
	inline void operator |= (EMouseMask& lhs, EMouseMask rhs);
	inline void operator &= (EMouseMask& lhs, EMouseMask rhs);

	inline EKeyModifiersMask operator | (EKeyModifiersMask lhs, EKeyModifiersMask rhs);
	inline EKeyModifiersMask operator & (EKeyModifiersMask lhs, EKeyModifiersMask rhs);
	inline void operator |= (EKeyModifiersMask& lhs, EKeyModifiersMask rhs);
	inline void operator &= (EKeyModifiersMask& lhs, EKeyModifiersMask rhs);
}

/* Bit Operators Inline Definitions */
inline uiEV::EMouseMask 
uiEV::operator | (EMouseMask lhs, EMouseMask rhs)
{
	return static_cast<uiEV::EMouseMask>( static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs) );
}

inline uiEV::EMouseMask 
uiEV::operator & (EMouseMask lhs, EMouseMask rhs)
{
	return static_cast<uiEV::EMouseMask>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}

inline void 
uiEV::operator |= (EMouseMask& lhs, EMouseMask rhs)
{
	static_cast<uiEV::EMouseMask>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}

inline void 
uiEV::operator &= (EMouseMask& lhs, EMouseMask rhs)
{
	static_cast<uiEV::EMouseMask>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}



inline uiEV::EKeyModifiersMask 
uiEV::operator | (EKeyModifiersMask lhs, EKeyModifiersMask rhs)
{
	return static_cast<uiEV::EKeyModifiersMask>(static_cast<EKeyModifiersMask>(lhs) | static_cast<EKeyModifiersMask>(rhs));
}

inline uiEV::EKeyModifiersMask 
uiEV::operator & (EKeyModifiersMask lhs, EKeyModifiersMask rhs)
{
	return static_cast<uiEV::EKeyModifiersMask>(static_cast<EKeyModifiersMask>(lhs) & static_cast<EKeyModifiersMask>(rhs));
}

inline void 
uiEV::operator |= (EKeyModifiersMask& lhs, EKeyModifiersMask rhs)
{
	static_cast<uiEV::EKeyModifiersMask>(static_cast<EKeyModifiersMask>(lhs) | static_cast<EKeyModifiersMask>(rhs));
}

inline void 
uiEV::operator &= (EKeyModifiersMask& lhs, EKeyModifiersMask rhs)
{
	static_cast<uiEV::EKeyModifiersMask>(static_cast<EKeyModifiersMask>(lhs) & static_cast<EKeyModifiersMask>(rhs));
}