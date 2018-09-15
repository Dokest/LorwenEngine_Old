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

	float value = 0.0f;

	for (unsigned int i = 0; i < m_Bindings.size(); i++)
	{
		SBindings& binding = m_Bindings[i];

		if (binding.BindingKey == -1)
			continue; // Might want to change this to return later on!

		switch (binding.State)
		{
		case EInputState::VirtualAxis:
			value = buttons[binding.BindingKey];

			for (unsigned int a = i + 1; a < m_Bindings.size(); a++)
			{
				if (binding.hBindingName == m_Bindings[a].hBindingName)
				{
					value += buttons[binding.BindingKey];
					*buttons[m_Bindings[a].BindingKey] = 0.0f;
					break;
				}
			}

			pInputComponent->CallAxisInput(binding.hBindingName, value * binding.Value);
			
			break;
		case EInputState::Axis:
			pInputComponent->CallAxisInput(binding.hBindingName, axes[binding.BindingKey] * binding.Value);
			break;
		default:
			break;
		}

// 		if (binding.State == EInputState::Axis)
// 		{
// 			float value = glfwGetJoystickAxes(ID, &count)[binding.BindingKey];
// 
// 			printf("Value = %f\n", value);
// 
// 			//pInputComponent->CallAxisInput(binding.hBindingName, glfwGetJoystickAxes(ID, &count)[binding.BindingKey] * binding.Value);
// 		}
// // 		else if (binding.State != (EInputState)glfwGetKey(glfwWindow, binding.BindingKey))
// // 		{
// // 			binding.State = (EInputState)glfwGetKey(glfwWindow, binding.BindingKey);
// // 			pInputComponent->CallActionInput(binding.hBindingName, binding.State);
// // 		}

	}
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

void LController::BindAxis(unsigned int hBindingName, int key, float value, const EInputState inputType)
{
	for (SBindings& bind : m_Bindings)
	{
		if (bind.hBindingName == hBindingName && inputType == EInputState::Axis)
			ClearAxis(hBindingName, EInputState::Axis);

		if (bind.BindingKey == -1)
		{
			bind.hBindingName = hBindingName;
			bind.BindingKey = key;
			bind.State = inputType;
			bind.Value = value;
			return;
		}
		
	}
}

std::array<std::string, 15> SGamepadMapping::Buttons;

std::array<std::string, 6> SGamepadMapping::Axes;

SGamepadMapping* SGamepadMapping::Singleton_SGamepadMapping;
