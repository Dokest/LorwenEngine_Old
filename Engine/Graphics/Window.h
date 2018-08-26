#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Game/GameInputManager.h"

namespace Lorwen {

	class Window
	{
	private:
		GLFWwindow * m_Window;
		unsigned int m_Width, m_Height;
		GameInputManager m_InputManager;

		const char* m_Title;

	public:
		Window();
		~Window();

		void Init(unsigned int width, unsigned int height, const char* title);

	private:
		static void InputKey_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);


	public:
		bool ShouldCloseWindow();

		void Clear(GLbitfield mask);

		void SwapBuffers();

		void PollEvents();

		void SetVSync(bool bSync);

		inline double GetTime() const { return glfwGetTime(); }

		inline GLFWwindow* GetWindowPtr() const { return m_Window; }
	};
}
