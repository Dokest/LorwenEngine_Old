#pragma once

#include "GLFW/glfw3.h"

#include <string>

namespace Lorwen {

	class BasicTimer
	{
	private:
		int Frames = 0;
		int UnusedFrame = 0;
		double CurrentFrame = 0.0;
		double LastFrame = 0.0;
		float Time = 0.0f;

	public:
		inline void FrameStart() 
		{
			CurrentFrame = glfwGetTime();
			Time += CurrentFrame - LastFrame;
		}

		inline void FrameEnd()
		{
			Frames++;
			LastFrame = CurrentFrame;
		}

		inline int GetFrames() 
		{
			if (Time >= 1.0f)
			{
				Time = 0.0f;
				UnusedFrame = Frames;
				Frames = 0;
				return UnusedFrame;
			}

			return -5;
		}

		

	};


}