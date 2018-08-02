#include "Window.h"

#include <string>

namespace Lorwen {

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

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

		glfwMakeContextCurrent(m_Window);

		if (GLenum err = glewInit() != GLEW_OK)
		{
			printf("GLEW initialization failed!\n");
			fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
			return;
		}

		printf("%s\n", glGetString(GL_VERSION));
	}

	bool Window::ShouldCloseWindow()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::Clear(GLbitfield mask)
	{
		glClear(mask);
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}


	void Window::ShowOpenGLErrors()
	{
		GLenum error;
		while((error = glGetError()) != GL_NO_ERROR)
			printf(" -- OpenGL Error: %d\n-----------------------\n", error);
	}

}