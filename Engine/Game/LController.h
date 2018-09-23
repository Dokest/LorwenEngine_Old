#pragma once

#include "Object.h"

#include <array>

enum class EControllerDevice
{
	Keyboard,
	Gamepad
};

enum class EInputState : unsigned char
{
	Release = 0,
	Press = 1,
	Axis = 3,
	VirtualAxis = 4
};

struct SGamepadMapping
{
	static std::array<std::string, 15> Buttons;
	static std::array<std::string, 6> Axes;

	static SGamepadMapping* Singleton_SGamepadMapping;

	SGamepadMapping()
	{
		Singleton_SGamepadMapping = this;

		Buttons =
		{
			"Gamepad_Button_A",
			"Gamepad_Button_B",
			"Gamepad_Button_X",
			"Gamepad_Button_Y",

			"Gamepad_Button_Left_Bumper",
			"Gamepad_Button_Right_Bumper",

			"Gamepad_Button_Select",
			"Gamepad_Button_Start",
//			"Gamepad_Button_Guide",

			"Gamepad_Button_Left_Thumb",
			"Gamepad_Button_Right_Thumb",

			"Gamepad_Button_Dpad_Up",
			"Gamepad_Button_Dpad_Right",
			"Gamepad_Button_Dpad_Down",
			"Gamepad_Button_Dpad_Left"
		};

		Axes =
		{
			"Gamepad_Axis_Left_X",
			"Gamepad_Axis_Left_Y",
			"Gamepad_Axis_Right_X",
			"Gamepad_Axis_Right_Y",
			"Gamepad_Axis_Left_Trigger",
			"Gamepad_Axis_Right_Trigger"
		};
	}

	static std::pair<int, EInputState> GetKey(const std::string keyName)
	{
		for (unsigned int i = 0; i < Buttons.size(); i++)
		{
			if (Buttons[i] == keyName)
				return std::pair<int, EInputState>(i, EInputState::VirtualAxis);
		}

		for (unsigned int i = 0; i < Axes.size(); i++)
		{
			if (Axes[i] == keyName)
				return std::pair<int, EInputState>(i, EInputState::Axis);
		}
	}

};

struct SBindings 
{
	int BindingKey = -1;
	unsigned int hBindingName;
	float Value;
	EInputState State;
};

struct SAxisBinding
{
	unsigned int hBindingName = 0;
	int BindingKey = -1;
	float Sensitivity;
};

struct SButtonBinding
{
	int BindingKey = -1;
	unsigned int hBindingName = 0;
	EInputState State;
	EInputState LastFrameState;
};

struct SVirtualAxisBinding
{
	int BindingKey1 = -1;
	int BindingKey2 = -1;
	unsigned int hBindingName = 0;
	float Sensitivity;
};

class LController : public Object
{
public:
	int ID = -1;
	EControllerDevice Device;
	class LInputComponent* pInputComponent;

private:

	std::array<SAxisBinding, 15> m_AxisBindings;
	std::array<SVirtualAxisBinding, 15> m_VirtualAxisBindings;
	std::array<SButtonBinding, 15> m_ButtonBindings;

	std::array<SBindings, 50> m_Bindings;
public:
	void Init(const EControllerDevice device);

	void DetectsInputs();

	void BindAxis(unsigned int hBindingName, int key, float value);

	/**
	 *	@param hBindingName: hashed name of the binding.
	 *	@param key1, key2: key numbers to set the both axis to. A -1 is consider to skip that key.
	 *	@param value: Axis Sensibility.
	 */
	void BindVirtualAxis(const unsigned int hBindingName, const int key1, const int key2, const float value);

private:
	void DetectKeyboardInputs();
	void DetectGamepadInputs();

	void ClearAxis(const unsigned int hBindingName, const EInputState inputType);
};

