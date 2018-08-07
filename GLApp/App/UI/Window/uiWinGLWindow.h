#include <GLFW\glfw3.h>

namespace uiEV
{
	class EventTranslator;
}

namespace uiWin
{
	class GLWindow;

	enum class EWindowMode
	{
		FullScreen = 0x0,
		Windowed = 0x1
	};

	struct FWindowHandle
	{
		const GLWindow* Window;
		const GLFWwindow* GlfwHandle;	

		FWindowHandle() : Window(nullptr), GlfwHandle(nullptr) {}
		FWindowHandle(const GLWindow* _Window, const GLFWwindow* _GlfwHandle) : Window(_Window), GlfwHandle(_GlfwHandle) {}

		bool IsValid() const { return Window && GlfwHandle; }
	};
	
}

class uiWin::GLWindow
{
public:
	// important methods here...
	static const GLWindow* Create(int, int, EWindowMode);
	static void Destroy(GLWindow*);

	void Update();

	void SetWindowMode(EWindowMode);
	void Activate() const;

	// Accessors
	inline const GLFWwindow* GetGlfwWindow() const;
	inline EWindowMode GetWindowMode() const;

	inline int X() const;
	inline int Y() const;
	inline int Width() const;
	inline int Height() const;

protected:
	virtual void OnPreDraw();
	virtual void OnDraw();
	virtual void OnPostDraw();

private:
	GLWindow(GLFWwindow*, int, int, EWindowMode);
	~GLWindow();

	void SetGlfwWindow(GLFWwindow*);

	// The actual glfwWindow associated with this window object - this is the bridge to OpenGL
	GLFWwindow* glfwWindow;
	EWindowMode windowMode;

	int posX;
	int posY;
	int width;
	int height;
};


inline const GLFWwindow* uiWin::GLWindow::GetGlfwWindow() const										{ return glfwWindow; }
inline uiWin::EWindowMode uiWin::GLWindow::GetWindowMode() const									{ return windowMode; }

inline int uiWin::GLWindow::X() const																{ return posX; }
inline int uiWin::GLWindow::Y() const																{ return posY; }
inline int uiWin::GLWindow::Width() const															{ return width; }
inline int uiWin::GLWindow::Height() const															{ return height; }
