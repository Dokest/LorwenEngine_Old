// #pragma once
// 
// #include "Game/Object.h"
// 
// #include "LController.h"
// 
// #include <array>
// #include <map>
// #include <vector>
// 
// 
// struct SKeyBinding
// {
// 	int Key;
// 	EControllerDevice Device;
// 	float Value;
// 	EInputState InputType;
// };
// 
// class LGameInputManager_D : public Object
// {
// private:
// 	static std::array<class LController, 20> m_ConnectedControllers;
// 	static std::array<class LController*, 4> m_PlayingControllers;
// 
// 	static std::map<const std::string, std::vector<SKeyBinding>> m_FileBindings;
// 
// 	/**
// 	 *	Configuration
// 	 */
// 
// 	bool bSetKeyboardAsFirstContrller = false;
// 
// private:
// 	static inline std::pair<SKeyBinding*, SKeyBinding*> GetInputKey(const std::string inputName, const EControllerDevice device, unsigned int bindingNumber)
// 	{
// 		char bDone = 0;
// 		std::pair<SKeyBinding*, SKeyBinding*> keys;
// 
// 		for (SKeyBinding& binding : m_FileBindings[inputName])
// 		{
// 			if (binding.Device == device)
// 			{
// 				if (binding.InputType != EInputState::VirtualAxis)
// 				{
// 					keys.first = &binding;
// 					return keys;
// 				}
// 				else // InputType == Virtual Axis
// 				{
// 					if (bDone == 0)
// 					{
// 						keys.first = &binding;
// 						bDone = 1;
// 					}
// 					else 
// 					{
// 						keys.second = &binding;
// 						return keys;
// 					}
// 
// 				}
// 			}
// 		}
// 
// 
// 	}
// 
// 	void ReadControlsFile();
// 
// 	void ReadAxisControl(const std::string& line);
// 	void ReadActionControl(const std::string& line);
// 
// public:
// 	void Init();
// 
// 	static unsigned int BindAxis(const char* inputName, int controllerID, class LInputComponent* inputComponent);
// 
// 	static void AddControllerInterface(const int controllerID, const EControllerDevice device);
// 
// 	static char AddInputComponent(class LInputComponent* inputComponent);
// 
// 	void CheckInputs();
// 
// };

