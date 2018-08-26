#include "GameInputManager.h"

#include "InputComponent.h"

#include <string>

namespace Lorwen {

	GameInputManager* GameInputManager::Singleton_GameInputManager;


	void GameInputManager::sendInput(SInputData input)
	{
		for (InputComponent& inputComponent : m_InputComponents)
		{
			if (inputComponent.ReceiveInput(input) == true)
				return;

		}
	}

	GameInputManager::GameInputManager()
	{
	}


	void GameInputManager::InputKey(unsigned int key, EInputCategory category)
	{
		const char* keyCat[3] = { "Release", "Press", "Hold" };

		//printf("Key %d was %s\n", key, keyCat[(unsigned int)category]);
		SInputData data;
		data.InputCategory = category;
		data.Key = key;
		//data.Value = value;

		sendInput(data);
	}

	InputComponent* GameInputManager::RegisterInputComponent(GameObject* owner)
	{
		Singleton_GameInputManager->m_InputComponents.push_back(InputComponent());
		InputComponent* inputComp = &Singleton_GameInputManager->m_InputComponents[Singleton_GameInputManager->m_InputComponents.size() - 1];
		inputComp->Owner = owner;

		return inputComp;
	}
	
}