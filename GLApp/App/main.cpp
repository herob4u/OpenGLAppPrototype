#include <GLFW/glfw3.h>

#include <iostream>
#include <assert.h>

/*	Declaration of function used to handle error messages from the GLFW app
*/
void GLErrorCallback(int error, const char* description);

int main()
{
	glfwSetErrorCallback(GLErrorCallback);

	// Initialize the OpenGL Application
	assert(glfwInit() && "GLFW Failed to initialize, execution cannot continue");

	// Actual creation of a window (to be encapsulated)
	GLFWwindow* window = glfwCreateWindow(640, 640, "Deomar", NULL, NULL);
	assert(window && "GLFWWindow could not be created, execution cannot continue");
	glfwMakeContextCurrent(window);

	while ( !glfwWindowShouldClose(window) )
	{
		glfwPollEvents();
	}

	// Effectively destroys the current context
	glfwDestroyWindow(window);

	// Finalize the OpenGL Application
	glfwTerminate();

	return 0;
}


void GLErrorCallback(int error, const char* description)
{
	fprintf(stderr, "[ERROR %i]: %s\n", error, description);
}