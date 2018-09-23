#include "Window.h"

#include <string>
#include <iostream>

#include "Game/GameInputManager.h" // Delete after LGameInputManager is completely integrated!!!!
#include "Game/LGameInputManager.h"

Window::Window()
{
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Init(unsigned int width, unsigned int height, const char* title)
{
	m_Width = width;
	m_Height = height;
	m_Title = title;

	if (glfwInit() == GLFW_FALSE)
	{
		printf("GLFW failed to initiate!\n");
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	glfwWindowHint(GLFW_DECORATED, true); // Eliminates decorations

	m_pWindow = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

	glfwMakeContextCurrent(m_pWindow);
	glfwSwapInterval(0);

	/* Callbacks */
	glfwSetKeyCallback(m_pWindow, InputKey_Callback);
	glfwSetJoystickCallback(ControllerConnection_Callback);


	if (GLenum err = glewInit() != GLEW_OK)
	{
		printf("GLEW initialization failed!\n");
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return;
	}

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	

	printf("%s\n", glGetString(GL_VERSION));

	glfwSetWindowUserPointer(m_pWindow, this);

	glfwSetWindowSizeCallback(m_pWindow, WindowResize_Callback);

	DetectConnectedControllers();

}

void Window::CheckControllerState()
{

	CheckControllerInputs();
// 	int count;
// 
// 	for (SControllers<XboxOne>& controller : m_XBoxControllers)
// 	{
// 		if (!controller.bInUse)
// 			continue;
// 
// 		switch (controller.Brand)
// 		{
// 		case EControllerBrand::XboxOne:
// 			CheckXBoxController(controller);
// 		default:
//			break;
// 		}
// 
// 
// 
// 	}
}

void Window::InputKey_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
// 	Window* userWindow = (Window*)glfwGetWindowUserPointer(window);
// 	std::string keyString(1, (char)key);
// 
// 	switch (action)
// 	{
// 	case 0: // RELEASE
// 		userWindow->m_pInputManager->DetectAction(keyString, EInputState::Release);
// 		return;
// 	case 1: // PRESS
// 		userWindow->m_pInputManager->DetectAction(keyString, EInputState::Press);
// 		return;
// 	case 2: // HOLD
// 		userWindow->m_pInputManager->DetectAction(keyString, EInputState::Press);
// 		return;
// 	default:
		return;
// 	}
}

void Window::WindowResize_Callback(GLFWwindow* window, int width, int height)
{
	printf("Window resized!\n");

	glfwSetWindowSize(window, width, height);
}

void Window::ControllerConnection_Callback(int joy, int event)
{
	if (event == GLFW_CONNECTED)
	{

	}
	else
	{
		printf("Joystick disconnected %d\n", joy);
	}
}

void Window::DetectConnectedControllers()
{
	for (unsigned int i = 0; i < 16; i++)
	{
		if (glfwJoystickPresent(i) == GLFW_TRUE)
			ControllerConnection_Callback(i, GLFW_CONNECTED);
	}
}

void Window::CheckControllerInputs()
{
// 	for (const SControllerInterface& controller : GameInputManager::GetConnectedControllers())
// 	{
// 		switch (controller.Tag)
// 		{
// 		case XboxOne:
// 			CheckXboxController(controller);
// 			break;
// 		default:
//			break;
// 		}
// 		
// 	}
}

void Window::CheckXboxController(const struct SControllerInterface& controller)
{
// 	int count;
// 	const float* axes = glfwGetJoystickAxes(controller.ID, &count);
// 
// 	if (axes[0] != 0)
// 		GameInputManager::ReceiveActionInput("XBOX_LeftAxisX", axes[0], controller.ID);
// 
// 	if (axes[1] != 0)
// 		GameInputManager::ReceiveActionInput("XBOX_LeftAxisY", axes[1], controller.ID);
// 
// 	if (axes[2] != 0)
// 		GameInputManager::ReceiveActionInput("XBOX_RightAxisX", axes[2], controller.ID);
// 
// 	if (axes[3] != 0)
// 		GameInputManager::ReceiveActionInput("XBOX_RightAxisY", axes[3], controller.ID);
// 
// 	if ((axes[4] + 1) / 2 != 0)
// 		GameInputManager::ReceiveActionInput("XBOX_LeftTrigger", (axes[4] + 1) / 2, controller.ID);
// 
// 	if ((axes[5] + 1) / 2 != 0)
// 		GameInputManager::ReceiveActionInput("XBOX_RightTrigger", (axes[5] + 1) / 2, controller.ID);
// 
// 	const unsigned char* buttons = glfwGetJoystickButtons(controller.ID, &count);
// 
// 	for (unsigned int i = 0; i < 14; i++)
// 	{
// 		GameInputManager::ReceiveActionInput("Test", 1.0f, controller.ID);
// 	}

}

//void Window::CheckXBoxController(SControllers<XboxOne>& controller)
//{
//	int count;
//	const float* axes = glfwGetJoystickAxes(0, &count);
//
//	if (axes[0] != 0)
//		m_pInputManager->DetectAxis("XBOX_LeftAxisX", axes[0]);
//
//	if (axes[1] != 0)
//		m_pInputManager->DetectAxis("XBOX_LeftAxisY", axes[1]);
//
//	if (axes[2] != 0)
//		m_pInputManager->DetectAxis("XBOX_RightAxisX", axes[2]);
//
//	if (axes[3] != 0)
//		m_pInputManager->DetectAxis("XBOX_RightAxisY", axes[3]);
//
//	if ((axes[4] + 1) / 2 != 0)
//		m_pInputManager->DetectAxis("XBOX_LeftTrigger", (axes[4] + 1) / 2);
//
//	if ((axes[5] + 1) / 2 != 0)
//		m_pInputManager->DetectAxis("XBOX_RightTrigger", (axes[5] + 1) / 2);
//
//	const unsigned char* buttons = glfwGetJoystickButtons(controller.ID, &count);
//
//	for (unsigned int i = 0; i < 14; i++)
//	{
//		if (buttons[i] != controller.PressedButtons[i].State)
//		{
//			controller.PressedButtons[i].State = (buttons[i] == 0) ? false : true;
//		}
//
//		m_pInputManager->DetectAction(controller.PressedButtons[i].Name, (controller.PressedButtons[i].State) == true ? Press : Release);
//	}
//
//	return;
//
//	unsigned int i = controller.ID;
//
//	if (buttons[0 + i * i] == GLFW_PRESS && controller.PressedButtons[0].State == '0')
//	{
//		m_pInputManager->DetectAction("XBOX_A", Press);
//		m_Pressed[0] = '1';
//	}
//
//	if (buttons[1] == GLFW_PRESS && m_Pressed[1] == '0')
//	{
//		m_pInputManager->DetectAction("XBOX_B", Press);
//		m_Pressed[1] = '1';
//	}
//
//	if (buttons[2] == GLFW_PRESS && m_Pressed[2] == '0')
//		m_pInputManager->DetectAction("XBOX_X", Press);
//
//	if (buttons[3] == GLFW_PRESS && m_Pressed[3] == '0')
//		m_pInputManager->DetectAction("XBOX_Y", Press);
//
//	if (buttons[4] == GLFW_PRESS && m_Pressed[4] == '0')
//		m_pInputManager->DetectAction("XBOX_LB", Press);
//
//	if (buttons[5] == GLFW_PRESS && m_Pressed[5] == '0')
//		m_pInputManager->DetectAction("XBOX_RB", Press);
//
//	if (buttons[6] == GLFW_PRESS && m_Pressed[6] == '0')
//		m_pInputManager->DetectAction("XBOX_Select", Press);
//
//	if (buttons[7] == GLFW_PRESS && m_Pressed[7] == '0')
//		m_pInputManager->DetectAction("XBOX_Start", Press);
//
//	if (buttons[8] == GLFW_PRESS && m_Pressed[8] == '0')
//		m_pInputManager->DetectAction("XBOX_LTClick", Press);
//
//	if (buttons[9] == GLFW_PRESS && m_Pressed[9] == '0')
//		m_pInputManager->DetectAction("XBOX_RTClick", Press);
//
//	if (buttons[10] == GLFW_PRESS && m_Pressed[10] == '0')
//		m_pInputManager->DetectAction("XBOX_Dpad_Up", Press);
//
//	if (buttons[11] == GLFW_PRESS && m_Pressed[11] == '0')
//		m_pInputManager->DetectAction("XBOX_Dpad_Right", Press);
//
//	if (buttons[12] == GLFW_PRESS && m_Pressed[12] == '0')
//		m_pInputManager->DetectAction("XBOX_Dpad_Down", Press);
//
//	if (buttons[13] == GLFW_PRESS && m_Pressed[13] == '0')
//		m_pInputManager->DetectAction("XBOX_Dpad_Left", Press);
//
//}

// void Window::DetectConnectedControllers()
// {
// 	for (int i = 0; i < m_XBoxControllers.size(); i++)
// 	{
// 		if (glfwJoystickPresent(i) == GLFW_TRUE)
// 		{
// 			AddController(i);
// 		}
// 
// 	}
// }

// void Window::AddController(int joy)
// {
// 	const char* name = glfwGetJoystickName(joy);
// 
// 	EControllerBrand brand;
// 	if (name == "Xbox 360 Controller")
// 	{
// 		brand = EControllerBrand::XboxOne;
// 
// 		SControllers<XboxOne> newController;
// 		newController.Name = *name;
// 		newController.ID = joy;
// 
// 		m_XBoxControllers[joy] = newController;
// 	}
// 	else if (name == "NEED TO BE TESTED")
// 	{
// 		brand = EControllerBrand::Playstation4;
// 		//SControllers<Playstation4> newController;
// 	}
// 	else
// 		return;
// 
// 
// 	
// 
// 
// 	printf("Joystick connected %d %s\n", joy, name);
// }

bool Window::ShouldCloseWindow()
{
	return glfwWindowShouldClose(m_pWindow);
}

void Window::Clear(GLbitfield mask)
{
	glClear(mask);
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(m_pWindow);
}

void Window::PollEvents()
{
	glfwPollEvents();
}

void Window::SetVSync(bool bSync)
{
	glfwSwapInterval(bSync);
}
