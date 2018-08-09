#pragma once

#include <GL/glew.h>
#include <string>


namespace Lorwen {

#define CheckOpenGLError() _CheckGLError(__FILE__, __LINE__);

void ShowOpenGLErrors()
{
	GLenum error;

	while ((error = glGetError()) != GL_NO_ERROR)
	{
		switch (error)
		{
		case GL_INVALID_ENUM:
			printf("OpenGL error -- INVALID ENUM --\n");
			break;
		case GL_INVALID_VALUE:
			printf("OpenGL error -- INVALID VALUE --\n");
			break;
		case GL_INVALID_OPERATION:
			printf("OpenGL error -- INVALID OPERATION --\n");
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			printf("OpenGL error -- INVALID FRAMEBUFFER_OPERATION --\n");
			break;
		case GL_OUT_OF_MEMORY:
			printf("OpenGL error -- OPENGL OUT OF MEMORY --\n");
			break;
		default:
			printf("OpenGL error -- UNKOWN ERROR --\n");
			break;
		}

		printf("------------------------------------------------\n");
	}

}

void _CheckGLError(const char* file, int line)
{
	GLenum err(glGetError());

	while (err != GL_NO_ERROR)
	{
		std::string error;
		switch (err)
		{
		case GL_INVALID_OPERATION:  error = "INVALID_OPERATION";      break;
		case GL_INVALID_ENUM:       error = "INVALID_ENUM";           break;
		case GL_INVALID_VALUE:      error = "INVALID_VALUE";          break;
		case GL_OUT_OF_MEMORY:      error = "OUT_OF_MEMORY";          break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:  error = "INVALID_FRAMEBUFFER_OPERATION";  break;
		}
		printf("GL_%s - %s : %s", error.c_str(), file, line);
		err = glGetError();
	}

	return;
}

}
