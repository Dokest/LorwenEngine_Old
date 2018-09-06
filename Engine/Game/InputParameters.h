#pragma once

#include <functional>

namespace Lorwen {
	enum class EInputCategory : unsigned char
	{
		Release = 0,
		Press = 1,
		Hold = 2
	};

	struct SInputData
	{
		EInputCategory InputCategory;
		float Value; // Has to be normalize { 0 - 1 }
		unsigned short Key;

	};

	enum class EInputManagersCategories
	{
		Keyboard_Mouse = 0,
		Keyboard = 1,
		Gamepad = 2

	};

	template<class T>
	struct SInputListening
	{
		unsigned int Key;
		std::string InputName;

	private:
		T* Instance;

		void(T::*Function)(float);

	public:
		void CallFunction(class GameObject* instance, float Value)
		{
			T* objectInstance = static_cast<T*>(instance);
			(objectInstance->*Function)(Value);
		}
		


		SInputListening(const std::string inputName, T* instanceListening, void(T::*function)(float) )
			: InputName(inputName), Instance(instanceListening), Function(function)
		{

		}

	};
}