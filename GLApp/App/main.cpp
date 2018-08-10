#include <App/UI/Window/uiWinManager.h>

#include <iostream>
#include <assert.h>

/*	Declaration of function used to handle error messages from the GLFW app
*/
void GLErrorCallback(int error, const char* description);

int main()
{
	// Create a window manager responsible for spawning and managing windows
	uiWin::Manager* mgr = uiWin::Manager::Instance();

	glfwSetErrorCallback(GLErrorCallback);

	// Initialize the OpenGL Application
	assert(glfwInit() && "GLFW Failed to initialize, execution cannot continue");

	mgr->CreateWindow(uiWin::EWindowMode::Windowed);

	while (1)
	{
		glfwPollEvents();
	}

	// Finalize the OpenGL Application
	glfwTerminate();

	return 0;
}


void GLErrorCallback(int error, const char* description)
{
	fprintf(stderr, "[ERROR %i]: %s\n", error, description);
}