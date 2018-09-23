#include "LController.h"

#include "Graphics/Window.h"

#include "LInputComponent.h"

#include <string>

#include <GLFW/glfw3.h>

void LController::Init(const EControllerDevice device)
{
	Device = device;

	printf("New controller was connected & binded correctly at index %d\n", ID);
}

void LController::DetectsInputs()
{
	switch (Device)
	{
	case EControllerDevice::Keyboard: 
		DetectKeyboardInputs();
		break;

	case EControllerDevice::Gamepad:
		DetectGamepadInputs();
		break;
	}
}

void LController::DetectKeyboardInputs()
{
	GLFWwindow* glfwWindow = Window::GetWindowPointer()->GetGLFWwindowPointer();

	for (SBindings& binding : m_Bindings)
	{
		if (binding.BindingKey == -1)
			continue; // Might want to change this to return later on!

		if (binding.State == EInputState::Axis)
		{
			pInputComponent->CallAxisInput(binding.hBindingName, glfwGetKey(glfwWindow, binding.BindingKey) * binding.Value);
		}
		else if (binding.State != (EInputState)glfwGetKey(glfwWindow, binding.BindingKey))
		{
			binding.State = (EInputState)glfwGetKey(glfwWindow, binding.BindingKey);
			pInputComponent->CallActionInput(binding.hBindingName, binding.State);
		}

	}
}

void LController::DetectGamepadInputs()
{
	int buttonCount;
	int axisCount;

	const float* axes = glfwGetJoystickAxes(ID, &axisCount);
	const unsigned char* buttons = glfwGetJoystickButtons(ID, &buttonCount);

	/* Check Virtual Axis Bindings */
	for (SVirtualAxisBinding& vA : m_VirtualAxisBindings)
	{
		if (buttons[vA.BindingKey1] > 0 && buttons[vA.BindingKey2] == 0)
			pInputComponent->CallAxisInput(vA.hBindingName, buttons[vA.BindingKey1]);		
		else if (buttons[vA.BindingKey1] == 0 && buttons[vA.BindingKey2] > 0)				
			pInputComponent->CallAxisInput(vA.hBindingName, buttons[vA.BindingKey2]);
		else
			pInputComponent->CallAxisInput(vA.hBindingName, 0);
	}

	/* Check for Axis Bindings */
	for (SAxisBinding& axis : m_AxisBindings)
		pInputComponent->CallAxisInput(axis.hBindingName, axes[axis.BindingKey] * axis.Sensitivity);


	/* Check for Button Bindings*/
	for (SButtonBinding& button : m_ButtonBindings)
		if ((EInputState)buttons[button.BindingKey] == button.State && (EInputState)buttons[button.BindingKey] != button.LastFrameState)
			pInputComponent->CallActionInput(button.hBindingName, button.State);

}

void LController::ClearAxis(const unsigned int hBindingName , const EInputState inputType)
{
	for (SBindings& bind : m_Bindings)
	{
		if (bind.hBindingName == hBindingName)
		{
			if (bind.State == EInputState::VirtualAxis)
			{
				bind.BindingKey = -1;
				bind.hBindingName = 0;
				
				continue;
			}
			else
			{
				bind.BindingKey = -1;
				bind.hBindingName = 0;
				
				return;
			}
		}
	}
}

void LController::BindAxis(unsigned int hBindingName, int key, float value)
{

	for (SAxisBinding& axis : m_AxisBindings)
	{
		if (axis.BindingKey == -1)
		{
			axis.BindingKey = key;
			axis.hBindingName = hBindingName;
			axis.Sensitivity = value;
		}
	}

// 	for (SBindings& bind : m_Bindings)
// 	{
// 		if (bind.hBindingName == hBindingName && inputType == EInputState::Axis)
// 			ClearAxis(hBindingName, EInputState::Axis);
// 
// 		if (bind.BindingKey == -1)
// 		{
// 			bind.hBindingName = hBindingName;
// 			bind.BindingKey = key;
// 			bind.State = inputType;
// 			bind.Value = value;
// 			return;
// 		}
// 		
// 	}
}

void LController::BindVirtualAxis(const unsigned int hBindingName, const int key1, const int key2, const float value)
{
	SVirtualAxisBinding* vAToChange = nullptr;

	for (SVirtualAxisBinding& vA : m_VirtualAxisBindings)
	{
		if (vA.hBindingName == hBindingName)
		{
			if (key1 != -1)
				vA.BindingKey1 = key1;

			if (key2 != -1)
				vA.BindingKey2 = key2;

			if(value != 0)
				vA.Sensitivity = value;

			return;
		}

		if (vAToChange == nullptr && vA.hBindingName == 0)
			vAToChange = &vA;
	}

	if (key1 != -1)
		vAToChange->BindingKey1 = key1;

	if (key2 != -1)
		vAToChange->BindingKey2 = key2;

	vAToChange->hBindingName = hBindingName;
	vAToChange->Sensitivity = value;
}

std::array<std::string, 15> SGamepadMapping::Buttons;

std::array<std::string, 6> SGamepadMapping::Axes;

SGamepadMapping* SGamepadMapping::Singleton_SGamepadMapping;
