#pragma once

#include <map>
#include <vector>
#include <array>

#include <functional>

#include "SController.h"

// 
// enum class EInputState : unsigned char
// {
// 	None = 0,
// 	Release = 1,
// 	Press = 2,
// 	Axis = 3
// };
// 
// enum EInputModifiers : unsigned char
// {
// 	ALT = 0,
// 	CTRL = 1,
// 	ALT_CTRL = 5
// };
// 
// struct SInput
// {
// 	unsigned char KeyCode;
// 
// 	EInputState InputState;
// 
// 	/* Hashed input Name */
// 	unsigned int hInputName;
// 
// 	bool operator==(SInput& other)
// 	{
// 		return other.hInputName == hInputName && other.InputState == InputState;
// 	}
// };
// 
// enum EInputType
// {
// 	ACTION = 0,
// 	AXIS = 1
// };
// 
// 
// 
// struct SLInputComponentType
// {
// 	class LInputComponent* Component;
// 	EInputState State;
// 
// 	SLInputComponentType() { }
// 
// 	SLInputComponentType(class LInputComponent* comp, EInputState state)
// 		: Component(comp), State(state) { }
// };
// 
// template<EInputType>
// struct SInputAtom;
// 
// template<EInputType>
// struct SInputMolecule;
// 
// /* ACTION */
// template<>
// struct SInputAtom<ACTION>
// {
// 	unsigned int hName;
// 	std::vector<std::string> Keys;
// };
// 
// template<>
// struct SInputMolecule<ACTION>
// {
// 	SInputAtom<ACTION> Action;
// 	std::vector<SLInputComponentType> Listeners;
// };
// 
// /* AXIS */
// template<>
// struct SInputAtom<AXIS>
// {
// 	unsigned int hName;
// 	std::vector<std::pair<std::string, float>> Keys;
// };
// 
// template<>
// struct SInputMolecule<AXIS>
// {
// 	SInputAtom<AXIS> Axis;
// 
// 	std::vector<class LInputComponent*> Listeners;
// };
// 
// 
// struct SInputRelation
// {
// 	SInput* Input;
// 
// 	std::vector<class LInputComponent*> Listeners;
// };
// 
// class GameInputManager
// {
// public:
// 
// 	static GameInputManager* Singleton_GameInputManager;
// 
// private:
// 	std::vector<SInput> m_PossibleInputs;
// 
// 	std::vector<SInputMolecule<ACTION>> m_PossibleActions;
// 	std::vector<SInputMolecule<AXIS>> m_PossibleAxis;
// 
// 	std::vector<SInputRelation> m_InputListeners;
// 
// 	std::vector<class LInputComponent*> m_Controllers;
// 
// 	static std::hash<std::string> m_Hasher;
// 
// 
// private:
// 	void ReadControlsFile();
// 
// 	inline void ReadAxisControl(const std::string& line);
// 	inline void ReadActionControl(const std::string& line);
// 
// public:
// 	GameInputManager();
// 	
// public:
// 	void Init();
// 
// 	/**
// 	*  Binds an input with a Function, that will be use as a callback when the input is detected.
// 	*/
// 	unsigned int BindAxis(class LInputComponent& newInput, const char* inputName);
// 
// 	unsigned int BindAction(class LInputComponent& inputComponent, const char* inputName, const EInputState state); // NOT SUPPORTED YET
// 
// 	void DetectAction(const std::string key, const EInputState state);
// 
// 	void DetectAxis(const char* axisName, float value);
// 
// 	/* Controllers Handling */
// 
// public:
// 	void AddNewController(class LInputComponent* inputComponent, EControllerTypes controllerType = None);
// 
// 	static void ReceiveActionInput(const char* name, const unsigned char state, const unsigned char controllerID);
// 	static void ReceiveAllActionInput(const char* name, const unsigned char state, const unsigned char controllerID);
// 	static void ReceiveAxisInput(const char* name, const float value, const unsigned char controllerID);
// 
// 	static void AddControllerInterface(const unsigned char iD, const EControllerTypes controllerType);
// 
// private:
//  	static std::array<SControllerInterface*, 4> m_AvailableControllers;
// 	static std::array<SControllerInterface, 10> m_ConnectedControllers;
// 
// public:
// 	static inline const std::array<SControllerInterface, 10>& GetConnectedControllers() { return m_ConnectedControllers; }
// };
// 
