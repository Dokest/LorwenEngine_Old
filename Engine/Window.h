#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Lorwen {

	class Window
	{
	private:
		GLFWwindow * m_Window;
		unsigned int m_Width, m_Height;

		const char* m_Title;

	public:
		Window();
		~Window();

		void Init(unsigned int width, unsigned int height, const char* title);

	public:
		bool ShouldCloseWindow();

		void Clear(GLbitfield mask);

		void SwapBuffers();

		void PollEvents();

		void ShowOpenGLErrors();
	};
}
