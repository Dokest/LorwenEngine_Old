#include "Window.h"

#include <string>
#include <iostream>

#include "Game/GameInputManager.h"

namespace Lorwen {

	std::array<SControllers<XboxOne>, 4> Window::m_XBoxControllers;

	Window::Window()
	{
	}


	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::Init(unsigned int width, unsigned int height, const char* title, class GameInputManager* inputManager)
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

		m_pWindow = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

		glfwMakeContextCurrent(m_pWindow);
		glfwSwapInterval(0);

		/* Callbacks */
		glfwSetKeyCallback(m_pWindow, InputKey_Callback);
		glfwSetJoystickCallback(ControllerButton_Callback);


		if (GLenum err = glewInit() != GLEW_OK)
		{
			printf("GLEW initialization failed!\n");
			fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
			return;
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		printf("%s\n", glGetString(GL_VERSION));

		glfwSetWindowUserPointer(m_pWindow, this);

		DetectConnectedControllers();
		m_XBoxControllers[0].bInUse = true;

		/* Set input Manager Pointer */
		m_pInputManager = inputManager;
	}

	void Window::CheckControllerState()
	{
		int count;

		for (SControllers<XboxOne>& controller : m_XBoxControllers)
		{
			if (!controller.bInUse)
				continue;

			switch (controller.Brand)
			{
			case EControllerBrand::XboxOne:
				CheckXBoxController(controller);
			default:
				break;
			}



		}
	}

	void Window::InputKey_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* userWindow = (Window*)glfwGetWindowUserPointer(window);
		std::string keyString(1, (char)key);

		switch (action)
		{
		case 0: // RELEASE
			userWindow->m_pInputManager->DetectAction(keyString, Release);
			return;
		case 1: // PRESS
			userWindow->m_pInputManager->DetectAction(keyString, Press);
			return;
		case 2: // HOLD
			//userWindow->m_pInputManager->InputKey(key);
			return;
		default:
			return;
		}
		
		printf("Input detected\n");

	}

	void Window::ControllerButton_Callback(int joy, int event)
	{
		if (event == GLFW_CONNECTED)
		{
			AddController(joy);
		}
		else
		{
			

			printf("Joystick disconnected %d\n", joy);
		}

		
	}

	void Window::CheckXBoxController(SControllers<XboxOne>& controller)
	{
		int count;
		const float* axes = glfwGetJoystickAxes(0, &count);

		if (axes[0] != 0)
			m_pInputManager->DetectAxis("XBOX_LeftAxisX", axes[0]);

		if (axes[1] != 0)
			m_pInputManager->DetectAxis("XBOX_LeftAxisY", axes[1]);

		if (axes[2] != 0)
			m_pInputManager->DetectAxis("XBOX_RightAxisX", axes[2]);

		if (axes[3] != 0)
			m_pInputManager->DetectAxis("XBOX_RightAxisY", axes[3]);

		if ((axes[4] + 1) / 2 != 0)
			m_pInputManager->DetectAxis("XBOX_LeftTrigger", (axes[4] + 1) / 2);

		if ((axes[5] + 1) / 2 != 0)
			m_pInputManager->DetectAxis("XBOX_RightTrigger", (axes[5] + 1) / 2);

		const unsigned char* buttons = glfwGetJoystickButtons(controller.ID, &count);

		for (unsigned int i = 0; i < 14; i++)
		{
			if (buttons[i] != controller.PressedButtons[i].State)
			{
				controller.PressedButtons[i].State = (buttons[i] == 0) ? false : true;

				m_pInputManager->DetectAction(controller.PressedButtons[i].Name, (controller.PressedButtons[i].State) == '1' ? Press : Release);
			}
		}

		return;

		unsigned int i = controller.ID;

		if (buttons[0 + i * i] == GLFW_PRESS && controller.PressedButtons[0].State == '0')
		{
			m_pInputManager->DetectAction("XBOX_A", Press);
			m_Pressed[0] = '1';
		}

		if (buttons[1] == GLFW_PRESS && m_Pressed[1] == '0')
		{
			m_pInputManager->DetectAction("XBOX_B", Press);
			m_Pressed[1] = '1';
		}

		if (buttons[2] == GLFW_PRESS && m_Pressed[2] == '0')
			m_pInputManager->DetectAction("XBOX_X", Press);

		if (buttons[3] == GLFW_PRESS && m_Pressed[3] == '0')
			m_pInputManager->DetectAction("XBOX_Y", Press);

		if (buttons[4] == GLFW_PRESS && m_Pressed[4] == '0')
			m_pInputManager->DetectAction("XBOX_LB", Press);

		if (buttons[5] == GLFW_PRESS && m_Pressed[5] == '0')
			m_pInputManager->DetectAction("XBOX_RB", Press);

		if (buttons[6] == GLFW_PRESS && m_Pressed[6] == '0')
			m_pInputManager->DetectAction("XBOX_Select", Press);

		if (buttons[7] == GLFW_PRESS && m_Pressed[7] == '0')
			m_pInputManager->DetectAction("XBOX_Start", Press);

		if (buttons[8] == GLFW_PRESS && m_Pressed[8] == '0')
			m_pInputManager->DetectAction("XBOX_LTClick", Press);

		if (buttons[9] == GLFW_PRESS && m_Pressed[9] == '0')
			m_pInputManager->DetectAction("XBOX_RTClick", Press);

		if (buttons[10] == GLFW_PRESS && m_Pressed[10] == '0')
			m_pInputManager->DetectAction("XBOX_Dpad_Up", Press);

		if (buttons[11] == GLFW_PRESS && m_Pressed[11] == '0')
			m_pInputManager->DetectAction("XBOX_Dpad_Right", Press);

		if (buttons[12] == GLFW_PRESS && m_Pressed[12] == '0')
			m_pInputManager->DetectAction("XBOX_Dpad_Down", Press);

		if (buttons[13] == GLFW_PRESS && m_Pressed[13] == '0')
			m_pInputManager->DetectAction("XBOX_Dpad_Left", Press);

	}

	void Window::DetectConnectedControllers()
	{
		for (int i = 0; i < m_XBoxControllers.size(); i++)
		{
			if (glfwJoystickPresent(i) == GLFW_TRUE)
			{
				AddController(i);
			}

		}
	}

	void Window::AddController(int joy)
	{
		const char* name = glfwGetJoystickName(joy);

		EControllerBrand brand;
		if (name == "Xbox 360 Controller")
		{
			brand = EControllerBrand::XboxOne;

			SControllers<XboxOne> newController;
			newController.Name = *name;
			newController.ID = joy;

			m_XBoxControllers[joy] = newController;
		}
		else if (name == "NEED TO BE TESTED")
		{
			brand = EControllerBrand::Playstation4;
			//SControllers<Playstation4> newController;
		}
		else
			return;


		


		printf("Joystick connected %d %s\n", joy, name);
	}

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

}