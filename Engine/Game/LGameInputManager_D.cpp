// #include "LGameInputManager_D.h"
// 
// #include "Utils/FileReader.h"
// 
// #include <string>
// #include <iostream>
// #include <stdlib.h>
// 
// 
// std::array<class LController, 20> LGameInputManager_D::m_ConnectedControllers;
// 
// std::array<class LController*, 4> LGameInputManager_D::m_PlayingControllers;
// 
// std::map<const std::string, std::vector<SKeyBinding>> LGameInputManager_D::m_FileBindings;
// 
// void LGameInputManager_D::Init()
// {
// 	/* Read Controls on the DEFAULT file */
// 	ReadControlsFile();
// 
// 	/* Set Keyboard as First Controller*/
// 	if (bSetKeyboardAsFirstContrller)
// 	{
// 		AddControllerInterface(0, EControllerDevice::Keyboard);
// 	}
// }
// 
// void LGameInputManager_D::ReadControlsFile()
// {
// 	/* Create GamePad controls */
// 	new SGamepadMapping; 
// 
// 	std::ifstream ControlsFile = FileReader::GetFileStream("Controls.txt");
// 
// 	std::string line;
// 	unsigned char currentRead = 0; // 0 == AXIS / 1 == ACTIONS
// 
// 	while (getline(ControlsFile, line))
// 	{
// 		if (line == "[Axis]")
// 		{
// 			currentRead = 0;
// 			continue;
// 		}
// 		else if (line == "[Actions]")
// 		{
// 			currentRead = 1;
// 			continue;
// 		}
// 		else if (line == "")
// 		{
// 			continue;
// 		}
// 		else if (currentRead == 0)
// 		{
// 			ReadAxisControl(line);
// 		}
// 		else
// 		{
// 			ReadActionControl(line);
// 		}
// 
// 	}
// }
// 
// void LGameInputManager_D::ReadAxisControl(const std::string& line)
// {
// 	SKeyBinding binding;
// 
// 	std::string inputName = (line.substr(1, line.find('"', 2) - 1)).c_str();
// 	//const char* inputName = testString.c_str();
// 
// 	std::string keys = line.substr(line.find('|', 3) + 2);
// 
// 	for (unsigned int i = 0; i < keys.size() - 1; i = (keys.find(')', i) + 2))
// 	{
// 		std::string keyName = keys.substr(i, keys.find('(', i) - i).c_str();
// 
// 		if (keyName.size() > 5)
// 		{
// 			binding.Device = EControllerDevice::Gamepad;
// 			std::pair<int, EInputState> type = SGamepadMapping::GetKey(keyName.c_str());
// 
// 			binding.Key = type.first;
// 			binding.InputType = type.second;
// 		}
// 		else
// 		{
// 			binding.Device = EControllerDevice::Keyboard;
// 			binding.Key = (int)*(keyName.c_str());
// 
// 		}
// 		//keys.substr(i, keys.find('(', i) - i);
// 
// 		//std::string test = keys.substr(keys.find('(', i) + 1, keys.find(')', i) - 2);
// 
// 		binding.Value = std::stof(keys.substr(keys.find('(', i) + 1, keys.find(')', i) - 2), nullptr);
// 		m_FileBindings[inputName].push_back(binding);
// 	}
// 	
// }
// 
// void LGameInputManager_D::ReadActionControl(const std::string& line)
// {
// // 	SInputMolecule<ACTION> input;
// // 	input.Action.hName = m_Hasher(line.substr(1, line.find('"', 3) - 1));
// // 	std::string keys = line.substr(line.find('|', 3) + 2);
// // 
// // 	for (unsigned int i = 0; i < keys.size(); i += 2)
// // 	{
// // 		input.Action.Keys.push_back(keys.substr(i, keys.find(' ', i) - i));
// // 	}
// // 
// // 	m_PossibleActions.push_back(input);
// // 
// // 	std::cout << "ACTION: {" << line.substr(1, line.find('"', 3) - 1) << "} : " << line.substr(line.find('|', 3) + 2) << std::endl;
// }
// 
// unsigned int LGameInputManager_D::BindAxis(const char* inputName, int controllerID, class LInputComponent* inputComponent)
// {
// 	for (LController* controller : m_PlayingControllers)
// 	{
// 		if (controller != nullptr && controller->ID == controllerID)
// 		{
// 			std::hash<const char*> hasher;
// 			std::pair<SKeyBinding*, SKeyBinding*> bindingVariables = GetInputKey(inputName, controller->Device, 2);
// 
// 			if (bindingVariables.first->Key == -1)
// 			{
// 				printf("There was a problem trying to access key with input name: %s", inputName);
// 				return 0;
// 			}
// 
// 			switch (bindingVariables.first->InputType)
// 			{
// 			case EInputState::Axis:
// 				controller->BindAxis(hasher(inputName), bindingVariables.first->Key, bindingVariables.first->Value);
// 				break;
// 			
// 			case EInputState::VirtualAxis:
// 				controller->BindVirtualAxis(hasher(inputName), bindingVariables.first->Key, bindingVariables.second->Key, bindingVariables.first->Value);
// 			default:
//				break;
// 			}
// 
// 			return hasher(inputName);
// 		}
// 	}
// }
// 
// void LGameInputManager_D::AddControllerInterface(const int controllerID, const EControllerDevice device)
// {
// 	for (LController& controller : m_ConnectedControllers)
// 	{
// 		if (controller.ID == -1)
// 		{
// 			controller.ID = controllerID;
// 			controller.Init(device);
// 
// 			break;
// 		}
// 	}
// 
// 	return;
// 
// // 	for (LController& connectedController : m_ConnectedControllers)
// // 		if (connectedController.ID == -1)
// // 		{
// // 			for (LController* playingController : m_PlayingControllers)
// // 			{
// // 				if (playingController == nullptr)
// // 				{
// // 					playingController = &connectedController;
// // 					playingController->Init(device);
// // 					return;
// // 				}
// // 			}
// // 		}
// }
// 
// char LGameInputManager_D::AddInputComponent(class LInputComponent* inputComponent)
// {
// 	for (LController& controller : m_ConnectedControllers)
// 	{
// 		if (controller.ID != -1 && controller.pInputComponent == nullptr)
// 		{
// 			controller.pInputComponent = inputComponent;
// 
// 			for (unsigned int i = 0; i < m_PlayingControllers.size(); i++)
// 			{
// 				if (m_PlayingControllers[i] == nullptr)
// 				{
// 					m_PlayingControllers[i] = &controller;
// 					break;
// 				}
// 			}
// 
// 			return controller.ID;
// 		}
// 	}
// }
// 
// void LGameInputManager_D::CheckInputs()
// {
// 	for (LController* controller : m_PlayingControllers)
// 	{
// 		if(controller != nullptr)
// 			controller->DetectsInputs();
// 	}
// }
