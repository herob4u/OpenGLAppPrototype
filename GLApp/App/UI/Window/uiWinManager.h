#include <GLFW\glfw3.h>
#include <App/UI/Window/uiWinGLWindow.h>
#include <vector>

/*	The Window Manager class used by client code to issue
*	the creation of new windows. The manager tracks a stack
*	container of windows from which the item on top of the stack
*	is considered as the currently active context.
*
*	Windows can create sub-windows that share the parent window's 
*	context. This implies, a sub-window does not create a new 
*	stack entry, but rather lives in its parent's scope.
*	If the parent goes out of the focus, all its descending children
*	inherit the focus loss accordingly.
*/

// Restrict the app to support 12 instanced windows on the stack, this makes our CPU Cache's
// life easier. It is unreasonable for the app to produce 12 context windows, an exception shall
// be thrown.
#define MAX_WINDOW_COUNT		12

namespace uiWin
{
	class Manager;
	class GLWindow;

	enum class EWindowHints
	{
		Default		= GLFW_RESIZABLE | GLFW_VISIBLE | GLFW_FOCUSED | GLFW_DECORATED | GLFW_AUTO_ICONIFY,
		Resizable	= GLFW_RESIZABLE,	// Windowed Mode Only; Indicates whether resizable BY THE USER
		Visible		= GLFW_VISIBLE,		// If false, the window is invisible on creation until explicitly set
		Focused		= GLFW_FOCUSED,		// Windowed Mode Only; Created window recieves input focus
		Maximize	= GLFW_MAXIMIZED,	// Windowed Mode Only; Attempts to maximize the window when created
		Decorated	= GLFW_DECORATED,
		Floating	= GLFW_FLOATING,
		AutoIconify	= GLFW_AUTO_ICONIFY
	};

	enum class EWindowMode
	{
		FullScreen	= 0x0,
		Windowed	= 0x1
	};
}


class uiWin::Manager
{
public:
	Manager();
	~Manager();

	/*	Creates a new window and places it on top of the window stack.
	*	If previous windows existed, they lose focus and ignore events.
	*	If no size or mode argument is provided, a fullscreen window
	*	will be created using the monitor's resolution.
	*
	*	@Param int: The Width of the window in screen space
	*	@Param int: The Height of the window in screen space
	*	@Param EWindowMode: Chooses between Fullscreen or Windowed mode
	*	@Param EWindowHints: Flag representing creation hints for the window
	*
	*	@Return bool: Returns true only if the window was successfully created with context
	*/
	bool CreateWindow(EWindowMode mode = EWindowMode::FullScreen, 
					  EWindowHints hints = EWindowHints::Default);

	bool CreateWindow(int, int
					, EWindowMode mode	 = EWindowMode::Windowed 
					, EWindowHints hints = EWindowHints::Default);

	/*	Creates a sub window that shares the context of a parent window.
	*	A sub window is not a new stack entry, and is maintained internally
	*	by the parenting window object.
	*
	*	@Param 
	*/
	bool CreateSubWindow(GLFWwindow*, int, int);
	bool CreateSubWindow(GLFWwindow*, int, int);
private:
	/* GLFW INTERFACE */

	/*	Invoked when a GLFWwindow receives a button click.
	*
	*	@Param GLFWwindow: The window that recieved the button click
	*	@Param int: The code representing the button clicked
	*	@Param int: The code representing the type of action (Press OR Release)
	*	@Param int: A bit vector representing the modifier keys currently held down
	*/
	void MouseButtonHandler(GLFWwindow*, int, int, int);


	/*	Invoked when the mouse cursor in a GLFWwindow updates position.
	*
	*	@Param GLFWwindow: The window that recieved the mouse movement
	*	@Param int:	The new X-coordinate of the cursor
	*	@Param int: The new Y-coordinate of the cursor
	*/
	void MouseMoveHandler(GLFWwindow*, double, double);


	/*	Invoked when the mouse cursor exits or enters a window
	*
	*	@Param GLFWwindow: The window that was notified of entry/exit
	*	@Param int: GLFW_TRUE or GLFW_FALSE indicating whether
	*				it entered or exited respectively.
	*/
	void MouseCursorExitHandler(GLFWwindow*, int);


	/*	Invoked when a scroll occurs (primarily due to a mouse wheel)
	*
	*	@Param GLFWwindow: The window that received the scroll
	*	@Param double: The scroll OFFSET in the X-position
	*	@Param double: The scroll OFFSET in the Y-position
	*/
	void MouseWheelHandler(GLFWwindow*, double, double);


	/*	Invoked when a keyboard button is pressed or released
	*
	*	@Param GLFWwindow: The window that recieved the keyboard event
	*	@Param int: The GLFW keycode for the key that was pressed/released
	*	@Param int: The system specific scan-code for the key (we don't need this yet)
	*	@Param int: The code for action associated with the event (Press,Release,Hold)
	*	@Param int: A bit vector representing modifier keys currently held.
	*/
	void KeyInputHandler(GLFWwindow*, int, int, int, int);

	
	/*	[NOT IN USE]
	*	Invoked when a Unicode character has been entered regardless of prior
	*	key input events. This is useful for supporting IME or foreign languages
	*	that have indirect means of inputting characters. The Modifiers variant
	*	of the function handles the case where a character was input while a
	*	modifier key was held.
	*
	*	@Param GLFWwindow: The window that recieved the char event
	*	@Param unsigned int: The Unicode code representing the character
	*	@Param int: Bit vector representing modifier keys currently held
	*/
	void CharInputHandler(GLFWwindow*, unsigned int);
	void CharModifiersInputHandler(GLFWwindow*, unsigned int, int);

	/*	Invoked when FILE(s) has been dropped unto a window.
	*
	*	@Param GLFWwindow: The window the files have been dropped to
	*	@Param int: The number of files dropped
	*	@Param const char**: An array that contains UTF-8 encoded file paths (null terminated)
	*/
	void DragDropHandler(GLFWwindow*, int, const char**);

	

	/* Window Operations */

	inline int16_t FindWindowHandle(const GLFWwindow*) const;

	// Toggles specified window hints flags
	inline void SetWindowHints(EWindowHints);
	inline void ResetWindowHints();

private:
	// Initially at -1, improves caching since it is very likely the same window is being accessed again
	uint8_t lastAccessedWindow;

	// We allocate our objects statically so that they are located contigously in memory, this gives
	// us more chances for cache hits. When operating on windows, we either return references or 
	// "point" to them via array indices.
	GLWindow windowStack[MAX_WINDOW_COUNT];
};


// Bitwise OR operation to allow us to set window hint flags conveniently
inline uiWin::EWindowHints 
operator | (uiWin::EWindowHints lhs, uiWin::EWindowHints rhs)
{
	return static_cast<uiWin::EWindowHints>( static_cast<int>(lhs) | static_cast<int>(rhs) );
}

// Toggles specified window hints flags ON
inline void 
uiWin::Manager::SetWindowHints(EWindowHints hints)
{
	glfwWindowHint(static_cast<int>(hints), GLFW_TRUE);
}

inline void 
uiWin::Manager::ResetWindowHints()
{
	glfwDefaultWindowHints();
}