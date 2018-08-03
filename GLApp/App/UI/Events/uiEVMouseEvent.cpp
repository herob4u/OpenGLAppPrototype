#include <App/UI/Events/uiEVMouseEvent.h>
#include <assert.h>

using namespace uiEV;

MouseEvent::MouseEvent(EEventType _evType, EMouseMask _mouseMask)
	: Event(_evType)
	, mouseMask(_mouseMask)
{
}

MouseEvent::MouseEvent(EEventType _evType, EMouseMask _mouseMask, const Geom2D::Point& _cursorPos)
	: Event(_evType)
	, mouseMask(_mouseMask)
	, cursorPos(_cursorPos)
{
}

MouseEvent::MouseEvent(const MouseEvent& other)
{
	assert(false);
}