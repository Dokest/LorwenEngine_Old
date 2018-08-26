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

	struct SInputListening
	{
		unsigned int Key;
		std::function<void(float)> Function;

		SInputListening()
			{}

		SInputListening(unsigned int key, std::function<void(float)> function)
			: Key(key), Function(function)
		{

		}
	};
}