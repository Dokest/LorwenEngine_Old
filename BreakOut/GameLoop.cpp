#include <stdlib.h>

#include "GL/glew.h"

#include "Graphics/Window.h"
#include "Utils/BasicTimer.h"

#include "Levels/BasicLevel.h"
#include "Game/GameObjectManager.h"
#include "Game/GameInputManager.h"

#define LORWEN_SHOW_FPS 0

using namespace Lorwen;
//using namespace Graphics;

int main()
{
	GameObjectManager objectManager = GameObjectManager();
	GameInputManager inputManager = GameInputManager();
	inputManager.Init();

	Window gameWindow;
	gameWindow.Init(800, 600, "Lorwen Engine Prototype - Breakout", &inputManager);
	BasicTimer timer;

	/* Start Managers */

	/* Start Level */
	BasicLevel level;
	level.PrepareLevel();
	level.Load();
	level.Init();


	int frames = 0;
	double time = 0.0f;
	double currentFrame = 0.0f;
	double lastFrame = 0.0f;
	gameWindow.SetVSync(true);

	while (!gameWindow.ShouldCloseWindow())
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		timer.FrameStart();
		gameWindow.Clear(GL_COLOR_BUFFER_BIT);

		gameWindow.PollEvents();
		gameWindow.CheckControllerState();

		level.Render();


#if LORWEN_SHOW_FPS
		frames = timer.GetFrames();
		if (frames != -5)
			printf("%d FPS\n", frames);
#endif

		timer.FrameEnd();
		gameWindow.SwapBuffers();
	}

	
}