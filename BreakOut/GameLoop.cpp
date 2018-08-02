#include <stdlib.h>

#include "GL/glew.h"

#include "Window.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include "SpriteRenderer.h"

using namespace Lorwen;
using namespace Graphics;

int main()
{
	Lorwen::Window gameWindow;

	gameWindow.Init(800, 600, "Lorwen Engine Prototype");

	float positions[] = {
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 0.0f,  1.0f, 0.0f

// 		-0.5f, -0.5f,
// 		 0.5f, -0.5f,
// 		 0.5f,  0.5f,
// 		-0.5f,  0.5f
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

 	VertexBuffer vb(positions, 3 * 3 * sizeof(float));
 	IndexBuffer ib(indices, 6);
// 
	SpriteRenderer spriteRenderer;
// 
 	spriteRenderer.Submit(&SpriteRenderable(&vb, &ib));

	/* TEST */
	unsigned int bufferID;
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, 3 * 3 * sizeof(float), positions, GL_STATIC_DRAW);

	while (!gameWindow.ShouldCloseWindow())
	{
		gameWindow.Clear(GL_COLOR_BUFFER_BIT);

		gameWindow.PollEvents();

		glDrawArrays(GL_TRIANGLES, 0, 3);


		spriteRenderer.Render();
		gameWindow.ShowOpenGLErrors();

		gameWindow.SwapBuffers();
	}



}