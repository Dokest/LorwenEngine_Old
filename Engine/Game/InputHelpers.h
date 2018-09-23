#pragma once

#include <functional>

typedef std::function<void(void)> ButtonFunction;
typedef std::function<void(float)> AxisFunction;

enum class EButtonAction : unsigned char
{
	RELEASE = 0,
	PRESS = 1
};

enum class EInputType : unsigned char
{
	ACTION,
	AXIS,
	VIRTUAL_AXIS
};

enum class EInputDevice
{
	ANY,
	KEYBOARD,
	GAMEPAD
};

template<EInputType>
struct SInputBind;

template<>
struct SInputBind<EInputType::ACTION>
{
	/* Key to listen */
	int Key = -1;

	/* Function to call when matching input is detected */
	ButtonFunction Function = nullptr;

	/* The key state that triggers the Action */
	EButtonAction ActionTrigger = EButtonAction::PRESS;

	/* Hashed input Name */
	size_t InputID;

	EButtonAction LastFrameState = EButtonAction::RELEASE;
};

template<>
struct SInputBind<EInputType::AXIS>
{
	/* Keys to listen */
	int PositiveKey = -1;
	int NegativeKey = -1;

	float Sensitivity = 1;

	/* Function to call when matching input is detected */
	AxisFunction Function = nullptr;

	/* Hashed input Name */
	size_t InputID;

};