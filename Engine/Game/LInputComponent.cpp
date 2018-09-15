#include "LInputComponent.h"

#include "LGameInputManager.h"

#include "Utils/FileReader.h"

#include <iostream>

void LInputComponent::OnCreation()
{
	m_ControllerID = LGameInputManager::AddInputComponent(this);

	std::cout << "Input Component was binded with Controller " << m_ControllerID << std::endl;
}
