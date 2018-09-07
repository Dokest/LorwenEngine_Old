#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <array>
#include <map>


enum EControllerBrand
{
	XboxOne,
	Playstation4
};

struct Button
{
	const char* Name;
	bool State;

	Button() { }
	Button(const char* name, unsigned char state)
		: Name(name), State(state) { }
};

template<EControllerBrand>
struct SControllers;

template<>
struct SControllers<XboxOne>
{
	unsigned int ID;
	char Name;
	EControllerBrand Brand;

	bool bInUse = false;

	std::array<Button, 14> PressedButtons =
	{
		Button("XBOX_A", 0),
		Button("XBOX_B", 0),
		Button("XBOX_X", 0),
		Button("XBOX_Y", 0),
		Button("XBOX_LB", 0),
		Button("XBOX_RB", 0),
		Button("XBOX_Select", 0),
		Button("XBOX_Start", 0),
		Button("XBOX_LTClick", 0),
		Button("XBOX_RTClick", 0),
		Button("XBOX_Dpad_Up", 0),
		Button("XBOX_Dpad_Right", 0),
		Button("XBOX_Dpad_Down", 0),
		Button("XBOX_Dpad_Left", 0)
	};

	SControllers() 
		:Name(*"None") { }

	SControllers(const char* name, EControllerBrand brand)
		: Name(*name), Brand(brand) { }
};

class Window
{
private:
	GLFWwindow * m_pWindow;
	unsigned int m_Width, m_Height;
	class GameInputManager* m_pInputManager;

	const char* m_Title;

public:
	Window();
	~Window();

	void Init(unsigned int width, unsigned int height, const char* title, class GameInputManager* inputManager);

	void CheckControllerState();

private:
	static void InputKey_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void ControllerButton_Callback(int joy, int event);

	void CheckXBoxController(SControllers<XboxOne>& controller);

	void DetectConnectedControllers();
	std::array<char, 50> m_Pressed;

	static void AddController(int joy);

	static std::array<SControllers<XboxOne>, 4> m_XBoxControllers;

public:
	bool ShouldCloseWindow();

	void Clear(GLbitfield mask);

	void SwapBuffers();

	void PollEvents();

	void SetVSync(bool bSync);

	inline double GetTime() const { return glfwGetTime(); }

	inline GLFWwindow* GetWindowPtr() const { return m_pWindow; }
};

