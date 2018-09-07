#include "GameInputManager.h"

#include "GameObject.h"

#include "Utils/FileReader.h"

#include <string>
#include <iostream>
#include <stdlib.h>

#include "InputComponent.h"

GameInputManager* GameInputManager::Singleton_GameInputManager;

GameInputManager::GameInputManager()
{
	Singleton_GameInputManager = this;
}

void GameInputManager::Init()
{
	ReadControlsFile();
	return;


	std::ifstream ControlsFile = FileReader::GetFileStream("Controls.txt");

	std::string line;
	std::string inputName;
	std::string inputKey;

	while (getline(ControlsFile, line))
	{
		unsigned short uInputName_FinalLetter = line.find("\"", 3);
		unsigned short uInputKey = line.find('-', 3);
		unsigned char uInputState = line.find('|', 3);
		
		inputName = line.substr(2, uInputName_FinalLetter - 2);

		unsigned int hHashedName = m_Hasher(inputName);

		inputKey = line.substr(uInputKey + 2, 1);

		std::cout << inputName << "(" << hHashedName << ")" << ": Binded with -> " << inputKey[0] << " with state " << line.substr(uInputState + 2, 1)[0] << std::endl;

		SInput newInput;
		newInput.hInputName = m_Hasher(inputName);
		newInput.KeyCode = inputKey[0];
		newInput.InputState = (line.substr(uInputState + 2, 1)[0] == 'P') ? EInputState::Press : EInputState::Release;

		m_PossibleInputs.push_back(newInput);
	}

}

void GameInputManager::ReadControlsFile()
{
	std::ifstream ControlsFile = FileReader::GetFileStream("Controls.txt");

	std::string line;
	EInputType currentRead = AXIS;

	while (getline(ControlsFile, line))
	{
		if (line == "[Axis]")
		{
			currentRead = AXIS;
			continue;
		}
		else if (line == "[Actions]")
		{
			currentRead = ACTION;
			continue;
		}
		else if(line == "")
		{
			continue;
		}
		
		switch (currentRead)
		{
		case AXIS:
			ReadAxisControl(line);
			break;
		case ACTION:
			ReadActionControl(line);
			break;
		}


	}
}

void GameInputManager::ReadAxisControl(const std::string& line)
{
	SInputMolecule<AXIS> input;
	input.Axis.hName = m_Hasher(line.substr(1, line.find('"', 2) - 1));
	
	std::string keys = line.substr(line.find('|', 3) + 2);

	for (unsigned int i = 0; i < keys.size() - 1;)
	{
		std::string name = keys.substr(i, keys.find('(', i) - i);
		std::string keyName = keys.substr(keys.find('(', i) + 1, keys.find(')', i) - 2 - i);

		std::cout << name << " -> " << keyName << std::endl;

		input.Axis.Keys.push_back(std::pair<std::string, float>(name, (float)atof(keyName.c_str())));

		i = (keys.find(')', i) + 2);

		//std::cout << "AXIS: {" << name << "} Key " << keys.substr(keys.find('(', i) + 1, keys.find(')', i) - 1).c_str()
		//	<< " - " << atof(keys.substr(keys.find('(', i) + 1, keys.find(')', i) - 1).c_str()) << std::endl;
	}

	m_PossibleAxis.push_back(input);
}

void GameInputManager::ReadActionControl(const std::string& line)
{
	SInputMolecule<ACTION> input;
	input.Action.hName = m_Hasher(line.substr(1, line.find('"', 3) - 1));
	std::string keys = line.substr(line.find('|', 3) + 2);

	for (unsigned int i = 0; i < keys.size(); i += 2)
	{
		input.Action.Keys.push_back(keys.substr(i, keys.find(' ', i) - i));
	}

	m_PossibleActions.push_back(input);

	std::cout << "ACTION: {" << line.substr(1, line.find('"', 3) - 1) << "} : " << line.substr(line.find('|', 3) + 2) << std::endl;
}

unsigned int GameInputManager::BindAxis(class InputComponent& newInput, const char* inputName)
{
	unsigned int hInputName = m_Hasher(inputName);

	for (SInputMolecule<AXIS>& axis : m_PossibleAxis)
	{
		if (axis.Axis.hName == hInputName)
		{
			axis.Listeners.push_back(&newInput);
		}
	}

	return hInputName;
}

unsigned int GameInputManager::BindAction(class InputComponent& inputComponent, const char* inputName, const EInputState state)
{
	unsigned int hName = m_Hasher(inputName);

	for (SInputMolecule<ACTION>& action : m_PossibleActions)
	{
		if (action.Action.hName == hName)
		{
			action.Listeners.push_back(SInputComponentType(&inputComponent, state));
			return hName;
		}
	}

}

void GameInputManager::DetectAction(const std::string key, const EInputState state)
{
	for (SInputMolecule<ACTION> input : m_PossibleActions)
	{
		for (std::string& letter : input.Action.Keys)
		{
			if (letter == key)
			{
				for (SInputComponentType& component : input.Listeners)
				{
					if (component.State != state)
						continue;
					component.Component->CallActionInput(input.Action.hName, state);

					return;
				}
			}
		}

	}

	if (state == Release)
		return;
	
	for (SInputMolecule<AXIS> axis : m_PossibleAxis)
	{
		for (std::pair<std::string, float>& letter : axis.Axis.Keys)
		{
			if (letter.first == key)
			{
				for (InputComponent*& component : axis.Listeners)
				{
					component->CallAxisInput(axis.Axis.hName, letter.second);

					return;
				}
			}
		}

	}
}

void GameInputManager::DetectAxis(const char* axisName, float value)
{
	for (SInputMolecule<AXIS> axis : m_PossibleAxis)
	{
		for (std::pair<std::string, float>& letter : axis.Axis.Keys)
		{
			if (letter.first == axisName)
			{
				for (InputComponent*& component : axis.Listeners)
				{
					component->CallAxisInput(axis.Axis.hName, value * letter.second);

					return;
				}
			}
		}

	}
}

