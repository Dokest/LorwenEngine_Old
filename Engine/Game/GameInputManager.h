#pragma once

#include <map>
#include <vector>

#include <functional>

namespace Lorwen {

	enum EInputState : unsigned char
	{
		Release = 0,
		Press = 1
	};

	enum EInputModifiers : unsigned char
	{
		ALT = 0,
		CTRL = 1,
		ALT_CTRL = 5
	};

	struct SInput
	{
		unsigned char KeyCode;

		EInputState InputState;

		/* Hashed input Name */
		unsigned int hInputName;

		bool operator==(SInput& other)
		{
			return other.hInputName == hInputName && other.InputState == InputState;
		}
	};

	enum EInputType
	{
		ACTION = 0,
		AXIS = 1
	};



	struct SInputComponentType
	{
		class InputComponent* Component;
		EInputState State;

		SInputComponentType() { }

		SInputComponentType(class InputComponent* comp, EInputState state)
			: Component(comp), State(state) { }
	};

	template<EInputType>
	struct SInputAtom;

	template<EInputType>
	struct SInputMolecule;

	/* ACTION */
	template<>
	struct SInputAtom<ACTION>
	{
		unsigned int hName;
		std::vector<std::string> Keys;
	};

	template<>
	struct SInputMolecule<ACTION>
	{
		SInputAtom<ACTION> Action;
		std::vector<SInputComponentType> Listeners;
	};

	/* AXIS */
	template<>
	struct SInputAtom<AXIS>
	{
		unsigned int hName;
		std::vector<std::pair<std::string, float>> Keys;
	};

	template<>
	struct SInputMolecule<AXIS>
	{
		SInputAtom<AXIS> Axis;

		std::vector<class InputComponent*> Listeners;
	};


	struct SInputRelation
	{
		SInput* Input;

		std::vector<class InputComponent*> Listeners;
	};

	class GameInputManager
	{
	public:

		static GameInputManager* Singleton_GameInputManager;

	private:
		std::vector<SInput> m_PossibleInputs;

		std::vector<SInputMolecule<ACTION>> m_PossibleActions;
		std::vector<SInputMolecule<AXIS>> m_PossibleAxis;

		std::vector<SInputRelation> m_InputListeners;

		std::vector<class InputComponent*> m_Controllers;

		std::hash<std::string> m_Hasher;


	private:
		void ReadControlsFile();

		inline void ReadAxisControl(const std::string& line);
		inline void ReadActionControl(const std::string& line);

	public:
		GameInputManager();
		
	public:
		void Init();

		/**
		*  Binds an input with a Function, that will be use as a callback when the input is detected.
		*/
		unsigned int BindAxis(class InputComponent& newInput, const char* inputName);

		unsigned int BindAction(class InputComponent& inputComponent, const char* inputName, const EInputState state); // NOT SUPPORTED YET

		void DetectAction(const std::string key, const EInputState state);

		void DetectAxis(const char* axisName, float value);

	};
}
