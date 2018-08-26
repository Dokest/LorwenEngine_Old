#pragma once

#include "Component.h"
#include "InputParameters.h"

#include "Alphabet.h"

#include <vector>

namespace Lorwen {

	class InputComponent : public Component
	{
	private:
		std::vector<SInputListening> m_InputListeners;

		bool bHasFocus = false;


	public:
		InputComponent();
		~InputComponent();

	public:
		bool ReceiveInput(SInputData data);

		template<typename T>
		void BindInput(const char* actionName, unsigned int button, void(*function)(float), T*);
	};

}
