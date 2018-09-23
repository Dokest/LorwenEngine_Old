#include "LInputComponent.h"

#include "LGameInputManager.h"

std::hash<std::string> LInputComponent::m_Hasher;

void LInputComponent::OnDestruction()
{

}

void LInputComponent::OnCreation()
{
	ControllerID = LGameInputManager::AddInputController(this);
}

void LInputComponent::AddActionInput(const std::string inputName, const EButtonAction action, std::function<void(void)> functionPtr)
{
// 	unsigned int inputID = m_Hasher(inputName);
// 
// 	for (SInputBind<EInputType::ACTION>& input : m_BindedButtons)
// 	{
// 		if (input.Key != -1)
// 			continue;
// 
// 		input.Key = LGameInputManager::GetKeyByInputID(inputID, ControllerDevice);
// 		input.ActionTrigger = action;
// 		input.Function = functionPtr;
// 
// 		return;
// 	}


	LGameInputManager::BindAction(this, functionPtr, inputName, action);
}

void LInputComponent::AddAxisInput(const std::string inputName, std::function<void(float)> functionPtr)
{
	LGameInputManager::BindAxis(this, functionPtr, inputName);
}

void LInputComponent::CallActionInput(const int key, const EButtonAction action)
{

}
