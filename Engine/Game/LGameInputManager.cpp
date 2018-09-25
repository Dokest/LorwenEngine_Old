#include "LGameInputManager.h"

#include <GLFW/glfw3.h>

#include <sstream>
#include <string>
#include <iostream>

#include "Utils/FileReader.h"
#include "Inputs/KeyboardEnum.h"

#include "LInputComponent.h"

std::array<SInputListeners, 4> LGameInputManager::m_InputListeners;

std::vector<SInputBind<EInputType::ACTION>> LGameInputManager::m_PossibleActions;

std::vector<SInputBind<EInputType::AXIS>> LGameInputManager::m_PossibleAxis;

struct GLFWwindow* LGameInputManager::m_pWindow;

std::hash<std::string> LGameInputManager::m_Hasher;

void LGameInputManager::Init(struct GLFWwindow* window)
{
	m_pWindow = window;

	// Create Keyboard mapping
	SKeyboardMapping* keyboardMapping = new SKeyboardMapping();

	ReadControlsFile();
}

void LGameInputManager::CheckInputs()
{
	// Go through all the listeners (players)
	for (SInputListeners& inputListener : m_InputListeners)
	{
		// If a player is not binded with a Input Component, it's not valid.
		if(inputListener.InputComponent == nullptr)
			continue;

		// Go through all the buttons binded with the input component
		for (SInputBind<EInputType::ACTION>*& button : inputListener.Actions)
		{
			// If the key has the same state as last frame, it doesn't need to call the action, as 'HOLD' action type is not supported.
			if ((EButtonAction)glfwGetKey(m_pWindow, button->Key) == button->LastFrameState)
				continue;

			// Set this frame as last frame state
			button->LastFrameState = (EButtonAction)glfwGetKey(m_pWindow, button->Key);

			// Test the trigger state with the actual state
			if (button->Key != -1 && button->ActionTrigger == button->LastFrameState)
			{
				button->Function();
			}

		}

		for (SInputBind<EInputType::AXIS>*& axis : inputListener.Axes)
		{
			float finalResult = glfwGetKey(m_pWindow, axis->PositiveKey);

			if (glfwGetKey(m_pWindow, axis->PositiveKey) == 1)
				finalResult = 1;
			else if (glfwGetKey(m_pWindow, axis->NegativeKey) == 1)
				finalResult = -1;
			else
				finalResult = 0;

			axis->Function(finalResult * axis->Sensitivity);
		}

	}


}

int LGameInputManager::GetKeyByInputID(const unsigned int inputID, const EInputDevice device)
{
	return m_PossibleActions.at(inputID).Key;
}

std::map<size_t, int> LGameInputManager::m_KeyBindings;

unsigned char LGameInputManager::AddInputController(class LInputComponent* inputController)
{
	for (unsigned int i = 0; i < m_InputListeners.size(); i++)
	{
		if (m_InputListeners[i].InputComponent == nullptr)
		{
			m_InputListeners[i].InputComponent = inputController;
			return i;
		}
	}
}

void LGameInputManager::BindAction(class LInputComponent* component, std::function<void(void)> function, const std::string inputName, const EButtonAction actionTrigger)
{
	size_t inputID = m_Hasher(inputName);

	for (SInputBind<EInputType::ACTION>& input : m_PossibleActions)
	{
		if (input.InputID == inputID)
		{
			input.ActionTrigger = actionTrigger;
			input.Function = function;

			m_InputListeners[component->GetControllerID()].Actions.push_back(&input);

			return;
		}
	}

}

void LGameInputManager::BindAxis(class LInputComponent* component, std::function<void(float)> function, const std::string inputName)
{
	size_t inputID = m_Hasher(inputName);

	for (SInputBind<EInputType::AXIS>& input : m_PossibleAxis)
	{
		if (input.InputID == inputID)
		{
			input.Function = function;


			m_InputListeners[component->GetControllerID()].Axes.push_back(&input);

			return;
		}
	}
}

void LGameInputManager::ReadControlsFile()
{
	std::ifstream ControlsFile = FileReader::GetFileStream("GameControls.txt");
 
 	std::string line;
 
	EInputDevice device = EInputDevice::ANY;
	EInputType type = EInputType::ACTION;

	unsigned int inputCounter = 0;

	while (getline(ControlsFile, line))
	{
		// Dont read empty or commmented lines
		if (line.length() == 0 || line[0] == '#')
			continue;

		// If line starts with '<', it means is a device changing line.
		if (line[0] == '<')
		{
			if (line == "<Keyboard>")
				device = EInputDevice::KEYBOARD;
			else
				device = EInputDevice::GAMEPAD;

			continue;
		}
		else if (line[0] == '[')
		{
			if (line == "[ACTION]")
				type = EInputType::ACTION;
			else // If its not an action, it has to be an axis. On Keyboard axis are called Virtual Axis
				type = (device == EInputDevice::KEYBOARD) ? EInputType::VIRTUAL_AXIS : EInputType::AXIS;

			continue;
		}

		std::string inputName = line.substr(0, line.find('=') - 1);
		size_t inputID = m_Hasher(inputName);

		if (type == EInputType::ACTION)
		{
			SInputBind<EInputType::ACTION> action;
			action.Key = (int)*line.substr(line.find('=') + 2).c_str();
			action.InputID = inputID;

			action.Key = GetKeyByName(line.substr(line.find('=') + 2));
			
			m_PossibleActions.push_back(action);
		}
		else
		{
			SInputBind<EInputType::AXIS> axis;
			axis.PositiveKey = (int)*line.substr(line.find('=') + 2, line.find('-')).c_str();
			axis.NegativeKey = (int)*line.substr(line.find('-') + 2).c_str();

			axis.InputID = inputID;

			m_PossibleAxis.push_back(axis);
		}


		inputCounter++;
	}


}

