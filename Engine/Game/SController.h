#pragma once

#include <array>

#include <iostream>

enum class EInputTypes
{
	Action = 0,
	Axis = 1,
	VirtualAxis = 2
};

enum EControllerTypes : unsigned char
{
	None = 0,
	XboxOne = 1,
	Playstation4 = 2
};

struct SButton
{
	const char* Name;
	bool State;

	SButton() { }
	SButton(const char* name, unsigned char state)
		: Name(name), State(state) { }
};

struct SAxis
{
	const char* Name;

	SAxis() { }

	SAxis(const char* name)
		: Name(name) { }
};

struct XboxControllerMap
{
	static std::array<SButton, 14> Buttons;
	static std::array<SAxis, 6> Axes;

	XboxControllerMap()
	{
		Buttons = 
		{
			SButton("XBOX_A", 0),
			SButton("XBOX_B", 0),
			SButton("XBOX_X", 0),
			SButton("XBOX_Y", 0),

			SButton("XBOX_LB", 0),
			SButton("XBOX_RB", 0),

			SButton("XBOX_Select", 0),
			SButton("XBOX_Start", 0),

			SButton("XBOX_LTClick", 0),
			SButton("XBOX_RTClick", 0),

			SButton("XBOX_Dpad_Up", 0),
			SButton("XBOX_Dpad_Right", 0),
			SButton("XBOX_Dpad_Down", 0),
			SButton("XBOX_Dpad_Left", 0),
		};

		Axes =
		{
			SAxis("XBOX_LeftAxisX"),
			SAxis("XBOX_LeftAxisY"),

			SAxis("XBOX_RightAxisX"),
			SAxis("XBOX_RightAxisY"),

			SAxis("XBOX_LeftTrigger"),
			SAxis("XBOX_RightTrigger")
		};
	}

};

struct SInputBinding
{
	SButton* Button;
	EInputTypes InputType;
};

struct SControllerInterface
{
	unsigned char ID;
	EControllerTypes Tag;

	class LInputComponent* InputComponent;

	std::array<SInputBinding*, 20> BindedActions;

	SControllerInterface()
		: ID(99), Tag(None) 
	{

	}

	void Init(const unsigned char iD, const EControllerTypes type)
	{
		BindedActions.fill(nullptr);

		ID = iD;
		Tag = type;

		std::cout << "Connected a " << type << " Controller with ID " << (int)(ID) << "!" << std::endl;
	}

	bool CheckAction(const char* inputName)
	{
// 		for (SInputBinding* binding : BindedActions)
// 		{
// 			if (strcmp(binding->Button->Name, inputName) == 0)
// 				return true;
// 		}

		return false;
	}

};

