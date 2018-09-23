#pragma once

#include "Component.h"

#include <functional>
#include <array>

#include "InputHelpers.h"


class LInputComponent : public Component
{
private:
	std::array<SInputBind<EInputType::ACTION>, 15> m_BindedButtons;
	//std::array<std::pair<SAxisBinding, AxisFunction>, 15> m_BindedAxis;
	//std::array<std::pair<SVirtualAxisBinding, AxisFunction>, 15> m_BindedVirtualAxis;

	static std::hash<std::string> m_Hasher;

	/* Device type who this InputController is listening to*/
	EInputDevice ControllerDevice;

	virtual void OnDestruction();
	virtual void OnCreation();

	unsigned char ControllerID;

public:
	inline unsigned char GetControllerID() const { return ControllerID; }


	void AddActionInput(const std::string inputID, const EButtonAction action, std::function<void(void)> functionPtr);
	void AddAxisInput(const std::string inputName, std::function<void(float)> functionPtr);
public:
	
	template<class T>
	void BindAction(const std::string inputName, const EButtonAction action, T* objectInstance, void(T::*function)(void))
	{
		AddActionInput(inputName, action, std::bind(function, objectInstance));
	}
	
	template<class T>
	void BindAxis(const std::string inputName, T* objectInstance, void(T::*function)(float))
	{
		AddAxisInput(inputName, std::bind(function, objectInstance, std::placeholders::_1));
	}


	/**
	 *  FUNCTION CALLS
	 */

public:
	void CallActionInput(const int key, const EButtonAction action);

	inline std::array<SInputBind<EInputType::ACTION>, 15>* GetButtonInputs() { return &m_BindedButtons; }

};

