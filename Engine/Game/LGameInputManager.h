#pragma once

#include "Game/Object.h"

#include "LController.h"

#include <array>
#include <map>
#include <vector>


struct SKeyBinding
{
	int Key;
	EControllerDevice Device;
	float Value;
	EInputState InputType;
};

class LGameInputManager : public Object
{
private:
	static std::array<class LController, 20> m_ConnectedControllers;
	static std::array<class LController*, 4> m_PlayingControllers;

	static std::map<const std::string, std::vector<SKeyBinding>> m_FileBindings;

	/**
	 *	Configuration
	 */

	bool bSetKeyboardAsFirstContrller = false;

private:
	static inline std::vector<SKeyBinding*> GetInputKey(const std::string inputName, const EControllerDevice device, unsigned int bindingNumber)
	{
		bool bDone = false;

		std::vector<SKeyBinding*> bindings;

		for (SKeyBinding& binding : m_FileBindings[inputName])
		{
			if (binding.Device == device)
			{
				bindings.push_back(&binding);

				bDone = true;
// 				if (bindings.size() == bindingNumber)
// 					return bindings;
			}
		}

		if (bDone)
			return bindings;

		SKeyBinding key;
		key.Key = -1;
		bindings.push_back(&key);

		return bindings;
	}

	void ReadControlsFile();

	void ReadAxisControl(const std::string& line);
	void ReadActionControl(const std::string& line);

public:
	void Init();

	static unsigned int BindAxis(const char* inputName, int controllerID, class LInputComponent* inputComponent);

	static void AddControllerInterface(const int controllerID, const EControllerDevice device);

	static char AddInputComponent(class LInputComponent* inputComponent);

	void CheckInputs();

};

