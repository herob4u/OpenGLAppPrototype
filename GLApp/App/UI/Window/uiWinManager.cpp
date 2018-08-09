#include <App/UI/Window/uiWinManager.h>

using namespace uiWin;

Manager::Manager()
	:currWindow(-1)
{
	printf("uiWinManager");
}

Manager::~Manager()
{
	printf("~uiWinManager");

	// Cleanup all context(s)
	// ...
}


// Create a GLWindow of specified flags. If windowed mode, default to a resolution of 640x480
bool Manager::CreateWindow(EWindowMode mode,
						   EWindowHints hints)
{
	assert(glfwGetPrimaryMonitor());
	SetWindowHints(hints);

	int count;
	const GLFWvidmode* vidMode = glfwGetVideoModes(glfwGetPrimaryMonitor(), &count);

	int width = -1;
	int height = -1;

	switch (mode)
	{
		case EWindowMode::FullScreen:
		{
			width = vidMode->width;
			height = vidMode->height;
		}
		break;

		case EWindowMode::Windowed:
		{
			width = 640;
			height = 480;
		}
		break;
	}

	assert(width > 0 && height > 0);

	const GLWindow* glWindow = GLWindow::Create(width, height, mode);
	FWindowHandle handle(glWindow, glWindow->GetGlfwWindow());

	AddWindow(handle);
	SetWindowMode(mode);
	return true;
}

// Create a GLWindow of specified flags but with specified resolutions. If full screen, the resolution is overriden.
bool Manager::CreateWindow(int width, int height
						 , EWindowMode mode
						 , EWindowHints hints)
{
	return false;
}

bool Manager::CreateSubWindow(GLFWwindow*, int, int)
{
	return false;
}


// Destroy the window on top of the stack and update the indexer
void Manager::PopWindow()
{
	assert(windowStack[currWindow].IsValid());

	GLWindow::Destroy(const_cast<GLWindow*>(windowStack[currWindow].Window));
	currWindow--;

	// There remains another window in the stack, point to it.
	if (currWindow >= 0)
	{
		assert(windowStack[currWindow].IsValid()); // Windows stacked on top of each other CAN NEVER BE INVALID! UNDEFINED BEHAVIOUR
		windowStack[currWindow].Window->Activate();
	}
}

bool Manager::AddWindow(const FWindowHandle& _handle)
{
	assert(_handle.IsValid());

	if (currWindow == -1)
	{
		windowStack[0] = _handle;
	}
	else
	{
		if (currWindow == MAX_WINDOW_COUNT - 1)
			return false;

		// Hitting this assertion implies you are attemtping to overwrite an existing window.
		// This assertion should never occur - revise window stack addition operations and management.
		assert(!windowStack[currWindow + 1].IsValid());
		windowStack[currWindow + 1] = _handle;
		assert(windowStack[currWindow].IsValid());
	}

	// Move the indexer forward to point to the most recent window and activate it
	currWindow++;
	_handle.Window->Activate();
	return true;
}

void Manager::SetWindowMode(EWindowMode mode)
{	
	GLFWwindow* glfwWin = const_cast<GLFWwindow*>(windowStack[currWindow].GlfwHandle);
	GLWindow* glWin = const_cast<GLWindow*>(windowStack[currWindow].Window);
	assert(glfwWin && glWin);

	switch (mode)
	{
		case EWindowMode::FullScreen:
		{
			// We cannot make a full screen without a valid primary monitor. We do not iterate our monitors right now
			if (!glfwGetPrimaryMonitor())
				return;

			glfwSetWindowMonitor(glfwWin, glfwGetPrimaryMonitor(), glWin->X(), glWin->Y(), glWin->Width(), glWin->Height(), GLFW_DONT_CARE);
		}
		break;

		case EWindowMode::Windowed:
		{
			glfwSetWindowMonitor(glfwWin, NULL, glWin->X(), glWin->Y(), glWin->Width(), glWin->Height(), GLFW_DONT_CARE);
		}
		break;

		default:
		assert(false);
		break;
	}

	// Update the window mode in the GLWindow to reflect the change
	glWin->SetWindowMode(mode);
}





/* GLFW INTERFACE */

/*	==============================================
*				Window Event Handlers
*	==============================================*/


void Manager::WindowClosedHandler(GLFWwindow* window) 
{ 
	printf("Window Close Handler\n"); 
}


void Manager::WindowRefreshHandler(GLFWwindow*){}


void Manager::WindowMovedHandler(GLFWwindow*, int, int){}


void Manager::WindowResizedHandler(GLFWwindow*, int, int) {}



/*	==============================================
*				Input Event Handlers
*	==============================================*/

void Manager::MouseButtonHandler(GLFWwindow*, int, int, int) {}


void Manager::MouseMoveHandler(GLFWwindow*, double, double) { printf("Mouse Move\n"); }


void Manager::MouseCursorExitHandler(GLFWwindow*, int) {}


void Manager::MouseWheelHandler(GLFWwindow*, double, double) {}


void Manager::KeyInputHandler(GLFWwindow*, int, int, int, int) {}


void Manager::CharInputHandler(GLFWwindow*, unsigned int) {}
void Manager::CharModifiersInputHandler(GLFWwindow*, unsigned int, int) {}


void Manager::DragDropHandler(GLFWwindow*, int, const char**) {}


/* Event Binding */
void Manager::BindEventsToWindow(GLFWwindow* window) const
{
	glfwSetWindowCloseCallback(window, *&Manager::WindowClosedHandler);
}

void Manager::UnbindEventsFromWindow(GLFWwindow* window) const
{

}