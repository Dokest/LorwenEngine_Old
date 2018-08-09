#include <stdlib.h>

#include "GL/glew.h"

#include "Window.h"
#include "BasicTimer.h"

#include "Levels/BasicLevel.h"

#define LORWEN_SHOW_FPS 1

using namespace Lorwen;
//using namespace Graphics;

int main()
{
	Window gameWindow;

	gameWindow.Init(800, 600, "Lorwen Engine Prototype - Breakout");
	BasicTimer timer;

	BasicLevel level;
	level.Load();
	level.Init();

	int frames = 0;
	double time = 0.0f;
	double currentFrame = 0.0f;
	double lastFrame = 0.0f;
	gameWindow.SetVSync(false);

	while (!gameWindow.ShouldCloseWindow())
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		timer.FrameStart();
		gameWindow.Clear(GL_COLOR_BUFFER_BIT);


		gameWindow.PollEvents();

		level.Render();


#if LORWEN_SHOW_FPS
		frames = timer.GetFrames();
		if(frames != -5)
			printf("%d FPS\n", frames);
#endif

		timer.FrameEnd();
		gameWindow.SwapBuffers();
	}

	
}