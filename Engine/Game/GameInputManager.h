#pragma once

#include <vector>

#include "InputParameters.h"
#include "InputComponent.h"

namespace Lorwen {

	class GameInputManager
	{
	private:
		std::vector<InputComponent> m_InputComponents;

		static GameInputManager* Singleton_GameInputManager;

	private:
		void sendInput(SInputData input);

	public:
		GameInputManager();
		
	public:
		static InputComponent* RegisterInputComponent(GameObject* owner);

		void InputKey(unsigned int key, EInputCategory category);

	};
}
