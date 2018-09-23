#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <array>
#include <map>



class Window
{
private:
	GLFWwindow * m_pWindow;
	unsigned int m_Width, m_Height;

	const char* m_Title;

public:
	Window();
	~Window();

	void Init(unsigned int width, unsigned int height, const char* title);

	void CheckControllerState();

private:
	static void InputKey_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void ControllerConnection_Callback(int joy, int event);

	static void WindowResize_Callback(GLFWwindow* window, int width, int height);

	void DetectConnectedControllers();
	void CheckControllerInputs();

	inline void CheckXboxController(const struct SControllerInterface& controller);

public:
	bool ShouldCloseWindow();

	void Clear(GLbitfield mask);

	void SwapBuffers();

	void PollEvents();

	void SetVSync(bool bSync);

	inline double GetTime() const { return glfwGetTime(); }

	inline GLFWwindow* GetGLFWwindowPointer() const { return m_pWindow; }

public:
};

