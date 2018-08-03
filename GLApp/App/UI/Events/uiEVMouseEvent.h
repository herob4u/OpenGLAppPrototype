#include <App/UI/Events/uiEVEvent.h>
#include <App/UI/Geom/Point.h>

namespace uiEV
{
	class MouseEvent;
}

/*	A Mouse event notifies listeners of the type of mouse interaction
*	and stores updated positional data of the cursor - i.e curson position
*/
class uiEV::MouseEvent : public uiEV::Event
{
private:
	MouseEvent(EEventType, EMouseMask);
	MouseEvent(EEventType, EMouseMask, const Geom2D::Point&);
	MouseEvent(const MouseEvent& other); // No Copy

	EMouseMask mouseMask;
	Geom2D::Point cursorPos;

public:
	static MouseEvent* Create(EEventType _evType, EMouseMask _mouseMask)
	{
		return new MouseEvent(_evType, _mouseMask);
	}

	static MouseEvent* Create(EEventType _evType, EMouseMask _mouseMask, const Geom2D::Point& _cursorPos)
	{
		return new MouseEvent(_evType, _mouseMask, _cursorPos);
	}

	/*	Get Mouse Mask
	*	Returns the masking enum used to indicate which mouse button was clicked
	*
	*	Get Cursor Pos
	*	Returns the current mouse cursor position as of the signalling of this event.
	*/
	inline EMouseMask GetMouseMask() const;
	inline Geom2D::Point GetCursorPos() const;

};


inline uiEV::EMouseMask 
uiEV::MouseEvent::GetMouseMask() const
{
	return mouseMask;
}

inline Geom2D::Point 
uiEV::MouseEvent::GetCursorPos() const
{
	return cursorPos;
}