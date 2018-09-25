#pragma once

#include "Object.h"

#include <array>
#include <vector>
#include <map>

#include "Inputs/InputHelpers.h"

#define NUMBER_OF_BUTTON_BINDINGS 15

struct SFileControlAction
{
	int Key;

	unsigned int InputID;

	EInputDevice Device;
};

struct SInputListeners 
{
	class LInputComponent* InputComponent;

	std::vector<SInputBind<EInputType::ACTION>*> Actions;
	std::vector<SInputBind<EInputType::AXIS>*> Axes;
};

class LGameInputManager
{
private:
	static std::array<SInputListeners, 4> m_InputListeners;

	static std::vector<SInputBind<EInputType::ACTION>> m_PossibleActions;
	static std::vector<SInputBind<EInputType::AXIS>> m_PossibleAxis;

	static struct GLFWwindow* m_pWindow;
	static std::hash<std::string> m_Hasher;

public:
	/**
	 *	This function needs to be called after generating the GLFW Window context
	 *
	 *	@param window
	 */
	void Init(struct GLFWwindow* window);

	void CheckInputs();

	/**
	 *  Input Component Binding
	 */
public:
	static int GetKeyByInputID(const unsigned int inputID, const EInputDevice device);
	static std::map<size_t, int> m_KeyBindings;

	static unsigned char AddInputController(class LInputComponent* inputController);

	/* Binds an action with a function */
	static void BindAction(class LInputComponent* component, std::function<void(void)> function, const std::string inputName, const EButtonAction actionTrigger);

	/* Binds an axis with a function */
	static void BindAxis(class LInputComponent* component, std::function<void(float)> function, const std::string inputName);

private:
	void ReadControlsFile();
};
