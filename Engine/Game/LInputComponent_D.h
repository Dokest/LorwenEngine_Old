#pragma once

#include "Component.h"

#include "KEY_Alphabet.h"

#include <vector>
#include <functional>

#include "LGameInputManager.h"


template<typename>
struct SInputFunction;

template<>
struct SInputFunction<float>
{
	std::function<void(float)> Function;

	SInputFunction() { }
};

template<>
struct SInputFunction<void>
{
	std::function<void(void)> Function;

	SInputFunction() { }
};

struct SAxisInput
{
	unsigned int hInputName;
	SInputFunction<float> Function;

	SAxisInput() { }

};

class LInputComponent : public Component
{
private:
	bool bHasFocus = false;
	int m_ControllerID = -1;

	std::map<unsigned int, SInputFunction<float>> m_BindedFunctions;

	std::map<std::pair<unsigned int, EInputState>, SInputFunction<void>> m_BindedActions;
	std::map<unsigned int, SInputFunction<float>> m_BindedAxis;

public:

	void CallActionInput(unsigned int functionName, EInputState state)
	{
		m_BindedActions[std::pair<unsigned int, EInputState>(functionName, state)].Function();
	}

	void CallAxisInput(unsigned int hFunctionName, float value)
	{
		m_BindedAxis[hFunctionName].Function(value);
	}

	template<typename ClassOwner>
	void BindAction(const char* actionName, EInputState state, ClassOwner* classInstance, void(ClassOwner::*function)(void))
	{
// 		unsigned int hHashedName = GameInputManager::Singleton_GameInputManager->BindAction(*this, actionName, state);
// 
// 		SInputFunction<void> newInput;
// 		newInput.Function = std::bind(function, classInstance);
// 		m_BindedActions[std::pair<unsigned int, EInputState>(hHashedName, state)] = newInput;
	}

	template<typename ClassOwner>
	void BindAxis(const char* actionName, ClassOwner* classInstance, void(ClassOwner::*function)(float))
	{
		unsigned int hHashedName = LGameInputManager::BindAxis(actionName, m_ControllerID, this);

		SInputFunction<float> newInput;
		newInput.Function = std::bind(function, classInstance, std::placeholders::_1);
		m_BindedAxis[hHashedName] = newInput;
	}

	//template<typename ClassOwner>
	//void BindAction(const )

	inline unsigned char GetControllerID() { return m_ControllerID; }
	inline void SetControllerID(unsigned char controllerID) { m_ControllerID = controllerID; }

private:
	//virtual void OnCreation();
};


