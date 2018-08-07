#include <App/UI/Window/uiWinGLWindow.h>
#include <assert.h>

#include <stdio.h> // for printf only

using namespace uiWin;


const GLWindow* GLWindow::Create(int width, int height, EWindowMode mode)
{
	GLFWwindow* glfwWindow = glfwCreateWindow(width, height, "Window", NULL, NULL);
	assert(glfwWindow);

	GLWindow* glWindow = new GLWindow(glfwWindow, width, height, mode);
	assert(glWindow);

	glWindow->SetGlfwWindow(glfwWindow);

	return glWindow;
}

// Just call delete for now
void GLWindow::Destroy(GLWindow* window)
{
	// Either you are illegally destroying a non-existent window, or const_cast conversion fails
	assert(window);
	delete window;

}

GLWindow::GLWindow(GLFWwindow* glfwWin, int _width, int _height, EWindowMode mode)
	: glfwWindow(glfwWin)
	, width(_width)
	, height(_height)
	, posX(50)
	, posY(50)
	, windowMode(mode)
{
	printf("GLWindow Constructor\n");
}

GLWindow::~GLWindow()
{
	printf("~GLWindow\n");

	// Destroy the OpenGL context first
	glfwDestroyWindow(glfwWindow);

	// Event Signalling here...
}


void GLWindow::Update()
{
	OnPreDraw();
	OnDraw();
	OnPostDraw();
}

void GLWindow::Activate() const
{
	// Every GLWindow must manage a glfwWindow. Calling activate before a GLWindow is 
	// fully initializes is an invalid call.
	assert(glfwWindow);
	glfwMakeContextCurrent(glfwWindow);
	printf("Activate Called\n");
}

void GLWindow::OnPreDraw()
{

}

void GLWindow::OnDraw()
{

}

void GLWindow::OnPostDraw()
{

}


void GLWindow::SetGlfwWindow(GLFWwindow* _glfwWindow)
{
	glfwWindow = _glfwWindow;
}

void GLWindow::SetWindowMode(EWindowMode mode)
{
	windowMode = mode;
}