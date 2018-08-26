#include "InputComponent.h"

#include "GameInputManager.h"

namespace Lorwen {

	InputComponent::InputComponent()
	{
		bCanTick = false;
	}


	InputComponent::~InputComponent()
	{
	}

	bool InputComponent::ReceiveInput(SInputData data)
	{
		if (bHasFocus == false)
			return false;

		for (SInputListening& input : m_InputListeners)
		{
			if (input.Key == data.Key)
			{
				input.Function(data.Value);
				return true;
			}
			
		}

		return false;
	}

	template<class T>
	void InputComponent::BindInput(const char* actionName, unsigned int button, void(*function)(float), T*)
	{
		SInputListening newInput;
		newInput.Function = std::bind(function);
	}

}